db = 0
kezdet = int(input("Egyik szám: "))
veg = int(input("Másik szám: "))

if kezdet > veg:
    seg=kezdet
    kezdet=veg
    veg=seg

for szam in range(kezdet,veg+1):
    i=2
    isprim=True
    while (i<=szam/2):
        if(szam%i == 0):
            isprim=False
            break
        i=i+1
    if isprim:
        print(szam)
        db+=1
    
print("A Primek szama",db)

db = 0
kezdet = int(input("Egyik szám: "))
veg = int(input("Másik szám: "))
if(kezdet>veg):
    seg=kezdet
    kezdet=veg
    veg=seg

for szam in range(kezdet,veg+1):
    i=2
    while (i<=szam/2)and(szam % i !=0):
        i=i+1
    if(i>szam/2):
        print (szam)
        db=db+1
print("A Primek szama",db)


