s = input("Do you agree ? ")

# in Python, it support OOP just like java
t = s.lower()

if s in ["y", "yes"]: #There is no char in Python, u use string of size 1
    print("Agreed!")
elif s in ["n", "no"]:
    print("Not agreed!")

