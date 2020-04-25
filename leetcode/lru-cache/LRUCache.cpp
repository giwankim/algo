#include <iostream>
#include <unordered_map>
#include <list>
#include <cassert>
using namespace std;

class LRUCache
{
private:
    typedef unordered_map<int, pair<int, list<int>::iterator>> Table;

    int capacity;
    list<int> keys;
    Table cache;

    void touch(Table::iterator it)
    {
        keys.erase(it->second.second);
        keys.push_front(it->first);
        it->second.second = keys.begin();
    }

public:
    LRUCache(int _capacity) : capacity(_capacity) {}

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end())
            return -1;
        touch(it);
        return it->second.first;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it == cache.end()) {
            keys.push_front(key);
            cache[key] = make_pair(value, keys.begin());
            if (keys.size() > capacity) {
                cache.erase(keys.back());
                keys.pop_back();
            }
        } else {
            touch(it);
            it->second.first = value;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    LRUCache cache = LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 1);
    assert(cache.get(1) == 1);
    cache.put(3, 3);
    assert(cache.get(2) == -1);
    cache.put(4, 4);
    assert(cache.get(1) == -1);
    assert(cache.get(3) == 3);
    assert(cache.get(4) == 4);
    return 0;
}
