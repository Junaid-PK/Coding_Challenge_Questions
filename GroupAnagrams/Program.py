from collections import defaultdict
def groupAnagrams(words):
    # Write your code here.
    result = defaultdict(list)
    for string in words:
        count = [0] * 26
        for char in string:
            count[ord(char)-ord("a")]+=1
        result[tuple(count)].append(string)
    return list(result.values())

# main
words = ["yo", "act", "flop", "tac", "foo", "cat", "oy", "olfp"]
print(groupAnagrams(words))