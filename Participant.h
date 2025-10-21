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
    

    double totalMilage;
    string name;
    int number;
    runs* runsArray;
    const int CAP = 6; //for array
    int noe; //number of entries
    

    
public:

    
    Participant();

    //big 3
    ~Participant();
    Participant(); //copy constructor
    Participant& operator=(const Participant& par); // overloaded = operator

    //everything else
    static int numOfParticipants(string file); //Counts number of participants.
    static void readFile(string file); //read function
    static void readLine(string line); // read individual line
    static string bestRunner(string file); //function to find best runner
    void displayInfo();
};


