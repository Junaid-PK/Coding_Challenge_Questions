def topKFrequent( nums, k):
        count = {}
        freq = [[] for i in range(len(nums)+1)]
        for n in nums:
            count[n] = 1+count.get(n,0)
        for key,value in count.items():
            freq[value].append(key)
        res = []
        for n in range(len(freq)-1,0,-1):
            for i in freq[n]:
                res.append(i)
                if len(res)==k:
                    return res

# main
print(topKFrequent([1,1,1,2,2,3],2))