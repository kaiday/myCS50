import csv

with open("phonebook.csv", "a") as file: # "a" means append mode

    name = input("Name: ")
    number = input("Number: ")

    writer = csv.DictWriter(file, fieldnames=["name","number"])
    writer.writerow({"name": name ,"number": number})
