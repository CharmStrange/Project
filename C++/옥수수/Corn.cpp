#include <iostream>
#include <vector>
using namespace std;

enum class Corn_Status {Bad, Soso, Good};

class Corn{
    
    Corn_Status CS;
    vector<short> Corn_Kernel;
    vector<short>::iterator Corn_Kernel_Finder;
    
public:
    Corn() : CS(Corn_Status::Soso) {
        cout << "Hello! I'm a Corn!! My name is " << this << endl;
    }
    
    void Nutrient_Supply() {}
    
    void Take_Kernel() {}
    
    ~Corn() {}
    
};

int main() {
    Corn corn1;
    Corn corn2;
}
