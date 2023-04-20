def mergeSort(array):
    if len(array)<=1:
        return array

    mid = len(array) // 2
    left = mergeSort(array[:mid])
    right = mergeSort(array[mid:])

    ans = []
    i = 0 
    j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            ans.append(left[i])
            i+=1
        else:
            ans.append(right[j])
            j+=1
    if i == len(left):
        i = j
        left = right

    while i<len(left):
        ans.append(left[i])
        i+=1
    return ans

def main():
    print(mergeSort([1,2,5,3,1,2,3]))

if __name__ == "__main__":
    main()