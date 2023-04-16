


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
    result = [""]
    for element in phoneNumber:
        value = keypad[element]
        newresult = []
        for char in value:
            for val in result:
                newresult.append(char+val)
        result = newresult
    return result

print(phoneNumberMnemonics("1905"))
