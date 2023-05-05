def tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest):
    # Write your code here.
    redShirtSpeeds.sort()
    blueShirtSpeeds.sort(reverse = fastest)
    return sum(max(red,blue) for red,blue in zip(redShirtSpeeds, blueShirtSpeeds))

# main
redShirtSpeeds = [5, 5, 3, 9, 2]
blueShirtSpeeds = [3, 6, 7, 2, 1]
fastest = True
print(tandemBicycle(redShirtSpeeds, blueShirtSpeeds, fastest))