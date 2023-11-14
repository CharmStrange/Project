import os
import datetime as dt
import ctypes as ct
import numpy as np
import sqlite3

class Struct(ct.Structure):

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

    def pop(self, index):
        del self.Base[index]

    pass

class Cursor:

    def __init__(self):
        pass

    def __del__(self):
        pass
