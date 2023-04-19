def DigitSum(n):
    if n == 0:
        return 0
    return (n%10)+DigitSum(int(n/10))
print(DigitSum(12345))