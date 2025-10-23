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
    ifstream inFile;
    inFile.open(file);
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

void Participant::readFile(const string& file, int& count, const Participant participants[])
{
    int numberOfPeople = numOfParticipants(file);
    ifstream inFile;
    inFile.open(file);
    Participant runs[numberOfPeople];
    int num;
    string name;
    double distances[6];

    /*
    for(int i = 0; i < numberOfPeople; i++)
    {
        runs[i] = 
    }
    */

    while(inFile >> num >> name)
    {
        
        for(int i = 0; i < 6; i++)
        {
            inFile >> distances[i];
        }
        runs[numberOfPeople] = Participant(num, name, distances);
        count++;
    }
    inFile.close();

}

string Participant:: bestRunner(const string& file, const Participant participants[], int count)
{
    int numberOfPeople = numOfParticipants(file);

    double bestMilage = participants[0].getTotalMileage();
    string bestRunner = participants[0].getName();
    for(int i = 1; i < numberOfPeople; i++)
    {   
         if(participants[i].getTotalMileage() > bestMilage)
         {
            bestMilage = participants[i].getTotalMileage();
            bestRunner = participants[i].getName();
         }
    }
    return bestRunner;
}
