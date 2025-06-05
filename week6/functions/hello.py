from cs50 import get_string, get_int # "," allows us to implements multiple function from a library

print("hello, world")

# in Python u dont need to specify the variable, it will automatically determine
answer = get_string("What is your name: ")

print("Hi, " + answer)

print("Hi,", answer)

print(f"Hi, {answer}")


# int counter = 0; in C
counter = 0

counter = counter + 1
counter += 1 # in Python it does not allow counter++

print("Counter:", counter)
