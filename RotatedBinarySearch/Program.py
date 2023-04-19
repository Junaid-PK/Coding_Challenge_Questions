def search(arr, target, s , e):
    if(s>e):
        return -1
    mid = int(s+(e-s)/2)
    if(arr[mid] == target):
        return mid
    if(arr[s]<=arr[mid]):
        if(target>=arr[s] & target<=arr[mid]):
            return search(arr, target, s, mid-1)
        else:
            return search(arr, target, mid + 1, e)
    if target>=arr[mid] & target<=arr[mid]:
        return search(arr, target, mid + 1, e)
    return search(arr, target, s, mid-1)

def main():
    arr = [5,6,7,8,9,1,2,3]
    print(search(arr,9,0,len(arr)))

main()
    