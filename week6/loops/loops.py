# While loop
i = 0
while i < 3:
    print("Moew")
    i +=1

print(" ")
# For loop
# This is the closest thing to "for(int i = 0; i < 3: i++)" in C
for i in [0,1,2]: # This is a list, Python does not have arrays
    print("moew")

print(" ")
# The previous code is not very well designed, espeacially when we want to scale up 0,1,2,...,500 we have to type all those numbers
for i in range(3): # range of given value, start at 0 on up
    print("MOEW")

print(" ")
# loop forever
while True:
    print("Moewww")
    break