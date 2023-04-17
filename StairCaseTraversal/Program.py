def staircaseTraversal(height, maxSteps):
    ans = 0
    if (height == 0):
            return 1
    if (height<0):
          return 0
    for i in range(1,maxSteps+1):
        ans += staircaseTraversal(height-i,maxSteps)
    return ans
print(staircaseTraversal(4,2))