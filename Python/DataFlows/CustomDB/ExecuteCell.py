Titan1 = TitanVault('titan1')
Titan1.DataBaseName
Titan1.CreatedDate
Titan1.newStruct()
Titan1.Base[0].push(10, 64, 0.5)

print(len(Titan1.Base))

Titan1.newStruct()
Titan1.Base[1].push(20, 128, 1.0)

print(len(Titan1.Base))

# Checking each Struct
#Titan1.Base[0].Header; Titan1.Base[0].Data_int; Titan1.Base[0].Data_double
#Titan1.Base[1].Header; Titan1.Base[1].Data_int; Titan1.Base[1].Data_double

Titan1.pop(0)
print(len(Titan1.Base))

###

Titan2 = TitanVault('titan2')
Titan2.DataBaseName
Titan2.CreatedDate
Titan2.newStruct()
Titan2.Base[0].push(5, 32, 0.25)

print(len(Titan2.Base))

Titan2.newStruct()
Titan2.Base[1].push(2, 16, 0.12)

print(len(Titan2.Base))

# Checking each Struct
#Titan2.Base[0].Header; Titan2.Base[0].Data_int; Titan2.Base[0].Data_double
#Titan2.Base[1].Header; Titan2.Base[1].Data_int; Titan2.Base[1].Data_double

Titan2.pop(0)
print(len(Titan2.Base))

###

test1 = Cursor('titan1')
test1.information()
test1.insert(0, 1, 2, 3.14)

test2 = Cursor('titan2')
test2.information()
test2.insert(1, 2, 3, 4.25)

test3 = Cursor('titan3')
test3.About()
test3.pop(0)
test3.About()
