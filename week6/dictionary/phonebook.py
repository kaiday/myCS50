people = {  # people = {} -> this is a dictionary, people = dict() will work the same
    "Carter" : "+1-617-495-1000" ,
    "David"  : "+1-949-468-2750"
    # Key    :  Value
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}") # people[name] Go to the "people" dictionary with the key "name" and return the value

