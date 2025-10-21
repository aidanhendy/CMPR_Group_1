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
    Participant(int mile, string name, int num);
    void displayInfo();
    static void readFile(string file); //read function
    static string bestRunner(string file); //function to find best runner
};


