import luigi
import sqlite3

# ELT & ETL 워크플로우 정의
# (1) : 데이터 수집 -> 데이터 DB 적재 -> 사용자 정의 작업 설정
# (2) : 데이터 수집 -> 데이터 변환 후 DB 적재 -> 사용자 정의 작업 설정

# 더미 데이터 프레임 제작
class RandomDataFrame(luigi.Task) :
    def run(self) : 
        made_dummy = make_dummies()
        Dummy = made_dummy.to_csv("test.csv")
        return Dummy

    def output(self) :
        pass

# Extraction class - luigi.Task inheritance
class Extraction(luigi.Task) :
    def output(self) :
        pass

    def run(self) :
        pass

    def requires(self) :
        return RandomDataFrame()

# Transformation class - luigi.Task inheritance
class Transformation(luigi.Task) :
    def output(self) :
        pass

    def run(self) :
        pass

    def requires(self) :
      return Extraction()

# Loading class - luigi.Task inheritance
class Loading(luigi.Task) :
    def output(self) :
        pass

    def run(self) :
        pass

    def requires(self) :
      return Transformation()

# 워크플로우 실행
#if __name__ == "__main__" :
#    luigi.build([Loading()], local_scheduler=True)
