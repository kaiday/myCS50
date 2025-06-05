from sys import exit

def main():
    change = get_value("Change owned: ")

    if change == 0:
        print(change)
        exit(0)

    quarter = calculate_quarter(change)
    dime = calculate_dime(change - quarter*25)
    nickel = calculate_nickel(change - quarter*25 - dime*10)
    penny = calculate_penny(change - quarter*25 - dime*10 - nickel*5)

    print(quarter + dime + nickel + penny)

def get_value(s):
    while True:
        try:
            n = float(input(s))
            if n >= 0:
                return int(n*100)
        except ValueError:
            continue

def calculate_quarter(value):
    if value == 25:
        return 1
    count = 0
    for i in range(24, value, 25):
        count += 1

    return count

def calculate_dime(value):
    if value == 10:
        return 1
    count = 0
    for i in range(9, value, 10):
        count += 1

    return count

def calculate_nickel(value):
    if value == 5:
        return 1
    count = 0
    for i in range(4, value, 5):
        count += 1

    return count

def calculate_penny(value):
    if value == 1:
        return 1
    count = 0
    for i in range(value):
        count += 1

    return count

main()