#include <iostream>
#include <vector>
using namespace std;

enum class Corn_Status {Bad, Soso, Good};

class Corn{
    
    Corn_Status CS;
    vector<short> Corn_Kernels;
    vector<short>::iterator Corn_Kernel_Finder;
    unsigned short Corn_Kernel;
    
public:

    Corn() : CS(Corn_Status::Soso) {
        cout << "Hello! I'm a Corn!! My name is " << this << endl;
    }
    
    void Nutrient_Supply() {
        Corn_Kernels.push_back(++Corn_Kernel);
    }
    
    void View_Kernels() {
        cout << "Corn Kernels:" << endl;
        for (Corn_Kernel_Finder = Corn_Kernels.begin(); Corn_Kernel_Finder != Corn_Kernels.end(); ++Corn_Kernel_Finder) {
            cout << *Corn_Kernel_Finder << " ";
        }
        cout << endl;
    }

    
    void Take_Kernel() {
        Corn_Kernels.pop_back();
    }
    
    ~Corn() {}
    
};

int main() {
    Corn corn1;
    for (int i = 0; i < 5; ++i) {
        corn1.Nutrient_Supply();
    }
    corn1.View_Kernels();
    corn1.Take_Kernel();
    
    cout << endl;
    
    Corn corn2;
    for (int i = 0; i < 5; ++i) {
        corn2.Nutrient_Supply();
    }
    corn2.View_Kernels();
    corn2.Take_Kernel();
}
