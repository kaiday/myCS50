
# Tuples are ordered, immutable sets of data

presidents  = [
    ("George Washington",1789),
    ("John Adams", 1797),
    ("Thomas Jefferson", 1801),
    ("James Madison",1809)
]  # this is a list of tuples

for prez, year in presidents:
    print("In {1}, {0} took office".format(prez, year))

