#include "bits/stdc++.h"
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> table;
    random_device rd;
    default_random_engine rng;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        rng = default_random_engine(rd());
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (table.find(val) != table.end())
            return false;
        nums.push_back(val);
        table[val] = (int)nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (table.find(val) == table.end())
            return false;
        int idx = table[val];
        int back_val = nums.back();
        
        nums[idx] = back_val;
        table[back_val] = idx;

        nums.pop_back();
        table.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> dist(0, (int)nums.size() - 1);
        auto it = nums.begin();
        advance(it, dist(rng));
        return *it;
    }
};

int main(int argc, char const *argv[]) {
    {
        cout << "=====Example 1=====\n";
        RandomizedSet rand_set;

        // Inserts 1 to the set. Returns true as 1 was inserted successfully.
        bool result1 = rand_set.insert(1);
        bool correct_result1 = true;
        cout << boolalpha;
        cout << "Expected:\n\t";
        cout << correct_result1 << "\n";
        cout << "Output:\n\t";
        cout << result1 << "\n\n";
        assert(result1 == correct_result1);

        // Returns false as 2 does not exist in the set.
        bool result2 = rand_set.remove(2);
        bool correct_result2 = false;
        cout << "Expected:\n\t";
        cout << correct_result2 << "\n";
        cout << "Output:\n\t";
        cout << result2 << "\n\n";
        assert(result2 == correct_result2);

        // Inserts 2 to the set, returns true. Set now contains [1,2].
        bool result3 = rand_set.insert(2);
        bool correct_result3 = true;
        cout << "Expected:\n\t";
        cout << correct_result3 << "\n";
        cout << "Output:\n\t";
        cout << result3 << "\n\n";
        assert(result3 == correct_result3);

        cout << "Should return either 1 or 2 randomly:\n\t";
        int result4 = rand_set.getRandom();
        cout << result4 << "\n\n";

        // Removes 1 from the set, returns true. Set now contains [2].
        bool result5 = rand_set.remove(1);
        bool correct_result5 = true;
        cout << "Expected:\n\t";
        cout << correct_result5 << "\n";
        cout << "Output:\n\t";
        cout << result5 << "\n\n";
        assert(result5 == correct_result5);

        // 2 was already in the set, so return false.
        bool result6 = rand_set.insert(2);
        bool correct_result6 = false;
        cout << "Expected:\n\t";
        cout << correct_result6 << "\n";
        cout << "Output:\n\t";
        cout << result6<< "\n\n";
        assert(result6 == correct_result6);

        // Since 2 is the only number in the set, getRandom always return 2.
        int result7 = rand_set.getRandom();
        int correct_result7 = 2;
        cout << "Should always return 2:\n\t";
        cout << result7 << "\n\n";
        assert(result7 == correct_result7);
    }
    return 0;
}
