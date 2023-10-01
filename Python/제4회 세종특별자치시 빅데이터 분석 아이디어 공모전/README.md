# [ *작성 보고서* ]

### *최근 들어 여름철 폭우에 의한 피해가 굉장히 많이 발생하고 있다. 기후 문제가 심각해짐에 따라 폭우에 의한 침수 피해나 인명 피해 등과 같은 수해는 계속해서 늘어날 것으로 보인다. 세종특별자치시가 이를 사전에 대비하는데 도움이 되고자 이 프로젝트를 진행하게 되었다*. 

## < 목차 >
### - **[수해와 관련된 개략적인 세종특별자치시의 현황 파악](#1)**
### - **[기록된 공개 정형 데이터로 문제점을 파악](#2)**
### - **[파악한 문제점을 바탕으로 아이디어의 실현 가능성 및 기대 효과를 판단](#3)**
### - **[결론](#결론)**
### - **[후기](#후기)**
---

> # #1. 수해와 관련된 개략적인 세종특별자치시의 현황 파악 <a name="1"></a>
> *이 부분에선 세종특별자치시의 수해와 관련된 여러 자료를 찾아 전반적인 현황 개요를 알아본다.*
> 
> [[생활안전지도 - 세종특별자치시 침수흔적도](https://www.safemap.go.kr/main/smap.do?flag=2#)(~2017)],
> [[뉴스 1](https://www.youtube.com/watch?v=qtdogMMv9UM)],
> [[뉴스 2](https://www.youtube.com/watch?v=Nzc5gc7kxOA)],
> [[뉴스 3](https://www.jbnews.com/news/articleView.html?idxno=1400821)],
> [[뉴스 4](https://www.yna.co.kr/view/AKR20230715029452063)],
> [[뉴스 5](https://news.kbs.co.kr/news/view.do?ncd=7724580)],
> [[뉴스 6](https://www.sjsori.com/news/articleView.html?idxno=64488)],
> [[뉴스 7](https://www.sjsori.com/news/articleView.html?idxno=64574)],
> [[뉴스 8](https://m.khan.co.kr/local/Sejong/article/202307101345001#c2b)],
> [[뉴스 9](https://www.inews365.com/mobile/article.html?no=726967)],
> [[세종특별자치시 불투수 면적 관련 뉴스](https://www.sjsori.com/news/articleView.html?idxno=44806)],
> [[침수 피해 연구 보고서](202205131112582602.pdf)]
> ```
> [특보] 세종시 등 산사태·침수…인명피해 잇따라 / KBS 2023.07.15.
> 세종 328㎜ 물폭탄… 이응다리 침수 위기
> [특보] 세종시 등 산사태·침수…인명피해 잇따라
> 세종시 해밀동 아파트, “매년 여름에는 물바다 돼요”
> 세종 곳곳서 집중 호우 피해…아파트 승강기 침수로 주민 불편 겪기도
> 세종시 조치원 중심 침수피해 발생…인명피해 없어
> ...
> ```
> 위 자료들로 개략적인 피해 현황을 파악할 수 있었다. 결과적으로 이는 충분히 심각한 문제로 인식되며 문제 해결의 필요성을 느끼게 한다.
>
> #### : 대표적인 세종특별자치시의 침수 피해 위험 지역은 **행정중심복합도시**와 **조치원읍**이라고 가정할 수 있을 것이다.
>
> > **Point**. 대부분의 도시 침수 피해 원인은 충분하지 못한 하수(우수/오수)처리시설의 수와 처리 용량, 그리고 넓은 불투수 면적이다.
>
> > **Plus**. [유역, 하천 등의 범람으로 인한 근방의 침수 피해](https://www.ytn.co.kr/_ln/0115_202307181904429744)도 존재한다. (세종특별자치시의 조치원읍 바로 옆 오송읍 사고)
---
> # #2. 기록된 공개 정형 데이터로 문제점을 파악 <a name="2"></a>
> [[세종특별자치시 상하수도 처리시설 데이터](https://github.com/CharmStrange/Project/blob/main/Python/%EC%A0%9C4%ED%9A%8C%20%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C%20%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%EC%95%84%EC%9D%B4%EB%94%94%EC%96%B4%20%EA%B3%B5%EB%AA%A8%EC%A0%84/CSV%20%EB%8D%B0%EC%9D%B4%ED%84%B0/%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C_%EC%83%81%ED%95%98%EC%88%98%EB%8F%84_%EC%B2%98%EB%A6%AC%EC%8B%9C%EC%84%A4_%ED%98%84%ED%99%A9_20230310.csv)(위도, 경도, 일일처리용량)],
> [[수해 위험 지역 현황 데이터](https://github.com/CharmStrange/Project/blob/main/Python/%EC%A0%9C4%ED%9A%8C%20%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C%20%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%EC%95%84%EC%9D%B4%EB%94%94%EC%96%B4%20%EA%B3%B5%EB%AA%A8%EC%A0%84/CSV%20%EB%8D%B0%EC%9D%B4%ED%84%B0/%ED%96%89%EC%A0%95%EC%95%88%EC%A0%84%EB%B6%80_%EC%9D%B8%EB%AA%85%ED%94%BC%ED%95%B4_%EC%9A%B0%EB%A0%A4%EC%A7%80%EC%97%AD_%ED%98%84%ED%99%A9_20230616.csv)],
> [[2023년 세종특별자치시 강우량 데이터](https://github.com/CharmStrange/Project/blob/main/Python/%EC%A0%9C4%ED%9A%8C%20%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C%20%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%EC%95%84%EC%9D%B4%EB%94%94%EC%96%B4%20%EA%B3%B5%EB%AA%A8%EC%A0%84/CSV%20%EB%8D%B0%EC%9D%B4%ED%84%B0/rf2023.csv)]
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
> ###
> [[하수처리시설 현황 지도](map.zip)]
> 
> <img width="348" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/4e3cef7d-b387-41a7-8e8a-e1785c97e43c">
><img width="333" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/9649fb0c-d031-456c-a5ae-32ad7605f5af">
>
> 가장 먼저 세종특별자치시의 하수처리시설 현황(위치)을 시각화하여 HTML 파일로 저장했다. 마커를 클릭하면 그 하수처리시설의 일일 처리량(단위 : 톤)을 볼 수 있다. 
>
> 이와 관련해 <[행정중심복합도시건설청 세종특별자치시 행복도시 정보](https://naacc.go.kr/WEB/contents/N1010100000.do)>에 기재된 내용에 따르면, 앞서 침수 피해 위험지역이라고 가정한 행정중심복합도시의 구역은 다음과 같다.
>
> <img width="765" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/1b62df9a-fc8c-4d6a-9292-8943c42ceb97">
>
> 그런데 방금 제작한 하수처리시설 현황을 보면, 행정중심복합도시엔 남서쪽 수질복원센터 A를 제외한 다른 하수처리시설은 아예 없다. 
> ###
> <img width="335" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/1aa4df09-cae5-47c6-a14a-633f4c7ea8c1">
> <img width="338" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/e255a519-5213-4c66-b50d-7e5a79c1b61c">
>
> 또한 앞서 첨부해 둔 `생활안전지도 - 세종특별자치시 침수흔적도(~2017)` 를 참고하여 하수처리시설 현황과 종합해 보면 조치원읍 또한 하수처리시설이 하나밖에 없다. 
> ###
> <img width="290" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/67cb071d-0685-49f8-98d1-01bb64ef49db">
>
> <img width="241" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/b0e43e63-89cd-45af-b40d-c8d2b6d0b852">
>
> <img width="300" alt="image" src="https://github.com/CharmStrange/Project/assets/105769152/d1d32b8b-4640-45bb-9db1-0f2360a72742">
>  
> ```
> [대표적 침수취약지역 수치해석 결과]
> 세종시 조치원읍 일대의 경우 체계적인 관거정비사업이 실시되지 못해 집중호우시 침수피해가 발생하고 있음.
> XP-SWMM을 활용하여 확률강우량과 방재성능목표 기반의 수치해석 결과 비교적 작은 빈도의 강우 발생에도 침수위험이 높게 나타났으며, 빈도의 크기 증가에 비례하여 강우 총량이 증가하여 도시침수 피해가 발생할 것으로 판단됨.
> ...
> 조치원 지하차도와 같은 상습침수 구역에 대한 집중적인 관리가 필요함.
> 해당 지역들의 경우 현재 낮은 빈도의 호우발생에도 배수능력 부족으로 내수침수 발생 가능성이 높은 것으로 분석되었음.
> ...
> ```
> [세종시 시민안전 물관리를 위한 정책 수립 및 이행 방안 中](https://github.com/CharmStrange/Project/blob/main/Python/%EC%A0%9C4%ED%9A%8C%20%EC%84%B8%EC%A2%85%ED%8A%B9%EB%B3%84%EC%9E%90%EC%B9%98%EC%8B%9C%20%EB%B9%85%EB%8D%B0%EC%9D%B4%ED%84%B0%20%EB%B6%84%EC%84%9D%20%EC%95%84%EC%9D%B4%EB%94%94%EC%96%B4%20%EA%B3%B5%EB%AA%A8%EC%A0%84/%EB%8B%A4%EB%A5%B8%20%EB%8D%B0%EC%9D%B4%ED%84%B0/202205131112582602.pdf) 
> 
---
> # #3. 파악한 문제점을 바탕으로 아이디어의 실현 가능성 및 기대 효과를 판단 <a name="3"></a>
> > ### **아이디어 제시에 앞서 선행되어야 할 필요조건은?**
> > #### - *세종특별자치시 내 침수 위험 지역 하수처리시설 증대와 성능 개선*
> > #### - *체계적인 데이터 저장 / 관리 시스템의 구축*
> > #### - *지역 주민, 상인, 근무자 등의 지속적인 관심*
> 
>  ### **My Idea** : [ 지역별로 침수 위험 정도에 따라 수위 측정 기준면을 설정하여, *측정 센서*와 *예측*을 통해 침수 피해를 최소화할 수 있도록, 침수 가능성이 높은 지역에 대해 해당 지역의 주민, 상인, 근무자 등의 사람들이 미리 알 수 있도록 예보 또는 경보를 해 주는 시스템을 구축하기 ]
>
> > ***수위 측정 기준면 및 센서 설치***(인프라스트럭쳐 개선의 일환) :
> > **실현 가능성** : 수위 측정 기준면은 지역별로 다르게 설정되어야 하며, 이를 기반으로 수위 측정 센서를 설치해야 한다. 이는 그곳의 지형과 하수처리시설 여부를 고려해 결정되어야 한다.
> >
> > **데이터 확보 방안** : 설치된 센서를 통해 데이터베이스에 지속적인  데이터 수집이 이루어져야 한다. 이를 위해 원격 모니터링 및 데이터 로깅 장치를 활용할 수 있고, 공공 기관, 연구 기관 또는 민간 협력 업체와 협력하여 확보할 수 있다. 
>
> > ***수위 예측 및 경보 시스템 구축***(빅데이터 활용) :
> > **실현 가능성** : 데이터를 수집하여 분석하고 인사이트를 찾아내 침수 피해 예측 모델을 개발해야 한다. 이미 다른 곳에서 제공되고 있는 기상 데이터, 지형 정보, 강우량 등도 활용하여 예측하는 모델에 활용할 수 있다. 이런 모델은 머신러닝 및 인공지능 기술을 활용하여 개발할 수 있다(ex : XGBoost). 사용되는 모델은 완벽하지 않기 때문에 유지 및 보수, 업데이트가 필수적이다.
> >
> > **데이터 확보 방안** : 모델을 구축하기 위해 데이터베이스에 저장된 정보를 충분히 활용해야 한다. 또한 추가적인 외부 데이터로 공공 기관, 기상청, 지도 데이터 제공 업체 및 관련된 연구 기관에 요청하여 사용할 수 있다. 
>
> [저장된 데이터를 기반으로 침수 예측을 수행하는 소스 코드](project_pseudocode.py)
> 
> [아이디어를 구현한 소스 코드](project_pseudocode.c) : 위 소스 코드의 결과를 받아야 함
> 
> *모두 *Pseudo Code*
---
> # #결론 <a name="결론"></a>
> 강우량, 수해 데이터 등을 지속적으로 수집, 관리하여 수해 예측 시스템과 예보, 경보 시스템을 구축한다면, 상황에 미리 준비되어 있을 것이므로, 자원을 효율적으로 사용하고 피해를 최소화 할 수 있으며, 피해가 있더라도 복구 비용을 절감할 수 있을 것이다. 더불어 시민들은 불편함이 덜해질 것이며 도시의 안전성 증대로 인한 지역 부동산 가치의 상승 또한 기대할 수 있을 것이다.
---
> # #후기 <a name="후기"></a>
> 데이터를 최대한 활용하여 어떻게 하면 세종특별자치시에 도움이 될 것인지, 시민들의 관심을 받을 것인지를 생각하여 아이디어를 구현해 보았다. 개인적으로 아주 좋은 경험이었다.
> 
> 하지만 제공되거나 찾을 수 있는 데이터가 한정적이라 조금 아쉬웠다. 게다가 그렇게 찾은 데이터 중에서도 누락된 값이 많았기 때문에 데이터 수집, 처리 쪽에서 힘들었다. 또한 그렇게 모은 데이터로 객관적인 지표를 도출해 내는 과정이 쉽지 않았다. 
>
> 프로젝트를 80% 진행하고 나서 2021년 수상작에 이 주제와 같은 작품이 있었다는 것을 알았고 그 때문에 살짝 멘붕. 시작부터 알았으면 이 주제 말고 다른 주제로 했을텐데... 하지만 마무리는 열심히 했다. 한편으로는 시민들에게 있어 침수에 의한 피해와 예방 대책은 굉장히 직접적이기 때문에 내 아이디어 자체는 괜찮다고 생각된다.
---
