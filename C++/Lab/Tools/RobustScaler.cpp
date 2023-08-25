#include <iostream>
#include <vector>
#include <algorithm>

class RobustScaler {
private:
    std::vector<double> centering_factors;
    std::vector<double> scaling_factors;

public:
    RobustScaler() {}

    void fit(const std::vector<std::vector<double>>& data) {
        int num_features = data[0].size();
        centering_factors.resize(num_features, 0.0);
        scaling_factors.resize(num_features, 1.0);

        for (int i = 0; i < num_features; ++i) {
            std::vector<double> feature_values;
            for (const auto& row : data) {
                feature_values.push_back(row[i]);
            }
            std::sort(feature_values.begin(), feature_values.end());

            int mid_idx = feature_values.size() / 2;
            double median = feature_values[mid_idx];

            centering_factors[i] = median;
            scaling_factors[i] = *std::max_element(feature_values.begin(), feature_values.end()) -
                                 *std::min_element(feature_values.begin(), feature_values.end());
        }
    }

    std::vector<std::vector<double>> transform(const std::vector<std::vector<double>>& data) const {
        std::vector<std::vector<double>> scaled_data;

        for (const auto& row : data) {
            std::vector<double> scaled_row(row.size());
            for (int i = 0; i < row.size(); ++i) {
                scaled_row[i] = (row[i] - centering_factors[i]) / scaling_factors[i];
            }
            scaled_data.push_back(scaled_row);
        }

        return scaled_data;
    }
};

int main() {
    std::vector<std::vector<double>> data = {
        // 여기에 데이터 삽입
    };

    RobustScaler scaler;
    scaler.fit(data);
    std::vector<std::vector<double>> scaled_data = scaler.transform(data);

    for (const auto& row : scaled_data) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
