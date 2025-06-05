from sys import argv

if len(argv) == 2:
    print(f"Hello, {argv[1]}")
else:
    print("hello, world")

print()
print("Print all the arg")
#for i in range(len(argv)):
#    print(argv[i])

#-> can be written as
for arg in argv:
    print(arg)

print()
print("Print every arg with given start value")
#-> Python also allow us to determine where to start in the list
for arg in argv[1:]: # [1:] will mean that start from 1 and onward
    print(arg)

print()
print("Print every arg with given start value and end value")
for arg in argv[0:2]:
    print(arg)