def productExceptSelf(nums):
    output = [1] * len(nums)
    prefix = 1
    for n in range(len(nums)):
        output[n] = prefix
        prefix = prefix*nums[n]
    postfix = 1
    for n in range(len(nums)-1,-1,-1):
        output[n] *= postfix
        postfix*=nums[n]
    return output
print(productExceptSelf([1,2,3,4]))