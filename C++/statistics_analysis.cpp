// [Data Structure] ! PARTITION AS DATE !

// ! DAILY !
// { Date : YYYY / MM / DD] }
// { Number of Restock : m } 
// { Number of sold items : n }
// { Number of ADS : o }
// { Number of Visitors : p }

#include <iostream>
#include <sqlite3.h>
#include <string>
#include <ctime>
using namespace std;

typedef struct FullData{
    unsigned int restock;
    unsigned int sold;
    unsigned int ads;
    unsigned int visitors;
}FullData;

string intToDate(int year, int month, int day) {
    string date = to_string(year) + "/" + (month < 10 ? "0" : "") + to_string(month) + "/" + (day < 10 ? "0" : "") + to_string(day);  
    return date;
}

class newNote{
    sqlite3* DB;
    int DB_t;
    
public:    
    newNote() {
        DB_t=sqlite3_open("newNote.db", &DB);
        if(DB_t) { cerr << "Cannot open new note: " << sqlite3_errmsg(DB) << endl; }
    }
    
    ~newNote() { sqlite3_close(DB); }
    
    void typeInfo() {
        FullData FD;
        
        time_t date_raw=time(nullptr);
        tm* date=localtime(&date_raw);
        string dates=intToDate(date->tm_year+1900, date->tm_mon + 1, date->tm_mday);
        
        cout << "Enter the Number of Restock: ";
        cin >> FD.restock;

        cout << "Enter the Number of sold items: ";
        cin >> FD.sold;

        cout << "Enter the Number of ADS: ";
        cin >> FD.ads;

        cout << "Enter the Number of Visitors: ";
        cin >> FD.visitors;
    }
};

int main(){}
