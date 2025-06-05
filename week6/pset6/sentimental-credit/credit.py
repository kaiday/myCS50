from sys import exit

def main():
    number = str(get_value("Number: "))
    length = len(number)
    if length >= 13 and length <= 16:
        if not Luhn_Algorithm(number,length):
            print("INVALID")
            exit(1)

        if number[0] == "4":
            print("VISA")
            exit(0)

        elif number[0] == "3" and (number[1] == "4" or number[1] == "7"):
            print("AMEX")
            exit(0)

        elif number[0] == "5" and number[1] > "0" and number[1] < "6":
            print("MASTERCARD")
            exit(0)

        else:
            print("INVALID")
            exit(1)
            
    print("INVALID")
    exit(1)

def get_value(s):
    while True:
        try:
            n = int(input(s))
            if n > 0:
                return n
        except ValueError:
            continue

def Luhn_Algorithm(num, len):
    sum = 0

    if len%2 == 0:
        start1 = 0
        start2 = 1
    else:
        start1 = 1
        start2 = 0

    for i in range(start1, len, 2):
        tmp = int(num[i])*2
        if tmp >= 10:
            sum += tmp//10
            sum += tmp%10
        else:
            sum += tmp

    for i in range(start2 , len, 2):
        sum += int(num[i])

    if sum%10 == 0:
        return True

    return False

main()