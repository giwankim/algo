# add_binary.py


def addBinary(a: str, b: str) -> str:
    a = list(reversed(a))
    b = list(reversed(b))
    c_len = max(len(a), len(b)) + 1
    c = ["0"] * c_len

    digit = 0
    for i in range(c_len):
        if i < len(a):
            digit += int(a[i])
        if i < len(b):
            digit += int(b[i])
        c[i] = str(digit % 2)
        digit //= 2

    while len(c) > 1 and c[-1] == "0":
        c.pop()
    return "".join(reversed(c))


if __name__ == "__main__":
    print("=====Example 1=====")
    a = "11"
    b = "1"
    expected = "100"
    result = addBinary(a, b)
    print(f"Expected:\n\t{expected}")
    print(f"Result:\n\t{result}")

    print("=====Example 2=====")
    a = "1010"
    b = "1011"
    expected = "10101"
    result = addBinary(a, b)
    print(f"Expected:\n\t{expected}")
    print(f"Result:\n\t{result}")

    print("=====Example 3=====")
    a = "0"
    b = "0"
    expected = "0"
    result = addBinary(a, b)
    print(f"Expected:\n\t{expected}")
    print(f"Result:\n\t{result}")
