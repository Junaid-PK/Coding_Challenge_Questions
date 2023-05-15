class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if not height: return 0

        l,r = 0 , len(height)-1
        leftMax,rightMax = height[l],height[r]
        res = 0
        while l < r:
            if leftMax < rightMax:
                l+=1
                leftMax = max(leftMax, height[l])
                res += leftMax - height[l]
            else:
                r-=1
                rightMax = max(rightMax,height[r])
                res+= rightMax - height[r]
        return res

mySolution = Solution()
print(mySolution.trap([0,1,0,2,1,0,1,3,2,1,2,1]))