A = {11, 25, 39, 14, 5}
B = {39, 14, 5, 62, 78}
print("given sets are: \n Set A: ", A, "\n Set B: ", B)
print("Select operation to perform: \n1.Add \n2.Remove \n3.Contain \n4.Size \n5.Intersection \n6.Union \n7.Difference \n8.Subset")
op = int(input("Enter operation: "))
if op == 1:
    s = input("Enter set to add element to: ")
    ele = int(input("Enter element: "))
    if s == "A":
        A.add(ele)    
        print(A)
    elif s == "B":
        B.add(ele)
        print(B)
    else: 
        print("Error")
        
elif op == 2:
    t = input("Enter set to remove element from: ")
    ele = int(input("Enter element: "))
    if t == "A":
        A.remove(ele)        
        print(A)
    elif t == "B":
        B.remove(ele)
        print(B)
    else: 
        print("Error")
        
elif op == 3:
    u = input("Enter set to check element in: ")
    ele = int(input("Enter element: "))
    if u == "A":
        if ele in A:       
            print("True")
    elif u == "B":
        if ele in B:       
            print("True")
    else: 
        print("Error")        

elif op == 4:
    v = input("Enter set to check size: ")
    if v == "A":
       print(len(A))
    elif v == "B":
        print(len(B))
    else: 
        print("Error")

elif op == 5:
    C = A.intersection(B)
    print("Intersection is: ", C)
 
elif op == 6:
    D = A.union(B)
    print("Union is: ", D)    
    
elif op == 7:
    E = A.difference(B)
    print("Difference is: ", E)    
    
elif op == 8:
    F = A.issubset(B)
    print(F)
    
else:
    print("error")   
