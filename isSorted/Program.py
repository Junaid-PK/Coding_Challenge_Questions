def isSorted(arr, s):
    if s == len(arr) - 1:
        return True
    return (arr[s] < arr[s+1]) & (isSorted(arr,s+1))

def main():
    print(isSorted([1,2,3,4], s=0))

main()