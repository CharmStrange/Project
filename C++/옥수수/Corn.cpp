#include <iostream>
#include <vector>
using namespace std;

enum class Corn_Status {Bad, Soso, Good};

class Corn{
    
    Corn_Status CS;
    vector<short> Corn_Kernel;
    vector<short>::iterator Corn_Kernel_Finder;
    unsigned short Corn_Kernel;
    
public:

    Corn() : CS(Corn_Status::Soso) {
        cout << "Hello! I'm a Corn!! My name is " << this << endl;
    }
    
    void Nutrient_Supply() {
        Corn_Kernels.push_back(Corn_Kernel);
    }
    
    void Take_Kernel() {
        Corn_Kernels.pop_back();
    }
    
    ~Corn() {}
    
};

int main() {
    Corn corn1;
    Corn corn2;
}
