class Solution:
    """
    @param: strs: a list of strings
    @return: encodes a list of strings to a single string.
    """
    def encode(self, strs):
        # write your code here
        res = ""
        for s in strs:
            res+=str(len(s))+ "#"+ s
        return res
        

    """
    @param: str: A string
    @return: dcodes a single string to a list of strings
    """
    def decode(self, str):
        # write your code here
        res = []
        i = 0
        while i<len(str):
            j = i
            while str[j] !="#":
                j+=1
            length = int(str[i:j])
            res.append(str[j+1:j+1+length])
            i = j+1+length
        return res
    
# main
if __name__ == "__main__":
    strs = ["lint","code","love","you"]
    s = Solution()
    print(s.encode(strs))
    print(s.decode(s.encode(strs)))

# Output
# 4#lint4#code4#love3#you
# ['lint', 'code', 'love', 'you']
