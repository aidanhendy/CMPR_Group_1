#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Participant {
private:

    struct runs
    {
        string neighborhood;
        double distance;
    };
    

    double milage;
    string name;
    int number;
    
public:

    
    Participant(double mile, string name, int num);

    //big 3
    ~Participant();
    Participant(); //copy constructor
    Participant& operator=(const Participant& par); // overloaded = operator

    //everything else
    static void readFile(string file); //read function
    static string bestRunner(string file); //function to find best runner
    void displayInfo();
};


