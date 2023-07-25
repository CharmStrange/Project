#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class StandardScaler {
private:
    vector<double> mean;
    vector<double> std_dev;

public:

    StandardScaler() {}

    // 데이터를 적합시켜 평균과 표준 편차를 계산하는 함수
    void fit(const vector<vector<double>>& data) {
        if (data.empty() || data[0].empty()) {
            return;
        }

        int num_features = data[0].size();
        mean.resize(num_features, 0.0);
        std_dev.resize(num_features, 0.0);

        // 각 특성별 평균 계산
        for (const auto& row : data) {
            for (int i = 0; i < num_features; ++i) {
                mean[i] += row[i];
            }
        }

        int num_samples = data.size();
        for (int i = 0; i < num_features; ++i) {
            mean[i] /= num_samples;
        }

        // 각 특성별 표준 편차 계산
        for (const auto& row : data) {
            for (int i = 0; i < num_features; ++i) {
                double diff = row[i] - mean[i];
                std_dev[i] += diff * diff;
            }
        }

        for (int i = 0; i < num_features; ++i) {
            std_dev[i] = sqrt(std_dev[i] / num_samples);
        }
    }

    // 평균과 표준 편차를 사용하여 데이터를 변환하는 함수
    vector<vector<double>> transform(const vector<vector<double>>& data) const {
        vector<vector<double>> transformed_data;

        if (data.empty() || data[0].empty()) {
            return transformed_data;
        }

        int num_samples = data.size();
        int num_features = data[0].size();
        transformed_data.resize(num_samples, vector<double>(num_features, 0.0));

        for (int i = 0; i < num_samples; ++i) {
            for (int j = 0; j < num_features; ++j) {
                transformed_data[i][j] = (data[i][j] - mean[j]) / std_dev[j];
            }
        }

        return transformed_data;
    }
};

int main() {
    vector<vector<double>> PackData = {
        // 여기에 데이터 삽입 
    };

    // StandardScaler 객체 생성 후 데이터를 적합
    StandardScaler scaler;
    scaler.fit(PackData);

    // 평균과 표준 편차를 사용하여 데이터를 변환
    vector<vector<double>> scaled_data = scaler.transform(PackData);

    // 변환된 데이터 출력
    for (const auto& row : scaled_data) {
        for (const auto& value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
