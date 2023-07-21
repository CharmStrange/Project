#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct{
    string CROP_NAME;
    string CROP_CATEGORY;
    short CROP_LEVEL;
    short CROP_STATUS;
    float CROP_PRICE;
    bool CROP_DONE;
}CROPS;

vector<CROPS> CROP_LIST = {
    {"Wheat", "Cereals", 1, 3, 27.3, false},
    {"Rice", "Cereals", 1, 3, 25.5, false},
    {"Corn", "Cereals", 1, 3, 20.2, false},
    {"Barley", "Cereals", 1, 3, 23.7, false},
    {"Millet", "Cereals", 1, 3, 22.1, false},
    {"Sorghum", "Cereals", 1, 3, 21.8, false},
    {"Millet", "Cereals", 1, 3, 19.5, false},
    {"Soybean", "Legumes", 1, 3, 30.8, false},
    {"Azuki Bean", "Legumes", 1, 3, 32.1, false},
    {"Mung Bean", "Legumes", 1, 3, 31.2, false},
    {"Adzuki Bean", "Legumes", 1, 3, 28.9, false},
    {"Cowpea", "Legumes", 1, 3, 29.7, false},
    {"Potato", "Root Vegetables", 1, 3, 16.5, false},
    {"Sweet Potato", "Root Vegetables", 1, 3, 18.9, false},
    {"Cabbage", "Vegetables", 1, 3, 14.3, false},
    {"Brussels Sprouts", "Vegetables", 1, 3, 15.8, false},
    {"Spinach", "Vegetables", 1, 3, 13.2, false},
    {"Lettuce", "Vegetables", 1, 3, 14.7, false},
    {"Watermelon", "Vegetables", 1, 3, 12.5, false},
    {"Cantaloupe", "Vegetables", 1, 3, 11.9, false},
    {"Cucumber", "Vegetables", 1, 3, 13.8, false},
    {"Pumpkin", "Vegetables", 1, 3, 15.2, false},
    {"Tomato", "Vegetables", 1, 3, 17.1, false},
    {"Strawberry", "Vegetables", 1, 3, 19.8, false},
    {"Eggplant", "Vegetables", 1, 3, 16.4, false},
    {"Radish", "Vegetables", 1, 3, 12.7, false},
    {"Carrot", "Vegetables", 1, 3, 13.9, false},
    {"Burdock", "Vegetables", 1, 3, 11.5, false},
    {"Taro", "Vegetables", 1, 3, 14.1, false},
    {"Hot Pepper", "Vegetables", 1, 3, 15.7, false},
    {"Garlic", "Vegetables", 1, 3, 17.3, false},
    {"Green Onion", "Vegetables", 1, 3, 12.3, false},
    {"Onion", "Vegetables", 1, 3, 14.6, false},
    {"Ginger", "Vegetables", 1, 3, 13.5, false},
    {"Apple", "Fruits", 1, 3, 30.5, false},
    {"Pear", "Fruits", 1, 3, 28.9, false},
    {"Peach", "Fruits", 1, 3, 27.8, false},
    {"Grape", "Fruits", 1, 3, 29.7, false},
    {"Persimmon", "Fruits", 1, 3, 28.2, false},
    {"Kumquat", "Fruits", 1, 3, 31.4, false},
    {"Chestnut", "Fruits", 1, 3, 25.6, false},
    {"Walnut", "Fruits", 1, 3, 27.1, false},
    {"Date", "Fruits", 1, 3, 24.5, false},
    {"Jujube", "Fruits", 1, 3, 26.9, false},
    {"Pine Nut", "Fruits", 1, 3, 23.8, false},
    {"Acorn", "Fruits", 1, 3, 22.5, false},
    {"Hazelnut", "Fruits", 1, 3, 25.3, false},
    {"Chestnut", "Fruits", 1, 3, 27.6, false},
    {"Korean Raspberry", "Fruits", 1, 3, 29.1, false},
    {"Cotton", "Special Crops", 1, 3, 40.3, false},
    {"Safflower", "Special Crops", 1, 3, 38.9, false},
    {"Sesame", "Special Crops", 1, 3, 35.6, false},
    {"Perilla", "Special Crops", 1, 3, 39.8, false},
    {"Peanut", "Special Crops", 1, 3, 42.1, false},
    {"Hops", "Special Crops", 1, 3, 44.2, false},
    {"Chinese Wolfberry", "Medicinal Plants", 1, 3, 50.2, false},
    {"Ginkgo", "Medicinal Plants", 1, 3, 53.1, false},
    {"Danggui", "Medicinal Plants", 1, 3, 49.8, false},
    {"Yam", "Medicinal Plants", 1, 3, 47.5, false},
    {"Astragalus", "Medicinal Plants", 1, 3, 48.9, false},
    {"Coptis", "Medicinal Plants", 1, 3, 52.3, false},
    {"Rehmannia", "Medicinal Plants", 1, 3, 45.6, false},
    {"Liquorice", "Medicinal Plants", 1, 3, 43.2, false},
    {"Oriental Raisin Tree", "Medicinal Plants", 1, 3, 46.7, false},
    {"Ogapi", "Medicinal Plants", 1, 3, 41.9, false},
    {"Cnidium", "Medicinal Plants", 1, 3, 44.8, false},
    {"Indian Buead", "Medicinal Plants", 1, 3, 47.3, false},
    {"Chrysanthemum", "Flowers", 1, 3, 36.8, false},
    {"Rose", "Flowers", 1, 3, 35.2, false},
    {"Mist Flower", "Flowers", 1, 3, 38.7, false},
    {"Shiitake Mushroom", "Mushrooms", 1, 3, 42.5, false},
    {"Enoki Mushroom", "Mushrooms", 1, 3, 40.9, false},
    {"King Oyster Mushroom", "Mushrooms", 1, 3, 43.7, false},
    {"Oyster Mushroom", "Mushrooms", 1, 3, 41.4, false},
};

vector<int> Farm_Index;
vector<int>::iterator Farm_Index_Iterator;

class Farm{

    Farm() {}

    ~Farm() {}
};

int main(){

}
