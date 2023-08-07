#ifndef SmartFarmCrops_H
# define SmartFarmCrops_H

# include <iostream>
# include <vector>
# include <string>
using namespace std;

enum class CropStatus { Planted, Growing, ReadyForHarvest, Damaged };

typedef struct{
    string CROP_NAME;
    string CROP_CATEGORY;
    short CROP_LEVEL;
    short CROP_TIMES;
    float CROP_PRICE;
    bool CROP_DONE;
    short CROP_ID;
}CROPS;

vector<CROPS> CROP_LIST = {
    {"Wheat", "Cereals", 1, 10, 27.3, false, 0},
    {"Rice", "Cereals", 1, 12, 25.5, false, 1},
    {"Corn", "Cereals", 1, 9, 20.2, false, 2},
    {"Barley", "Cereals", 2, 11, 23.7, false, 3},
    {"Millet", "Cereals", 2, 8, 22.1, false, 4},
    {"Sorghum", "Cereals", 2, 9, 21.8, false, 5},
    {"Millet", "Cereals", 3, 10, 19.5, false, 6},
    {"Soybean", "Legumes", 1, 11, 30.8, false, 7},
    {"Azuki Bean", "Legumes", 3, 9, 32.1, false, 8},
    {"Mung Bean", "Legumes", 3, 10, 31.2, false, 9},
    {"Adzuki Bean", "Legumes", 4, 12, 28.9, false, 10},
    {"Cowpea", "Legumes", 2, 8, 29.7, false, 11},
    {"Potato", "Root Vegetables", 1, 15, 16.5, false, 12},
    {"Sweet Potato", "Root Vegetables", 2, 14, 18.9, false, 13},
    {"Cabbage", "Vegetables", 2, 11, 14.3, false, 14},
    {"Brussels Sprouts", "Vegetables", 4, 16, 15.8, false, 15},
    {"Spinach", "Vegetables", 3, 13, 13.2, false, 16},
    {"Lettuce", "Vegetables", 2, 12, 14.7, false, 17},
    {"Watermelon", "Vegetables", 5, 18, 12.5, false, 18},
    {"Cantaloupe", "Vegetables", 5, 16, 11.9, false, 19},
    {"Cucumber", "Vegetables", 4, 14, 13.8, false, 20},
    {"Pumpkin", "Vegetables", 3, 13, 15.2, false, 21},
    {"Tomato", "Vegetables", 2, 11, 17.1, false, 22},
    {"Strawberry", "Vegetables", 3, 13, 19.8, false, 23},
    {"Eggplant", "Vegetables", 4, 16, 16.4, false, 24},
    {"Radish", "Vegetables", 1, 9, 12.7, false, 25},
    {"Carrot", "Vegetables", 1, 10, 13.9, false, 26},
    {"Burdock", "Vegetables", 2, 8, 11.5, false, 27},
    {"Taro", "Vegetables", 2, 11, 14.1, false, 28},
    {"Hot Pepper", "Vegetables", 3, 12, 15.7, false, 29},
    {"Garlic", "Vegetables", 1, 9, 17.3, false, 30},
    {"Green Onion", "Vegetables", 1, 8, 12.3, false, 31},
    {"Onion", "Vegetables", 1, 10, 14.6, false, 32},
    {"Ginger", "Vegetables", 4, 15, 13.5, false, 33},
    {"Apple", "Fruits", 2, 20, 30.5, false, 34},
    {"Pear", "Fruits", 2, 18, 28.9, false, 35},
    {"Peach", "Fruits", 4, 22, 27.8, false, 36},
    {"Grape", "Fruits", 2, 19, 29.7, false, 37},
    {"Persimmon", "Fruits", 5, 25, 28.2, false, 38},
    {"Kumquat", "Fruits", 5, 24, 31.4, false, 39},
    {"Walnut", "Fruits", 4, 21, 27.1, false, 40},
    {"Date", "Fruits", 3, 17, 24.5, false, 41},
    {"Jujube", "Fruits", 2, 19, 26.9, false, 42},
    {"Pine Nut", "Fruits", 2, 16, 23.8, false, 43},
    {"Acorn", "Fruits", 3, 14, 22.5, false, 44},
    {"Hazelnut", "Fruits", 2, 17, 25.3, false, 45},
    {"Chestnut", "Fruits", 2, 26, 27.6, false, 46},
    {"Korean Raspberry", "Fruits", 5, 21, 29.1, false, 47},
    {"Cotton", "Special Crops", 4, 28, 40.3, false, 48},
    {"Safflower", "Special Crops", 2, 16, 38.9, false, 49},
    {"Sesame", "Special Crops", 1, 12, 35.6, false, 50},
    {"Perilla", "Special Crops", 2, 14, 39.8, false, 51},
    {"Peanut", "Special Crops", 1, 11, 42.1, false, 52},
    {"Hops", "Special Crops", 1, 9, 44.2, false, 53},
    {"Chinese Wolfberry", "Medicinal Plants", 6, 30, 50.2, false, 54},
    {"Ginkgo", "Medicinal Plants", 6, 32, 53.1, false, 55},
    {"Danggui", "Medicinal Plants", 6, 29, 49.8, false, 56},
    {"Yam", "Medicinal Plants", 3, 27, 47.5, false, 57},
    {"Astragalus", "Medicinal Plants", 6, 31, 48.9, false, 58},
    {"Coptis", "Medicinal Plants", 6, 28, 52.3, false, 59},
    {"Rehmannia", "Medicinal Plants", 6, 25, 45.6, false, 60},
    {"Liquorice", "Medicinal Plants", 6, 23, 43.2, false, 61},
    {"Oriental Raisin Tree", "Medicinal Plants", 6, 26, 46.7, false, 62},
    {"Ogapi", "Medicinal Plants", 6, 21, 41.9, false, 63},
    {"Cnidium", "Medicinal Plants", 6, 24, 44.8, false, 64},
    {"Indian Buead", "Medicinal Plants", 6, 27, 47.3, false, 65},
    {"Chrysanthemum", "Flowers", 4, 16, 36.8, false, 66},
    {"Rose", "Flowers", 1, 13, 35.2, false, 67},
    {"Mist Flower", "Flowers", 2, 14, 38.7, false, 68},
    {"Shiitake Mushroom", "Mushrooms", 3, 20, 42.5, false, 69},
    {"Enoki Mushroom", "Mushrooms", 3, 18, 40.9, false, 70},
    {"King Oyster Mushroom", "Mushrooms", 5, 23, 43.7, false, 71},
    {"Oyster Mushroom", "Mushrooms", 4, 21, 41.4, false, 72},
};

