#include "Participant.h"
#include <fstream>
#include <string>
const int NEIGHBORHOODS = 6;
Participant::Participant() {
    number = 0;
    firstName = "";
    lastName ="";
    totalMileage = 0.0;
    for (int i = 0; i < 6; i++)
        runs[i] = 0.0;
}

Participant::Participant(int num, string name, double distances[6]) {
    number = num;
    name = name;
    totalMileage = 0.0;
    for (int i = 0; i < 6; i++) {
        runs[i] = distances[i];
        totalMileage += distances[i];
    }
}
int Participant:: setNumber(int num)
{
    number = num;
}
int Participant:: setFirstName(string name)
{
    firstName = name;
}
int Participant:: setFirstName(string name)
{
    lastName = name;
}
int Participant:: setRuns(double arr[])
{
    for (int i = 0; i < NEIGHBORHOODS; i++)
    {
        runs[i] = arr[i];
    }
}

double Participant::getTotalMileage() const {
    return totalMileage;
}

string Participant::getName() const {
    return firstName + " " + lastName;
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
    return count; //num of partipants
}



void Participant::readFile(const string& file)
{
    int numberOfPeople = numOfParticipants(file);
    ifstream inFile;
    inFile.open(file);

    Participant participants[numberOfPeople];
    int num;
    string firstName;
    string lastName;
    double distances[6];

    /*
    for(int i = 0; i < numberOfPeople; i++)
    {
        runs[i] = 
    }
    */
    string word;
    while(inFile >> word)
    {
        num = stoi(word);
        inFile >> word;
        firstName = word;
        inFile >> word;
        lastName = word;
    
        for (int i = 0; i < NEIGHBORHOODS; i++ )
        {
            inFile >> word;
            distances[i] = stoi(word);
        }
        for (int i = 0; i < numberOfPeople; i ++)
        {
            participants[i].setNumber(num);
            participants[i].setFirstName(firstName);
            participants[i].setLastName(lastName);
            participants[i].setRuns(distances);
        }

        
        numberOfPeople++;
    }
    inFile.close();

}

string Participant:: bestRunner(const string& file, const Participant participants[])
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
