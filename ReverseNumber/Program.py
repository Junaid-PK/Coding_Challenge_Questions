def reverseNum(n, res):
    if(n % 10 == n):
        res = res *10 +n
        return int(res)
    res = res *10 + (n%10)
    return reverseNum(int(n/10), res)

def main():
    print(reverseNum(1234, 0))

main()