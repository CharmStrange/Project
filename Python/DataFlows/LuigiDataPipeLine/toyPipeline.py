import luigi
import sqlite3

# ELT & ETL 워크플로우 정의
# (1) : 데이터 수집 -> 데이터 DB 적재 -> 사용자 정의 작업 설정 
# (2) : 데이터 수집 -> 데이터 변환 후 DB 적재 -> 사용자 정의 작업 설정

# Extraction class - luigi.Task inheritance 
class Extraction(luigi.Task) :
    def output(self) :
        pass

    def run(self) : 
        pass

class Transformation(luigi.Task) :
    def output(self) :
        pass

    def run(self) : 
        pass

    def requires(self) :
      pass

class Loading(luigi.Task) :
    def output(self) :
        pass

    def run(self) : 
        pass

    def requires(self) :
      pass
      
