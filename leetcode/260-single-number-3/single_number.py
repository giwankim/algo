import collections
from typing import List


def singleNumber(nums: List[int]) -> List[int]:
    counter = collections.Counter(nums)
    return [num for num, cnt in counter.items() if cnt == 1]


if __name__ == "__main__":
    nums = [1, 2, 1, 3, 2, 5]
    result = singleNumber(nums)
    correct_result = [3, 5]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
