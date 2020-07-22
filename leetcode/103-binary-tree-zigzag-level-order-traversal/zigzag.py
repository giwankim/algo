import collections
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def bfs(root: TreeNode) -> List[List[int]]:
    if root is None:
        return []
    ret = []
    q = collections.deque()
    q.append(root)
    even = True
    while q:
        level = []
        n = len(q)
        for _ in range(n):
            node = q.popleft()
            print(node.val)
            level.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if even:
            even = False
        else:
            level = level[::-1]
            even = True
        ret.append(level)
    return ret


def zigzagLevelOrder(root: TreeNode) -> List[List[int]]:
    def dfs(i, root):
        if root is None:
            return
        if i == len(ret):
            ret.append(collections.deque())

        if i % 2 == 0:
            ret[i].append(root.val)
        else:
            ret[i].appendleft(root.val)

        dfs(i + 1, root.left)
        dfs(i + 1, root.right)

    ret = []
    dfs(0, root)
    return ret


if __name__ == "__main__":
    print("=====Example 1=====")
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    result = zigzagLevelOrder(root)
    correct_result = [[3], [20, 9], [15, 7]]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
