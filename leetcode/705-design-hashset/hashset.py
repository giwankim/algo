import bisect


class MyHashSet:
    def __init__(self):
        self.arr = []

    def add(self, key):
        if self.contains(key):
            return
        bisect.insort(self.arr, key)

    def remove(self, key):
        if not self.contains(key):
            return
        i = bisect.bisect_left(self.arr, key)
        self.arr.pop(i)

    def contains(self, key):
        i = bisect.bisect_left(self.arr, key)
        if i != len(self.arr) and self.arr[i] == key:
            return True
        return False


if __name__ == "__main__":
    hashset = MyHashSet()
    hashset.add(1)
    hashset.add(2)
    # print(hashset.arr)
    assert hashset.contains(1) == True
    assert hashset.contains(3) == False
    hashset.add(2)
    assert hashset.contains(2) == True
    hashset.remove(2)
    assert hashset.contains(2) == False
