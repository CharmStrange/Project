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
    {"Wheat", "Cereals", 1, 10, 27.3, false},
    {"Rice", "Cereals", 1, 12, 25.5, false},
    {"Corn", "Cereals", 1, 9, 20.2, false},
    {"Barley", "Cereals", 2, 11, 23.7, false},
    {"Millet", "Cereals", 2, 8, 22.1, false},
    {"Sorghum", "Cereals", 2, 9, 21.8, false},
    {"Millet", "Cereals", 3, 10, 19.5, false},
    {"Soybean", "Legumes", 1, 11, 30.8, false},
    {"Azuki Bean", "Legumes", 3, 9, 32.1, false},
    {"Mung Bean", "Legumes", 3, 10, 31.2, false},
    {"Adzuki Bean", "Legumes", 4, 12, 28.9, false},
    {"Cowpea", "Legumes", 2, 8, 29.7, false},
    {"Potato", "Root Vegetables", 1, 15, 16.5, false},
    {"Sweet Potato", "Root Vegetables", 2, 14, 18.9, false},
    {"Cabbage", "Vegetables", 2, 11, 14.3, false},
    {"Brussels Sprouts", "Vegetables", 4, 16, 15.8, false},
    {"Spinach", "Vegetables", 3, 13, 13.2, false},
    {"Lettuce", "Vegetables", 2, 12, 14.7, false},
    {"Watermelon", "Vegetables", 5, 18, 12.5, false},
    {"Cantaloupe", "Vegetables", 5, 16, 11.9, false},
    {"Cucumber", "Vegetables", 4, 14, 13.8, false},
    {"Pumpkin", "Vegetables", 3, 13, 15.2, false},
    {"Tomato", "Vegetables", 2, 11, 17.1, false},
    {"Strawberry", "Vegetables", 3, 13, 19.8, false},
    {"Eggplant", "Vegetables", 4, 16, 16.4, false},
    {"Radish", "Vegetables", 1, 9, 12.7, false},
    {"Carrot", "Vegetables", 1, 10, 13.9, false},
    {"Burdock", "Vegetables", 2, 8, 11.5, false},
    {"Taro", "Vegetables", 2, 11, 14.1, false},
    {"Hot Pepper", "Vegetables", 3, 12, 15.7, false},
    {"Garlic", "Vegetables", 1, 9, 17.3, false},
    {"Green Onion", "Vegetables", 1, 8, 12.3, false},
    {"Onion", "Vegetables", 1, 10, 14.6, false},
    {"Ginger", "Vegetables", 4, 15, 13.5, false},
    {"Apple", "Fruits", 2, 20, 30.5, false},
    {"Pear", "Fruits", 2, 18, 28.9, false},
    {"Peach", "Fruits", 4, 22, 27.8, false},
    {"Grape", "Fruits", 2, 19, 29.7, false},
    {"Persimmon", "Fruits", 5, 25, 28.2, false},
    {"Kumquat", "Fruits", 5, 24, 31.4, false},
    {"Walnut", "Fruits", 4, 21, 27.1, false},
    {"Date", "Fruits", 3, 17, 24.5, false},
    {"Jujube", "Fruits", 2, 19, 26.9, false},
    {"Pine Nut", "Fruits", 2, 16, 23.8, false},
    {"Acorn", "Fruits", 3, 14, 22.5, false},
    {"Hazelnut", "Fruits", 2, 17, 25.3, false},
    {"Chestnut", "Fruits", 2, 26, 27.6, false},
    {"Korean Raspberry", "Fruits", 5, 21, 29.1, false},
    {"Cotton", "Special Crops", 4, 28, 40.3, false},
    {"Safflower", "Special Crops", 2, 16, 38.9, false},
    {"Sesame", "Special Crops", 1, 12, 35.6, false},
    {"Perilla", "Special Crops", 2, 14, 39.8, false},
    {"Peanut", "Special Crops", 1, 11, 42.1, false},
    {"Hops", "Special Crops", 1, 9, 44.2, false},
    {"Chinese Wolfberry", "Medicinal Plants", 6, 30, 50.2, false},
    {"Ginkgo", "Medicinal Plants", 6, 32, 53.1, false},
    {"Danggui", "Medicinal Plants", 6, 29, 49.8, false},
    {"Yam", "Medicinal Plants", 3, 27, 47.5, false},
    {"Astragalus", "Medicinal Plants", 6, 31, 48.9, false},
    {"Coptis", "Medicinal Plants", 6, 28, 52.3, false},
    {"Rehmannia", "Medicinal Plants", 6, 25, 45.6, false},
    {"Liquorice", "Medicinal Plants", 6, 23, 43.2, false},
    {"Oriental Raisin Tree", "Medicinal Plants", 6, 26, 46.7, false},
    {"Ogapi", "Medicinal Plants", 6, 21, 41.9, false},
    {"Cnidium", "Medicinal Plants", 6, 24, 44.8, false},
    {"Indian Buead", "Medicinal Plants", 6, 27, 47.3, false},
    {"Chrysanthemum", "Flowers", 4, 16, 36.8, false},
    {"Rose", "Flowers", 1, 13, 35.2, false},
    {"Mist Flower", "Flowers", 2, 14, 38.7, false},
    {"Shiitake Mushroom", "Mushrooms", 3, 20, 42.5, false},
    {"Enoki Mushroom", "Mushrooms", 3, 18, 40.9, false},
    {"King Oyster Mushroom", "Mushrooms", 5, 23, 43.7, false},
    {"Oyster Mushroom", "Mushrooms", 4, 21, 41.4, false},
};

vector<int> Farm_Index;
vector<int>::iterator Farm_Index_Iterator;

class Farm{

    Farm() {}

    ~Farm() {}
};

int main(){

}
