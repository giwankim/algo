import ipaddress

def validIPAddress(IP: str) -> str:
    try:
        addr = ipaddress.ip_address(IP)
        if type(addr) is ipaddress.IPv4Address:
            toks = IP.split('.')
            for tok in toks:
                if tok.startswith('0'):
                    if int(tok) != 0 or len(tok) > 1:
                        return 'Neither'
            return 'IPv4'
        else:
            toks = IP.split(':')
            if any(not tok for tok in toks):
                return 'Neither'
            return 'IPv6'
    except ValueError:
        return 'Neither'

def main():
    print("=====Example 1=====")
    IP = '172.16.254.1'
    result = validIPAddress(IP)
    correct_result = 'IPv4'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

    print("=====Example 2=====")
    IP = '2001:0db8:85a3:0:0:8A2E:0370:7334'
    result = validIPAddress(IP)
    correct_result = 'IPv6'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

    print("=====Example 3=====")
    IP = '256.256.256.256'
    result = validIPAddress(IP)
    correct_result = 'Neither'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

    print("=====Example 4=====")
    IP = '01.01.01.01'
    result = validIPAddress(IP)
    correct_result = 'Neither'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

    print("=====Example 5=====")
    IP = '2001:0db8:85a3::8A2E:0370:7334'
    result = validIPAddress(IP)
    correct_result = 'Neither'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

    print("=====Example 6=====")
    IP = '00.0.0.0'
    result = validIPAddress(IP)
    correct_result = 'Neither'
    print("Expected:")
    print(f"\t{correct_result}")
    print("Output:")
    print(f"\t{result}")
    assert(result == correct_result)

if __name__ == '__main__':
    main()
