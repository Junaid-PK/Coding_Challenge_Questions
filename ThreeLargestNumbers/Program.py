def findThreeLargestNumbers(array):
    # Write your code here.
    threeLargest = [None, None, None]
    for num in array:
        if threeLargest[2] is None or num > threeLargest[2]:
            update(threeLargest, num, 2)
        elif threeLargest[1] is None or num > threeLargest[1]:
            update(threeLargest, num, 1)
        elif threeLargest[0] is None or num > threeLargest[0]:
            update(threeLargest, num, 0)

    return threeLargest
            
            

def update(array, num, idx):
    for i in range(idx+1):
        if i == idx:
            array[i] = num
        else:
            array[i] = array[i+1]


print(findThreeLargestNumbers([141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7]))