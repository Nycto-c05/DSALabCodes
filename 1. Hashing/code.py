HashTable = [-1 for i in range(10)]
size = 10
count = 0
comparison = 0
compareForquad = 0

def hashFunc(val):
    key = val % size
    return key

def insert(data):
    key = hashFunc(data)
    global count
    if (count == size):
        print("Hash Table is full!! ")
        return

    if (HashTable[key] == -1):
        HashTable[key] = data
        count += 1
    else:
        key = quadraticProb(key)
        HashTable[key] = data
        count += 1

def linearProbing(key):
    global comparison
    while (HashTable[key] != -1):
        key  = (key + 1) % size
    return key

def quadraticProb(key):
    global HashTable
    curr = key
    i = 1
    while (HashTable[curr] != -1):
        curr = (key + i*i) % size
        i += 1
    return curr

     
def linearProbingForSearch(key, data):
    global comparison
    while (HashTable[key] != data):
        key  = (key + 1) % size
        comparison += 1
        if comparison > size :
            print (f"{data} not found! ")
            return comparison
        
    print(f"{data} is present in the hashtable at index {key}")
    return comparison

def quadraticProbingForSearch(key, data):
    global HashTable, compareForquad
    curr = key
    i = 1
    while (HashTable[curr] != data):
        curr = (key + i*i) % size
        i += 1
        compareForquad += 1
        if compareForquad > size:
            print (f"{data} not found! ")
            return compareForquad
        
    print(f"{data} is present in the hashtable at index {curr}")
    return compareForquad


def search(data):
    key = hashFunc(data)    
    global comparison, compareForquad
    comparison += 1
    compareForquad += 1

    if HashTable[key] == data :
        print(f"{data} is present in the hashtable at index {key}")   
        print("No. of comparisons made is 1")     
    else:
        print("Searching using linear probing.........")
        linearProbingForSearch(key, data)
        print(f"No. of comparisons made in linear probing are {comparison}")

        print("\nSearching using quadratic probing.........")
        quadraticProbingForSearch(key, data)
        print(f"No. of comparisons made in quadratic probing are {compareForquad}")


insert(11)
insert(33)
insert(43)
insert(81)
insert(56)
insert(79)
insert(10)
insert(99)
insert(45)
insert(53)
print(HashTable)

s = int(input("Enter the data to be searched: "))
search(s)
