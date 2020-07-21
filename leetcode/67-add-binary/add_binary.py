# add_binary.py


def addBinary(a: str, b: str) -> str:
    a = list(a)
    b = list(b)
    c = ""
    carry = 0
    while a or b or carry:
        if a:
            carry += int(a.pop())
        if b:
            carry += int(b.pop())
        c += str(carry % 2)
        carry //= 2

    return c[::-1]

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
