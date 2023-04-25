def commonCharacters(strings):
    # Write your code here.
    smallestString = getSmallestString(strings)
    potentialCommonCharacters = set(smallestString)

    for string in strings:
        removeNonExisting(string,potentialCommonCharacters)

    return list(potentialCommonCharacters)


def getSmallestString(strings):
    smallestString = strings[0]
    for string in strings:
        if len(string) < len(smallestString):
            smallestString = string

    return smallestString

def removeNonExisting(string, potentialCommonCharacters):
    uniqueStringCharacters = set(string)

    for character in list(potentialCommonCharacters):
        if character not in uniqueStringCharacters:
            potentialCommonCharacters.remove(character)
            


print(commonCharacters(["abc", "vbcsa"]))