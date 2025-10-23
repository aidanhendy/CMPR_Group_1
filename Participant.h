#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Participant {
private:
    struct Run {
        string neighborhood; // optional if needed
        double distance;
    };

    int number;
    string name;
    Run runsArray[6];
    double totalMileage;

public:
    Participant();
    Participant(int num, string name, double distances[6]);
    double getTotalMileage() const;
    string getName() const;
    int getNumber() const;
    void displayInfo() const;

    // static helper functions
    static int numOfParticipants(const string file);
    static void readFile(const string& file, Participant participants[], int& count);
    static string bestRunner(const Participant participants[], int count);
};
