#include <iostream>
using namespace std;

#include "FARM.H"
#include "SmartFarmCrops.H"

int main(){
    
    Farm FARM1;
    FARM_INDEX.push_back(FARM1);

    FarmControl farm;

    Crop wheat("Wheat", 5);
    crop_storage.push_back(wheat);

    Crop corn("Corn", 4);
    crop_storage.push_back(corn);

    Crop tomato("Tomato", 3);
    crop_storage.push_back(tomato);

    farm.plantCrop(wheat);
    farm.plantCrop(corn);
    farm.plantCrop(tomato);

    farm.advanceTime();
    farm.advanceTime();
    farm.advanceTime();

    farm.displayCrops();

    // Simulate watering
    farm.waterCrops();
    
}
