#ifndef FARM_H
# define FARM_H

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
using namespace std;


typedef struct{
    string CROP_NAME;
    short CROP_COUNT;
    short CROP_ID;
}STORAGE;


class Farm;
vector<Farm> FARM_INDEX;
vector<Farm>::iterator FARM_INDEX_ITERATOR;


class Town;
vector<Town> TOWN_INDEX;
vector<Town>::iterator TOWN_INDEX_ITERATOR;


class Factory;
vector<Factory> FACTORY_INDEX;
vector<Factory>::iterator FACTORY_INDEX_ITERATOR;


class Farm{
private:

    vector<STORAGE> Storage;
    short FARM_ID;
    
public:

    static short FARM_ID_P_;

    Farm() : FARM_ID(FARM_ID_P_++) {
        FARM_INDEX.push_back(*this);
    }
    
    short getFarmID() const {
        return FARM_ID;
    }

    ~Farm() {}
};


class Town{
private:

    short TOWN_ID;
    
public:

    static short TOWN_ID_P_;

    Town() : TOWN_ID(TOWN_ID_P_++) {
        TOWN_INDEX.push_back(*this);
    }
    
    short getTownID() const {
        return TOWN_ID;
    }
    
    ~Town() {}
};


class Factory{
private:

    short FACTORY_ID;
    
public:

    static short FACTORY_ID_P_;

    Factory() : FACTORY_ID(FACTORY_ID_P_++) {
        FACTORY_INDEX.push_back(*this);
    }
    
    short getFactoryID() const {
        return FACTORY_ID;
    }
    
    ~Factory() {}
    
};

short Farm::FARM_ID_P_ = 1;
short Town::TOWN_ID_P_ = 1;
short Factory::FACTORY_ID_P_ = 1;

#endif
