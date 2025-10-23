#include "Participant.h"
#include <fstream>
#include <string>

Participant::Participant() {
    number = 0;
    name = "";
    totalMileage = 0.0;
    for (int i = 0; i < 6; i++)
        runsArray[i].distance = 0.0;
}

Participant::Participant(int num, string name, double distances[6]) {
    number = num;
    name = name;
    totalMileage = 0.0;
    for (int i = 0; i < 6; i++) {
        runsArray[i].distance = distances[i];
        totalMileage += distances[i];
    }
}

double Participant::getTotalMileage() const {
    return totalMileage;
}

string Participant::getName() const {
    return name;
}

int Participant::getNumber() const {
    return number;
}

int Participant::numOfParticipants(const string file) {
    ifstream inFile(file);
    string line;
    int count = 0;
    while (getline(inFile, line))
    {
        if (!line.empty()) 
        {
            count++;
        }
    } 
    inFile.close();
    return count;
}

void Participant::readFile(const string& file, Participant participants[], int& count)
{

}

string bestRunner(const Participant participants[], int count)
{

}
