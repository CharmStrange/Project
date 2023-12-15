#include <iostream>
#include <vector>
#include <cstdlib>  // For std::rand
#include <ctime>    // For std::time
#include <random>
using namespace std;

enum class Status {Bad, Soso, Good};

class Corn{
    
    Status CS;
    vector<string> Corn_Kernels;
    vector<string>::iterator Corn_Kernel_Finder;
    string Corn_Kernel = "kernel";
    
    short degree;
    
public:

    Corn() : CS(Status::Soso) {
        cout << "Hello! I'm a Corn!! My name is " << this << endl;
        degree = 0;
    }
    
    void Nutrient_Supply() {
        cout << "Grow Up!" << endl;
        Corn_Kernels.push_back(Corn_Kernel);
        degree++;
    }
    
    void Corn_Status() {
        if (degree > 7) {Status::Bad; cout << "Bad" << endl;}
        else if (degree < -2) {Status::Bad; cout << "Bad" << endl;}
        else {Status::Good; cout << "Good" << endl;}
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
        degree--;
    }
    
    ~Corn() {}
    
};

enum class Weather_Phenomena {Breeze, Gust, Gale, Storm, Hurricane, Rain, Shower, Flood, Drought, Snow, Sleet, Hail, Blizzard, Fog, Mist, Haze};

Weather_Phenomena GetRandomWeather() {
    // Initialize a random number generator with a seed based on current time
    std::srand(static_cast<unsigned>(std::time(0)));

    // Get the number of enumerators in the Weather_Phenomena enum
    int enumSize = static_cast<int>(Weather_Phenomena::Haze) + 1;

    // Generate a random index within the range of the enum
    int randomIndex = std::rand() % enumSize;

    // Convert the random index to the corresponding Weather_Phenomena value
    Weather_Phenomena randomWeather = static_cast<Weather_Phenomena>(randomIndex);

    return randomWeather;
}

void Forecast() {
    Weather_Phenomena randomWeather = GetRandomWeather();

    // Do something with the randomly selected weather
    std::cout << "Forecast: " << static_cast<int>(randomWeather) << std::endl;
}

vector<Corn> Corn_List;
vector<Corn>::iterator Corn_List_Finder;

Corn New_Corn() {
    Corn corn;
    Corn_List.push_back(corn);
    return corn;
}

void View_Corns() {
    cout << "Corns : "<< Corn_List.size() << endl;
}

int main() {
    /*
    Corn corn1;
    for (int i = 0; i < 3; ++i) {
        corn1.Nutrient_Supply();
    }
    corn1.View_Kernels();
    corn1.Take_Kernel();
    corn1.Take_Kernel();
    corn1.View_Kernels();
    corn1.Corn_Status();
    
    cout << endl;
    
    Corn corn2;
    for (int i = 0; i < 11; ++i) {
        corn2.Nutrient_Supply();
    }
    corn2.View_Kernels();
    corn2.Take_Kernel();
    corn2.Take_Kernel();
    corn2.View_Kernels();
    corn2.Corn_Status();
    */
    
    New_Corn();
    New_Corn();
    New_Corn();
    View_Corns();
    Forecast();

}
