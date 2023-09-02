# [ *작성 보고서* ]

### *최근 들어 여름철 폭우에 의한 피해가 굉장히 많이 발생하고 있다. 기후 문제가 심각해짐에 따라 폭우에 의한 침수 피해나 인명 피해 등과 같은 수해는 계속해서 늘어날 것으로 보인다. 세종특별자치시가 이를 사전에 대비하는데 도움이 되고자 이 프로젝트를 진행하게 되었다*. 

## < 목차 >
### - **[수해와 관련된 개략적인 세종특별자치시의 현황 파악]**
### - **[기록된 공개 정형 데이터로 문제점을 파악]**
### -

---

> # 1. 수해와 관련된 개략적인 세종특별자치시의 현황 파악
> *이 부분에선 세종특별자치시의 수해와 관련된 여러 자료를 찾아 전반적인 현황 개요를 알아본다.*
> 
> [[생활안전지도 - 세종특별자치시 침수흔적도](https://www.safemap.go.kr/main/smap.do?flag=2#)],
> [[뉴스 1](https://www.youtube.com/watch?v=qtdogMMv9UM)],
> [[뉴스 2](https://www.youtube.com/watch?v=Nzc5gc7kxOA)],
> [[뉴스 3](https://www.jbnews.com/news/articleView.html?idxno=1400821)],
> [[뉴스 4](https://www.yna.co.kr/view/AKR20230715029452063)],
> [[뉴스 5](https://news.kbs.co.kr/news/view.do?ncd=7724580)],
> [[뉴스 6](https://www.sjsori.com/news/articleView.html?idxno=64488)],
> [[뉴스 7](https://www.sjsori.com/news/articleView.html?idxno=64574)],
> [[뉴스 8](https://m.khan.co.kr/local/Sejong/article/202307101345001#c2b)],
> [[세종특별자치시 불투수 면적 관련 뉴스](https://www.sjsori.com/news/articleView.html?idxno=44806)],
> [[침수 피해 연구 보고서](202205131112582602.pdf)]
> ```
> [특보] 세종시 등 산사태·침수…인명피해 잇따라 / KBS 2023.07.15.
> 세종 328㎜ 물폭탄… 이응다리 침수 위기
> [특보] 세종시 등 산사태·침수…인명피해 잇따라
> 세종시 해밀동 아파트, “매년 여름에는 물바다 돼요”
> 세종 곳곳서 집중 호우 피해…아파트 승강기 침수로 주민 불편 겪기도
> ...
> ```
> 위 자료들로 개략적인 피해 현황을 파악할 수 있었다. 결과적으로 이는 충분히 심각한 문제로 인식되며 문제 해결의 필요성을 느끼게 한다.
> > 대부분의 도시 침수 피해 원인은 충분하지 못한 하수(우수/오수)처리시설의 수와 처리 용량, 그리고 넓은 불투수 면적이다.
>
> > [유역, 하천 등의 범람으로 인한 근방의 침수 피해](https://www.ytn.co.kr/_ln/0115_202307181904429744)도 존재한다. (세종특별자치시의 조치원읍 바로 옆 오송읍 사고)
---
> # 2. 기록된 공개 정형 데이터로 문제점을 파악
> [[세종특별자치시 상하수도 처리시설 데이터](세종특별자치시_상하수도_처리시설_현황_20230310.csv)(위도, 경도, 일일처리용량)],
> [[수해 위험 지역 현황 데이터](행정안전부_인명피해_우려지역_현황_20230616.csv)]
> [[2023년 세종특별자치시 강우량 데이터](rf2023.csv)]
> 
> ```Python
> import pandas as pd
>import folium
> import geopandas as gpd
>from folium import GeoJson
>
>세종특별자치시_상하수도_처리시설_현황_20230310 = pd.read_csv("세종특별자치시_상하수도 처리시설 현황_20230310.csv", encoding='cp949')
>행정안전부_인명피해_우려지역_현황_20230616 = pd.read_csv("행정안전부_인명피해 우려지역 현황_20230616.csv", encoding='cp949')
>강우량2023 = pd.read_csv("rf2023.csv", encoding='cp949')
> 
> # 세종특별자치시 경계 GeoJSON 파일 경로
>geojson_path = 'hangjeongdong_세종특별자치시.geojson'
>
># GeoJSON 파일을 geopandas로 읽기
>gdf = gpd.read_file(geojson_path)
>
># 지도 생성
>m = folium.Map(location=[36.5, 127.25], zoom_start=11)
>
># 세종특별자치시 경계 GeoJson 객체 생성
>geojson = GeoJson(gdf,
>                  style_function=lambda feature: {
>                      'color': 'blue',
>                      'fillColor': 'blue',
>                      'weight': 2,
>                      'fillOpacity': 0.1,
>                  })
>
># 세종특별자치시 경계를 지도에 추가
>geojson.add_to(m)
>
># 데이터프레임을 반복하면서 마커와 팝업 추가
>for index, row in 세종특별자치시_상하수도_처리시설_현황_20230310.iterrows():
>    marker = folium.Marker(
>        location=[row['위도'], row['경도']],
>        popup=f"{row['처리시설명']}<br>처리용량(톤-일별): {row['처리용량(톤-일별)']}",
>        tooltip=row['처리시설명']  # 마커에 대한 툴팁 설정
>    )
>    marker.add_to(m)
>
># 지도 저장
>m.save('facility_map_with_capacity.html')
> ```
> 
> [[하수처리시설 현황 지도](map.zip)]
> 
> <img width="348" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/4e3cef7d-b387-41a7-8e8a-e1785c97e43c">
><img width="333" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/9649fb0c-d031-456c-a5ae-32ad7605f5af">

> 
