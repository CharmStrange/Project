#ifndef SmartFarmCrops_H
# define SmartFarmCrops_H

# include <iostream>
# include <vector>
# include <string>
using namespace std;

enum class CropStatus { Planted, Growing, ReadyForHarvest, Damaged };

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
};

class ControlCenterUnit {
public:
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
};

class Farm {
private:
    vector<Crop> crops;

public:
    Farm() {}

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
    
    ~Farm() {}
};

#endif
