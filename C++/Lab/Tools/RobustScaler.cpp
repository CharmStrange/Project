#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class RobustScaler {
private:
    vector<double> centering_factors;
    vector<double> scaling_factors;

public:
    RobustScaler() {}

    void fit(const vector<vector<double>>& data) {
        int num_features = data[0].size();
        centering_factors.resize(num_features, 0.0);
        scaling_factors.resize(num_features, 1.0);

        for (int i = 0; i < num_features; ++i) {
            vector<double> feature_values;
            for (const auto& row : data) {
                feature_values.push_back(row[i]);
            }
            sort(feature_values.begin(), feature_values.end());

            int mid_idx = feature_values.size() / 2;
            double median = feature_values[mid_idx];

            centering_factors[i] = median;
            scaling_factors[i] = *max_element(feature_values.begin(), feature_values.end()) -
                                 *min_element(feature_values.begin(), feature_values.end());
        }
    }

    vector<vector<double>> transform(const vector<vector<double>>& data) const {
        vector<vector<double>> scaled_data;

        for (const auto& row : data) {
            vector<double> scaled_row(row.size());
            for (int i = 0; i < row.size(); ++i) {
                scaled_row[i] = (row[i] - centering_factors[i]) / scaling_factors[i];
            }
            scaled_data.push_back(scaled_row);
        }

        return scaled_data;
    }
};

int main() {
    vector<std::vector<double>> PackData = {
        // 여기에 데이터 삽입
    };

    RobustScaler scaler;
    scaler.fit(PackData);
    vector<vector<double>> scaled_data = scaler.transform(PackData);

    for (const auto& row : scaled_data) {
        for (double val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
