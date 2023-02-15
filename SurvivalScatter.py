# 시뮬레이션 시각화를 위해 matplotlib 이 필요하니 불러오고 데이터 구조를 살짝 변경
import matplotlib.pyplot as plt
#np.random.seed(0) #고정값

x = np.random.rand(100)
y = np.random.rand(100)

plt.scatter(x, y)
plt.show()