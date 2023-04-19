def bubbleHelper(arr, end):
    if (end==0):
        return
    for i in range(end):
        if arr[i]>arr[i+1]:
            arr[i],arr[i+1] = arr[i+1],arr[i]
    bubbleHelper(arr,end-1)
def bubbleSort(array):
    # Write your code here.
    bubbleHelper(array,len(array)-1)
    return array


def main():
    print(bubbleSort([4,3,2,1]))

main()