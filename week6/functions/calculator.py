# from cs50 import get_int

# x = get_int("x: ")
# y = get_int("y: ")

# print(x + y) -> will give us the sum of 2 numbers

# Without the training wheels, Python has "input()" function that allow us to get input from user
# x = input("x: ") # But the "input()" will always return a String even if we type in a number
x = int(input("x: ")) # This will allow us to get int from input
y = int(input("y: "))

print(x+y)

z = x/y

print(z)

print(f"{z:.50f}") # the first f is for format .50 show 50 digits to the right and f is for float