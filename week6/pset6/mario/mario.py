from sys import exit
def get_value(s):
    while True:
        try:
            n = int(input(s))
            if n > 0 and n < 9:
                return n
        except ValueError:
            continue

value = get_value("Height: ")

if value == 1:
    print("#")
    exit(0)


for height in range(value):
    for space in range(height, value -1 , 1):
        print(" ", end = "")

    for left in range(height + 1):
        print("#", end = "")
    print()