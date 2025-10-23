#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Participant {
private:
    double runs[6];

    int number;
    string firstName;
    string lastName;
    double totalMileage;

public:

    Participant();
    Participant(int num, string name, double distances[6]);
    int setNumber(int num);
    int setFirstName(string name);
    int setLastName(string name);
    int setRuns(double runs[]);
    double getTotalMileage() const;
    string getName() const;
    int getNumber() const;

    void displayInfo() const;

    // static helper functions
    static int numOfParticipants(const string file);
    static void readFile(const string& file);
    static string bestRunner(const string& file, const Participant participants[]);
};


