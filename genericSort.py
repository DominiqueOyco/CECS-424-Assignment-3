#CECS 424 ASSIGNMENT 3
#genericSort.py
#Dominique Oyco (014605758)

class People:
    def __init__ (self, name, age):
        self.name = name
        self.age = age
    def __str__(self):
        return str(self.name) + "-" + str(self.age)

def compare(x, y):
    return (x > y) - (x < y)

def ageCompare(x, y):
    return compare(x.age, y.age)

#List of objects similar to struct people in C. 
#Contains a person's name and age
peopleList = [People("Hal", 20), 
               People("Susann", 31),
               People("Dwight", 19),
               People("Kassandra", 21), 
			   People("Lawrence", 25),
               People("Cindy", 22), 
               People("Cory", 27), 
               People("Mac", 19),
               People("Romana", 27), 
               People("Doretha", 32),
               People("Danna", 20), 
               People("Zara", 23), 
               People("Rosalyn", 26), 
               People("Risa", 24), 
               People("Benny", 28),
               People("Juan", 33), 
               People ("Natalie", 25)]
               
# Sorting a list of floating point values
numbers = [645.32, 37.40, 76.30, 5.40, -34.23, 1.11, -34.94, 23.37, 635.46, 
           -876.22, 467.73, 62.26]
numbers.sort()
print("The sorted numbers are:", numbers, "\n") 

def __repr__(self):
    return str(self)

choice = 0
while True:
    choice = int(input("Would you like to sort by name (1) or by age (2)?: "))
    try:
        if choice == 1: #sort people by name
            peopleList.sort(key = lambda People: People.name) 
            print(*peopleList, sep = "\n"); #need * because if it's not present, 
                                      #the address will be printed instead of
                                      #the list item.
        elif choice == 2: #sort people by age in descending order
            peopleList.sort(key = lambda People: People.age, reverse = True) 
            print(*peopleList, sep = "\n");
        else:
            raise ValueError
    except ValueError:
        print('Invalid input. Please try again')
    else:
        break
