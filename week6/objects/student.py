class Student():

    def __init__(self, name, id): # constructor
        self.name = name
        self.id = id

    def changeID(self, id): # self is the object student, always include self
        self.id = id

    def print(self):
        print("{} - {}".format(self.name, self.id))

# explicit function  
def method():
    print("Student Class")