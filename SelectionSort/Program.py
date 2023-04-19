def selectionSort(array):
    # Write your code here.
    sortHelper(array, 0, len(array))
    return array

def sortHelper(array, beginIndex, size):
    if beginIndex == size:
        return
    smallestIndex = beginIndex
    for i in range(beginIndex, size):
        if array[i] < array[smallestIndex]:
            smallestIndex = i

    array[beginIndex], array[smallestIndex] = array[smallestIndex], array[beginIndex]
    sortHelper(array, beginIndex + 1, size)


def main():
    print(selectionSort([145,52,34212,53,554,0]))

main()