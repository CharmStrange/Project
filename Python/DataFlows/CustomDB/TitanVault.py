import os
import datetime
import ctypes as ct

class Struct(ct.Structure):
    _fields_ = [
        ('Header', ct.c_short),
        ('Data_int', ct.c_int),
        ('Data_double', ct.c_double)
               ]

class TitanVault:

    def __init__(self, DataBaseName):
        self.DataBaseName = DataBaseName
        

    def method_1() :
        pass

    def method_2() :
        pass

    def method_3() :
        pass

    def method_4() :
        pass

    def method_5() :
        pass

    pass
