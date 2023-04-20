def quickSort(array):
    sortHelper(array,0, len(array)-1)
    return array

def sortHelper(array, low, high):
    if low>=high:
        return
    
    s = low
    e = high
    m = low + (high - low)//2
    pivot = array[m]
    while(s<=e):
        while array[s]<pivot:
            s+=1
        while array[e]>pivot:
            e-=1
        if s<=e:
            array[s],array[e] = array[e],array[s]
            s+=1
            e-=1
    sortHelper(array, low, e)
    sortHelper(array, s, high)

print(quickSort([32,1,4,2]))