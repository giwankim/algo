from typing import List


def allPathsSourceTarget(graph: List[List[int]]) -> List[List[int]]:
    ret = []
    path = []
    def dfs(i):
        if i == len(graph) - 1:
            ret.append(path[:])
            return
        for to in graph[i]:
            path.append(to)
            dfs(to)
            path.pop()
    
    path.append(0)
    dfs(0)
    return ret


if __name__ == "__main__":
    graph = [[1, 2], [3], [3], []]
    result = allPathsSourceTarget(graph)
    correct_result = [[0, 1, 3], [0, 2, 3]]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
