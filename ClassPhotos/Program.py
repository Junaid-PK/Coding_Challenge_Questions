def classPhotos(redShirtHeights, blueShirtHeights):
    # Write your code here.
    redShirtHeights.sort()
    blueShirtHeights.sort()
    
    if redShirtHeights[-1] > blueShirtHeights[-1]:
        biggerArray = redShirtHeights
        smallerArray = blueShirtHeights
    else:
        smallerArray = redShirtHeights
        biggerArray = blueShirtHeights

    for i in range(len(biggerArray)):
        if (biggerArray[i] - smallerArray[i]) <= 0:
            return False
    return True

redShirtHeights = [5, 8, 1, 3, 4]
blueShirtHeights = [6, 9, 2, 4, 5]
print(classPhotos(redShirtHeights,blueShirtHeights))