class Crop {
public:
    string name;
    CropStatus status;
    int growthDays;

    Crop(string name, int growthDays) : name(name), status(CropStatus::Planted), growthDays(growthDays) {}

    void water() {
        if (status == CropStatus::Growing) {
            cout << name << " is watered.\n";
        } else {
            cout << name << " is not ready for watering.\n";
        }
    }

    void harvest() {
        if (status == CropStatus::ReadyForHarvest) {
            cout << "Harvesting " << name << ".\n";
            status = CropStatus::Planted;
        } else {
            cout << name << " is not ready for harvest yet.\n";
        }
    }

    Crop() {}
};

class ControlCenterUnit {
public:
    ControlCenterUnit() {}

    void checkCropStatus(const Crop& crop) {
        cout << crop.name << " - ";
        switch (crop.status) {
            case CropStatus::Planted:
                cout << "Planted";
                break;
            case CropStatus::Growing:
                cout << "Growing (" << crop.growthDays << " days left)";
                break;
            case CropStatus::ReadyForHarvest:
                cout << "Ready for Harvest";
                break;
            case CropStatus::Damaged:
                cout << "Damaged";
        }
        cout << endl;
    }

    void waterCrop(Crop& crop) {
        if (crop.status == CropStatus::Growing) {
            crop.water();
        } else {
            cout << "Cannot water " << crop.name << " at the moment.\n";
        }
    }

    ~ControlCenterUnit() {}
};

class FarmControl {
private:
    vector<Crop> crops;

public:
    FarmControl() {}

    void plantCrop(Crop crop) {
        crops.push_back(crop);
        cout << "Planted " << crop.name << " on the farm.\n";
    }

    void advanceTime() {
        for (auto& crop : crops) {
            if (crop.status == CropStatus::Planted) {
                crop.status = CropStatus::Growing;
                cout << crop.name << " is now growing.\n";
            } else if (crop.status == CropStatus::Growing) {
                crop.growthDays--;
                if (crop.growthDays == 0) {
                    crop.status = CropStatus::ReadyForHarvest;
                    cout << crop.name << " is now ready for harvest.\n";
                }
            }
        }
    }

    void displayCrops() {
        cout << "Crops on the farm:\n";
        for (const auto& crop : crops) {
            ControlCenterUnit ccu;
            ccu.checkCropStatus(crop);
        }
    }

    void waterCrops() {
        ControlCenterUnit ccu;
        for (auto& crop : crops) {
            ccu.waterCrop(crop);
        }
    }

    void plowup() {
        if (crops.empty()) {
            cout << "Cannot Plow Up! There are no crops to plow.\n";
            return;
        }

        string cropNameToRemove;
        cout << "Enter the name of the crop you want to plow up: ";
        cin >> cropNameToRemove;

        auto it = std::remove_if(crops.begin(), crops.end(),
                                 [cropNameToRemove](const Crop& crop) {
                                     return crop.name == cropNameToRemove;
                                 });

        if (it != crops.end()) {
            cout << "Plowed up the selected crop: " << it->name << "\n";
            crops.erase(it, crops.end());
        } else {
            cout << "Crop with name " << cropNameToRemove << " not found.\n";
        }
    }

    ~FarmControl() {}
};

#endif
