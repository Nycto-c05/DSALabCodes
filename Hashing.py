hashTable = [-1 for i in range(10)]
count = 0
size = 10

def hasF(data):
    key = data%size
    return key;

def insert():

    global count, size, hashTable;

    if(count == size):
        print("Hash table is full");
    else:
        data = int(input("Enter the data: "))
        key = hasF(data)

        if(hashTable[key] == -1):
            hashTable[key] = data
            count+=1
        else:
            QuadProb(data, key)
            count+=1

def linearProbing(data, key):
    global size, count, hashTable
    while(hashTable[key]!= -1):
        key = (key + 1)%size
    hashTable[key] = data

def QuadProb(data, key):
    global size, count, hashTable
    i = 1
    curr = key
    while(hashTable[curr]!= -1):
        newkey = (key + (i**2))%size
        curr = newkey
        i+=1

    hashTable[newkey] = data

insert();
print(hashTable)
insert()
print(hashTable)
insert()
print(hashTable)
    




