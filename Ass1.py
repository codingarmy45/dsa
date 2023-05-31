table_size = 10

class Hashing:
    def __init__(self):
        self.a = [0] * table_size

    def insert(self):
        number = int(input("Enter the phone number: "))
        self.hash_func(number)

    def hash_func(self, number):
        hash_index = number % table_size
        if self.a[hash_index] == 0:
            self.a[hash_index] = number
            print("Number added at index:", hash_index)
        else:
            print("Collision occurred")
            print("1. Linear Probing\n2. Quadratic Probing")  
            choice = int(input("Enter your choice: "))
            if choice == 1:
                result = self.linear_probing(hash_index, number)
                if result == -1:
                    print("Cannot find an empty space for insertion!")
                else:
                    print("Number added at index:", result)
            elif choice == 2:
                result = self.quadratic_probing(hash_index, number)
                if result == -1:
                    print("Cannot find an empty space for insertion!")
                else:
                    print("Number added at index:", result)
            else:
                print("Wrong choice!")

    def linear_probing(self, loc, number):
        for i in range(table_size):
            if self.a[loc] == 0:
                self.a[loc] = number
                return loc
            loc = (loc + 1) % table_size
        return -1

    def search_linear_probing(self, key):
        loc = key % table_size
        for i in range(table_size):
            if self.a[loc] == key:
                print("Key found at index:", loc)
                print("No. of comparisons required:", i)
                return
            loc = (loc + 1) % table_size
        print("Number not found")

    def quadratic_probing(self, loc, number):
        for i in range(table_size):
            temp = (loc + i*i) % table_size
            if self.a[temp] == 0:
                self.a[temp] = number
                return temp
           # loc = (loc + 1) % table_size
        return -1

    def search_quadratic_probing(self, key):
        loc = key % table_size
        for i in range(table_size):
            temp = (loc + i*i) % table_size
            if self.a[temp] == key:
                print("Key found at index:", temp)
                print("No. of comparisons required:", i)
                return
        print("Number not found")

    def search(self):
        number = int(input("Enter the number you want to search: "))
        print("1. Using linear probing\n2. Using quadratic probing")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            self.search_linear_probing(number)
        elif choice == 2:
            self.search_quadratic_probing(number)
        else:
            print("Wrong choice")

    def display(self):
        print("Index  Number")
        for i in range(table_size):
            print("  ", i+1, "    ", self.a[i])

hash_table = Hashing()

while True:
    print("\nOperations:")
    print("1. Insert")
    print("2. Search")
    print("3. Display")
    print("4. Exit")
    choice = int(input("Enter your choice: "))

    if choice == 1:
        hash_table.insert()
    elif choice == 2:
        hash_table.search()
    elif choice == 3:
        hash_table.display()
    elif choice == 4:
        break
    else:
        print("Invalid choice!")
