pizzas =  { # Dictionary contains key and value
    "cheese" : 9,  # key : value
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}

pizzas["cheese"] = 8 # change the key's value

pizzas["bacon"] = 14 # add a key and the associated value

for pie in pizzas: # iterate thru the dictionary
    print(pie) # print out the key

for pie,price in pizzas.items(): # iterate by values
    print(price) # print out the value

# The order of the dictionary is not guaranteed

for pie, price in pizzas.items():
    print("A whole {} pizza costs ${}".format(pie,price))
   #print("A whole " + pie + " pizza cost $" + str(price)) -> would give the same output