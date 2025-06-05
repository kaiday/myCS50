from cs50 import get_int
# if else in Python
x = get_int("X: ")
y = get_int("Y: ")
# in python the indentation (white space before an operation) is required to make sense what operation is in what block of code
if x < y:
    print("x is less than y") # indentation -> the print is in the "if" block
elif x > y: # short for else if -> outside of "if" block
    print("x is greater than y")
else:
    print("x is equal to y")
