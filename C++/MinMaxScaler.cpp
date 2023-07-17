#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

// MinMaxScaler FUNCTION
vector<vector<double>> minMaxScaling(const vector<vector<int>>& data) {
    vector<vector<double>> scaledData(data.size(), vector<double>(data[0].size()));

    // 각 열에 대해 최솟값과 최댓값을 찾음
    vector<int> minValues(data[0].size(), INT_MAX);
    vector<int> maxValues(data[0].size(), INT_MIN);
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            minValues[i] = min(minValues[i], row[i]);
            maxValues[i] = max(maxValues[i], row[i]);
        }
    }

    // MinMaxScaling
    for (size_t i = 0; i < data.size(); ++i) {
        for (size_t j = 0; j < data[0].size(); ++j) {
            scaledData[i][j] = static_cast<double>(data[i][j] - minValues[j]) / (maxValues[j] - minValues[j]);
        }
    }

    return scaledData;
}

int main() {
    vector<vector<int>> PackData = {
      // 여기에 데이터 삽입  
    };

    vector<vector<double>> scaledData = minMaxScaling(PackData);

    // 데이터 출력
    for (const auto& row : scaledData) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
