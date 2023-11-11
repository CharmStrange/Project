Titan1 = TitanVault('titan1')
Titan1.DataBaseName
Titan1.CreatedDate
Titan1.newStruct()
Titan1.Base[0].push(10, 64, 0.5)

Titan1.newStruct()
Titan1.Base[1].push(20, 128, 1.0)

len(Titan1.Base)
Titan1.Base[0].Header; Titan1.Base[0].Data_int; Titan1.Base[0].Data_double
Titan1.Base[1].Header; Titan1.Base[1].Data_int; Titan1.Base[1].Data_double

###

Titan2 = TitanVault('titan2')
Titan2.DataBaseName
Titan2.CreatedDate
Titan2.newStruct()
Titan2.Base[0].push(5, 32, 0.25)

Titan2.newStruct()
Titan2.Base[1].push(2, 16, 0.12)

len(Titan2.Base)
Titan2.Base[0].Header; Titan2.Base[0].Data_int; Titan2.Base[0].Data_double
Titan2.Base[1].Header; Titan2.Base[1].Data_int; Titan2.Base[1].Data_double
