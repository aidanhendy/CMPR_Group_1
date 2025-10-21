#include "Participant.h"
#include <fstream>
#include <string>

int Participant:: numOfParticipants(string file)
{
    ifstream inFile;
    inFile.open("participantData.txt");
    string line;
    int count;

while(getline(inFile, line))
{
    count++;
}

}






void Participant:: readFile(string file)
{
    ifstream inFile;
    inFile.open("participantData.txt");
    string line;

    if(!inFile)
    {
        cerr << "Error opening file!" << endl;
        return;
    }

    while(getline(inFile, line))
    {

    }


while()
{

current++;


}

//while(infile >> num &&)




}
void Participant:: readLine(string line)
{
    int temp;
    for(int i =0; i < line.size();i++)
    {
        if (i ==' ' && i >= 30 && i <= 39)
        {
          temp = stoi(line.substr(0, i -1));
        }
    }
    
}
