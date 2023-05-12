class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        l,r = 0,len(numbers)-1
        while l<r:
            currentSum = numbers[l] + numbers[r]
            if currentSum > target:
                r-=1
            elif currentSum  < target:
                l+=1
            else:
                return [l+1,r+1]
        return []

mySolution = Solution()
print(mySolution.twoSum([2,7,11,15],9))