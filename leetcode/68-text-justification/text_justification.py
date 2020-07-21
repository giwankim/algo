from typing import List


def fullJustify(words: List[str], maxWidth: int) -> List[str]:
    ret = []
    cur, cur_len = [], 0
    for word in words:
        if cur_len + len(word) + len(cur) > maxWidth:
            # Distribute (maxWidth - cur_len) spaces evenly
            # from left to right round-robin
            for i in range(maxWidth - cur_len):
                cur[i % (len(cur) - 1 or 1)] += " "
            ret.append("".join(cur))
            cur, cur_len = [], 0

        cur.append(word)
        cur_len += len(word)

    ret.append(" ".join(cur).ljust(maxWidth))
    return ret


if __name__ == "__main__":
    print("=====Example 1=====")
    words = ["This", "is", "an", "example", "of", "text", "justification."]
    maxWidth = 16
    result = fullJustify(words, maxWidth)
    correct_result = ["This    is    an", "example  of text", "justification.  "]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)

    print("=====Example 2=====")
    words = ["What", "must", "be", "acknowledgment", "shall", "be"]
    maxWidth = 16
    result = fullJustify(words, maxWidth)
    correct_result = ["What   must   be", "acknowledgment  ", "shall be        "]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)

    print("=====Example 3=====")
    words = [
        "Science",
        "is",
        "what",
        "we",
        "understand",
        "well",
        "enough",
        "to",
        "explain",
        "to",
        "a",
        "computer.",
        "Art",
        "is",
        "everything",
        "else",
        "we",
        "do",
    ]
    maxWidth = 20
    result = fullJustify(words, maxWidth)
    correct_result = [
        "Science  is  what we",
        "understand      well",
        "enough to explain to",
        "a  computer.  Art is",
        "everything  else  we",
        "do                  ",
    ]
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
