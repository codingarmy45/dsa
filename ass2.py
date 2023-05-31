class KeyValuePair:
    def __init__(self, key, value):
        self.key = key
        self.value = value


class Dictionary:
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(size)]

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        chain = self.table[index]
        for pair in chain:
            if pair.key == key:
                pair.value = value
                return
        chain.append(KeyValuePair(key, value))
        print("Key-value pair inserted successfully.")

    def find(self, key):
        index = self._hash(key)
        chain = self.table[index]
        for pair in chain:
            if pair.key == key:
                return pair.value
        return None

    def delete(self, key):
        index = self._hash(key)
        chain = self.table[index]
        for i, pair in enumerate(chain):
            if pair.key == key:
                del chain[i]
                print("Key-value pair deleted successfully.")
                return
        print("Key not found.")

    def display(self):
        for i, chain in enumerate(self.table):
            if len(chain) > 0:
                print(f"Index {i}:")
                for pair in chain:
                    print(f"  Key: {pair.key}, Value: {pair.value}")


def print_menu():
    print("1. Insert a key-value pair")
    print("2. Find a value by key")
    print("3. Delete a key-value pair")
    print("4. Display dictionary")
    print("5. Exit")


# Example usage:
dictionary = Dictionary(10)

while True:
    print_menu()
    choice = input("Enter your choice: ")

    if choice == "1":
        key = input("Enter the key: ")
        value = input("Enter the value: ")
        dictionary.insert(key, value)

    elif choice == "2":
        key = input("Enter the key to find the corresponding value: ")
        result = dictionary.find(key)
        if result is not None:
            print(f"Value: {result}")
        else:
            print("Key not found.")

    elif choice == "3":
        key = input("Enter the key to delete the corresponding key-value pair: ")
        dictionary.delete(key)

    elif choice == "4":
        dictionary.display()

    elif choice == "5":
        print("Exiting...")
        break

    else:
        print("Invalid choice. Please try again.")
