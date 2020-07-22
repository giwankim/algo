# word_search.py
from typing import List


def exist(board: List[List[str]], word: str) -> bool:
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    rows = len(board)
    cols = len(board[0])

    def backtrack(i, y, x):
        if i == len(word):
            return True
        if y < 0 or y >= rows or x < 0 or x >= cols:
            return False
        if board[y][x] != word[i]:
            return False

        board[y][x] = "#"
        ret = False
        for k in range(len(dx)):
            ny = y + dy[k]
            nx = x + dx[k]
            if backtrack(i + 1, ny, nx):
                ret = True
                break
        board[y][x] = word[i]

        return ret

    for y in range(rows):
        for x in range(cols):
            if backtrack(0, y, x):
                return True

    return False


if __name__ == "__main__":
    board = [
        ["A", "B", "C", "E"],
        ["S", "F", "C", "S"],
        ["A", "D", "E", "E"],
    ]

    print("=====Example 1=====")
    word = "ABCCED"
    result = exist(board, word)
    correct_result = True
    print(f"Expected:\n\t{correct_result}")
    print(f"Output:\n\t{result}")

    print("=====Example 2=====")
    word = "SEE"
    result = exist(board, word)
    correct_result = True
    print(f"Expected:\n\t{correct_result}")
    print(f"Output:\n\t{result}")

    print("=====Example 3=====")
    word = "ABCB"
    result = exist(board, word)
    correct_result = False
    print(f"Expected:\n\t{correct_result}")
    print(f"Output:\n\t{result}")

    board = [["a"]]

    print("=====Example 4=====")
    word = "a"
    result = exist(board, word)
    correct_result = True
    print(f"Expected:\n\t{correct_result}")
    print(f"Output:\n\t{result}")
