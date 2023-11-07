# SQLite DB 

개인 프로젝트 로컬 데이터베이스에 적합한 **SQLite**를 사용했다.

수집한 데이터를 어떻게 저장하면 좋을 지, 예를 들면 필드와 레코드의 정의와 그 길이 등을 생각하다가 10개의 텍스트만 추출해 상위부터 하위로 정렬하여 저장하는 구조를 떠올려냈다. 추출된 텍스트는 다음과 쿼리 문을 통해 데이터베이스에 저장된다.
 
[default](defaultQuery.sql) : 
```SQL 
INSERT INTO Carrot('Top1', 'Top2', 'Top3', 'Top4', 'Top5', 'Top6', 'Top7', 'Top8', 'Top9', 'Top10') VALUES(...)
```

```SQL
update Carrot set '컬럼명'=null where day=
```
