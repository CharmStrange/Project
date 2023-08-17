import requests

# 다운로드할 파일의 URL
url = 'https://example.com/image.jpg'

# 요청 보내고 데이터 다운로드
response = requests.get(url)

# 응답 상태코드 확인 (200이면 성공)
if response.status_code == 200:
    # 파일명 추출
    filename = url.split("/")[-1]
    
    # 파일 저장 경로 설정
    save_path = f'./{filename}'
    
    # 파일 저장
    with open(save_path, 'wb') as f:
        f.write(response.content)
    print(f'{filename} 다운로드 완료')
else:
    print('다운로드 실패')
