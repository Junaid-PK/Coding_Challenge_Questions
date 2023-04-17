def phoneNumberMnemonics(phoneNumber):
    keypad = {"0":"0",
          "1":"1",
          "2":"abc",
            "3":"def",
            "4":"ghi",
            "5":"jkl",
            "6":"mno",
            "7":"pqrs",
            "8":"tuv",
            "9":"wxyz"}
    result = []
    tempResult = ""
    helper(phoneNumber, tempResult, keypad, result, 0)
    return result

def helper(phoneNumber,tempResult, keypad, result, index):
    if (index>=len(phoneNumber)):
        result.append(tempResult)
        return
    
    key = phoneNumber[index]
    value = keypad[key]
    
    for i in range(len(value)):
        tempResult+=value[i]
        helper(phoneNumber,tempResult, keypad, result, index+1)
        tempResult = tempResult[:-1]

    

def main():    
    degit = "1905"
    print(phoneNumberMnemonics(degit))

main()