def reverseWords(s: str) -> str:
    return " ".join(list(reversed(s.split())))


if __name__ == "__main__":
    print("=====Example 1=====")
    s = "the sky is blue"
    correct_result = "blue is sky the"
    result = reverseWords(s)
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
    # assert result == correct_result

    print("=====Example 2=====")
    s = "  hello world!  "
    correct_result = "world! hello"
    result = reverseWords(s)
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
    # assert result == correct_result

    print("=====Example 3=====")
    s = "a good   example"
    correct_result = "example good a"
    result = reverseWords(s)
    print("Expected:")
    print(correct_result)
    print("Output:")
    print(result)
    # assert result == correct_result
