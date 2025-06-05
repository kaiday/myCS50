
def main():
    height = get_value("Height")
    for i in range(height):
        print("#")

    print()

    width = get_value("Width")
    for i in range(width):
        print("#", end="")  # the print function at the end there always will be a "\n" value
                            # -> so to print every thing in a single line, u must define the end value to be nothing
    print()

    print()
    print("Block")
    for i in range(height):
        print("#"*width)

def get_value(s):
    print(s)
    while True:
        try:
            n = int(input("Value: "))
            if n > 0:
                return n
        except ValueError:
            print("Not an integer")

main()