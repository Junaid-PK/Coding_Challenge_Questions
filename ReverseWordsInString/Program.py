def reverseWordsInString(string):
    # Write your code here.
    reverse = ""

    i = len(string)-1
    currentWord = ""
    while(i>=0):
        char = string[i]
        if char == " ":
            reverse += currentWord + " "
            currentWord = ""
        else:
            currentWord = char + currentWord
        i-=1
    return reverse + currentWord

print(reverseWordsInString("AlgoExpert is the best!"))