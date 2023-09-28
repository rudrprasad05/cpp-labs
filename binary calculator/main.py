from email.policy import default
import math
from operator import mod
from xml.dom.minidom import Element



def textToBinary(strIn, tempMod, modifier):
    
    tempNum = strIn // modifier
    tempMod.append(strIn % modifier)
    

    while tempNum != 0:
        tempMod.append(tempNum % modifier) 
        tempNum = tempNum // modifier

    if modifier == 2:
        return tempMod

    elif modifier == 16:
        for index, element in enumerate(tempMod):
            match element:
                case 10:
                    tempMod[index] = 'a'
                case 11:
                    tempMod[index] = 'b'
                case 12:
                    tempMod[index] = 'c'
                case 13:
                    tempMod[index] = 'd'
                case 14:
                    tempMod[index] = 'e'
                case 15:
                    tempMod[index] = 'f'
        
        return tempMod
    

def binaryToDecimal(binIn):
    sum = 0
    arr = []
    for i in binIn:
        arr.append(int(i))
    
    arr.reverse()

    for index, element in enumerate(arr):
        sum = sum + (element * pow(2, index))

    return sum 

def hexToDecimal(numIn):
    sum = 0;
    arr = []
    for index, element in enumerate(numIn):
        match element:
            case 'a':
                arr.append(10)
            case 'b':
                arr.append(11)
            case 'c':
                arr.append(12)
            case 'd':
                arr.append(13)
            case 'e':
                arr.append(14)
            case 'f':
                arr.append(15)
            case  _:
                arr.append(int(element))

    arr.reverse()
    for index, element in enumerate(arr):
        sum = sum + (element * pow(16, index))

    return sum


def main():
    arr = []
    farr = []
    inputChar = str(input("Enter menu: \n(1) Decimal to binary \n(2) Binary To Decimal \n(3) Decimal to Hexadecimal \n(4) Hexadecimal to Decimal \n(Q) Quit \n>>> "))

    if inputChar == "1": 
        inputNum = int(input("Enter decimal number: "))
        farr = textToBinary(inputNum, arr, 2)
        farr.reverse()
        for i in farr:
            print(i, end="")

    elif inputChar == "2":
        inputNum = input("Enter binary number: ")
        sum = binaryToDecimal(inputNum)
        print(sum)

    elif inputChar == "3":
        inputNum = int(input("Enter decimal number: "))
        farr = textToBinary(inputNum, arr, 16)
        farr.reverse()
        for i in farr:
            print(i, end="")

    elif inputChar == "4":
        inputNum = input("Enter hex number: ")
        sum = hexToDecimal(inputNum)
        print(sum)


    elif inputChar.upper() == "Q":
        quit()

if __name__ == "__main__":
    main()