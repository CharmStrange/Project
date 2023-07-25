#include <iostream>
using namespace std;

#include FARM.h

int main(){
    
    Farm farm1;
    Farm farm2;
    
    Town town1;
    Town town2;
    
    Factory factory1;
    Factory factory2;
    
    cout << "Farm ID: " << farm1.getFarmID() << endl;
    cout << "Farm ID: " << farm2.getFarmID() << endl;
    
    cout << "Town ID: " << town1.getTownID() << endl;
    cout << "Town ID: " << town2.getTownID() << endl;
    
    cout << "Factory ID: " << factory1.getFactoryID() << endl;
    cout << "Factory ID: " << factory2.getFactoryID() << endl;
}
