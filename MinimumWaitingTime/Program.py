def minimumWaitingTime(queries):
    # Write your code here.
    queries.sort()
    minWaitingTime = 0
    previousTime = 0
    for i in range(len(queries)):
        minWaitingTime += previousTime
        previousTime+= queries[i]
    return minWaitingTime

print(minimumWaitingTime([3,2,1,2,6]))