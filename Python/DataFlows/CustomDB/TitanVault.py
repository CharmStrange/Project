import os
import datetime as dt
import ctypes as ct
import sqlite3

class Struct(ct.Structure):
    _fields_ = [
        ('Header', ct.c_short),
        ('Data_int', ct.c_int),
        ('Data_double', ct.c_double)
               ]

class TitanVault:

    def __init__(self, DataBaseName):
        self.DataBaseName = DataBaseName
        self.CreatedDate = dt.datetime.now()
        self.Structure = Struct()

    def __del__(self):
        pass

    def push(self, Header, Data_int, Data_double):
        self.Structure.Header = Header
        self.Structure.Data_int = Data_int
        self.Structure.Data_double = Data_double

    def pop(self):
        pass

    def method_3(self):
        pass

    def method_4(self):
        pass

    def method_5(self):
        pass

    pass
