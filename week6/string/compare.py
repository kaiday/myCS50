s  = input("String: ")

t = s.capitalize() #this will capitalize only the first char in the string

print(f"String before: {s}")
print(f"String after: {t}")

str1 = input("Str1: ")
str2 = input("Str2: ")

if str1 == str2:  # in Python, u dont need to worried abt comparing 2 string with "==" line in C
                  # because in Python, there is no pointer 
    print("Same")
else:
    print("Different")