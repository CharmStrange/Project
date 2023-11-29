import os
import datetime as dt
import ctypes as ct
import numpy as np
import sqlite3

class Struct(ct.Structure):
    # fields are customizable
    _fields_ = [
        ('Header', ct.c_short),
        ('Data_int', ct.c_int),
        ('Data_double', ct.c_double)
               ]

    def __init__(self):
        pass

    def __del__(self):
        pass

    def push(self, Header, Data_int, Data_double):
        self.Header = Header
        self.Data_int = Data_int
        self.Data_double = Data_double

class TitanVault:

    def __init__(self, DataBaseName):
        self.DataBaseName = DataBaseName
        self.CreatedDate = dt.datetime.now()
        self.Base = []

    def __del__(self):
        pass

    def newStruct(self):
        self.Structure = Struct()
        self.Base.append(self.Structure)
        return self.Structure

    def pop(self, index):
        del self.Base[index]

class Cursor:

    db = 0
    dbs = []

    @classmethod
    def About(cls):
        print(f"Database(s) in database list : {cls.db}")

        for database in cls.dbs:
            print(f"All database(s) : {database}")

    """

    | Document |

    01. Create a new database.
    >>>

    02. Utilize it.
    >>>

    """

    def __init__(self, Name, cnt=1):
        for i in range(cnt):
            self.db += 1
            titanvault = TitanVault(Name)
            self.dbs.append(titanvault)
            print(f"Created new database(s) | {titanvault} | Database can be controled by methods.\n")
        print(f"Created database(s) : {self.db} | Length of database list : {len(self.dbs)}")

    def __del__(self):
        pass

    def information(self):
        index = 0

        for element in self.dbs:
            print(f"Informations of each database :\nDatabse list index [{index}] | Database name : {element.DataBaseName} | Created date : {element.CreatedDate}")
            index+=1

    def insert(self, index, header, data_int, data_double):
        new_Struct = self.dbs[index].newStruct()
        print(type(new_Struct))
        new_Struct.push(header, data_int, data_double)
        return new_Struct

    def pop(self, index):
        del self.dbs[index]
        print("Successfully deleted.")
