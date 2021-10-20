#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string namesOfPeople[999];
int agesOfPeople[999];      
int numberOfPeople = 0;

int emptyData() {
    fstream fillDefult;
    fillDefult.open("savedData.dat", ios::out);
    fillDefult << "0" << endl;
    fillDefult << ",," << endl;
    fillDefult << ",," << endl;
    return 0;
}

int createFile() {
    fstream create;
    create.open("savedData.dat", ios::out);
    create.close();
    return 0;
}

int readData() {
    fstream myfile;
    myfile.open("savedData.dat", ios::in);
    if (!myfile.is_open()) {
        cout << "NO FILE" << endl;
        myfile.close();
        return 1;
    }
    if (myfile.peek() == std::ifstream::traits_type::eof()) {
        cout << "empty" << endl;
        myfile.close();
        return 2;
    }
    string NameArrayBeforeConversion; //shooot me please i want to die 
    string AgeArrayBeforeConversion; //shooot me more please i want to die even more
    string lines;
    int numberOfLines = 0;
    while (getline(myfile,lines)) {
        if (numberOfLines == 0)
        {
            numberOfPeople = stoi(lines);
        }
        else if (numberOfLines == 1) {
            NameArrayBeforeConversion = lines;
        }
        else if (numberOfLines == 2) {
            AgeArrayBeforeConversion = lines;
        }
        numberOfLines++;
    }
    string alltogetherThing;
    int numberAdded = 0;
    for (int i = 0; i < NameArrayBeforeConversion.length()-1; i++)
    {
        cout << alltogetherThing <<endl;
        string letter = string(1,NameArrayBeforeConversion[i]);
        if (!(letter == ",")) {
            alltogetherThing += letter;
        }
        else if (letter == "," ) {
            namesOfPeople[numberAdded] = alltogetherThing;
            alltogetherThing = "";
            numberAdded += 1;
        }
    }
    cout << endl;
    string ageAlltogetherThingy = ""; //i dont have a single clue about how my brain got this so like wowowowowwow
    int ageNumberAdded = 0;
    for (int i = 0; i < AgeArrayBeforeConversion.length()-1; i++)
    {
        cout << ageAlltogetherThingy << endl;
        string letter = string(1,AgeArrayBeforeConversion[i]);
        if (!(letter == ",")) {
            ageAlltogetherThingy += letter;
            cout << letter << endl;
        }
        else if (letter == "," ) {
            if (!(ageAlltogetherThingy == "")) {
                agesOfPeople[ageNumberAdded] = stoi(ageAlltogetherThingy);
            }
        ageAlltogetherThingy = "";
        ageNumberAdded++;
            
        }
    }
    myfile.close();
    return 0;
}

int main() {
    int thing = readData();
    if (thing == 1) {
        createFile();
        emptyData();
        readData();
    }
    else if (thing == 2) {
        emptyData();
        readData();
    }
    cout << endl;
    for (int i = 0; i < numberOfPeople; i++) {
            cout << namesOfPeople[i] << endl;
            cout << agesOfPeople[i] << endl;
        }

}