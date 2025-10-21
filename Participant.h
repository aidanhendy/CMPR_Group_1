#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Participant {
private:
    int milage;
    string name;
    int number;
public:
    Participant(int, string, int);
    void displayInfo();
    string bestRunner();
};


