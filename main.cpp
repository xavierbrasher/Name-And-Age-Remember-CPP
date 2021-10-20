#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;
string holdBeforeEnd;
string namesOfPeople[999];
fstream file;
int agesOfPeople[999];
int numberOfPeople = 0;
bool quit = true;

int clear(){
    system("cls");
    return 0;
}

int enterToContinue() {
    cout << "Press Enter to continue\n";
    cin.get();
    cin.ignore();
    return 0;
}

int saveData() {
    fstream saveFile;
    saveFile.open("savedData.dat", ios::out);
    if (!saveFile.is_open()) {
        return 1;
    }
    
    saveFile << numberOfPeople << endl;
    for (int i = 0; i < numberOfPeople; i++) {
        saveFile << namesOfPeople[i] << ",";
    }
    saveFile << "," << endl;
    for (int i = 0; i < numberOfPeople; i++) {
        saveFile << agesOfPeople[i] << ",";
    }
    saveFile << ",";
    saveFile.close();
    return 0;
}

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
        myfile.close();
        return 1;
    }
    if (myfile.peek() == std::ifstream::traits_type::eof()) {
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
    string ageAlltogetherThingy = ""; //i dont have a single clue about how my brain got this so like wowowowowwow
    int ageNumberAdded = 0;
    for (int i = 0; i < AgeArrayBeforeConversion.length()-1; i++)
    {
        string letter = string(1,AgeArrayBeforeConversion[i]);
        if (!(letter == ",")) {
            ageAlltogetherThingy += letter;
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

string toLower(string data){    
    for_each(data.begin(), data.end(), [](char & c) {
        c = ::tolower(c);
    });
    return data;
}

int newPerson(int clearOrNot) {
    if (clearOrNot == 0) {
        clear();
    }
    string name;
    cout << "What is the persons name (Type c to cancel):  ";
    cin >> name;
    if (name == "c" || name == "C") {
        cout << "Canceled. " << endl;
        enterToContinue();
        return 0;
    }
    string BasicBitchAge;
    cout << "\nWhat is the " + name + " age (Type c to cancel): ";
    cin >> BasicBitchAge;

    if (BasicBitchAge == "c" || BasicBitchAge == "C") {
        cout << "Canceled. " << endl;
        enterToContinue();
        return 0;
    }
    int age;
    try
    {
        age = stoi(BasicBitchAge);
        namesOfPeople[numberOfPeople] = name;
        agesOfPeople[numberOfPeople] = age;
        numberOfPeople += 1;
        return 0;
    }
    catch(const std::exception& e)
    {
        clear();
        cout<< "WOW that was toxic DO you know how much hardwork i have to do to make sure this works smh\n";
        newPerson(1);
        return 1;
    }
    
}

int listNames(int thingy) {
    clear();
    if (numberOfPeople == 0) {
        cout << "No one to list.\n";
    }
    else {
        for (int i = 0; i < numberOfPeople; i++) {
            cout << i+1 << ". Name: "<< namesOfPeople[i] << ", Age: " << agesOfPeople[i] <<"\n";
        }
    }
    if (thingy == 0)
    {
        enterToContinue();
    }
    return 0;
}

int removePerson(int anotherThingy) {

    if (anotherThingy == 0) {
        clear();
    }

    if (numberOfPeople == 0) {
        cout << "No one to remove.\n";
        enterToContinue();
        return 0;
    }
    cin.ignore();
    listNames(1);
    cout << "Which one would you like to remove: ";
    string BasicBitchIndexShitBleh;
    cin >> BasicBitchIndexShitBleh;
    int index;
    try
    {
        index = stoi(BasicBitchIndexShitBleh);
    }
    catch(const std::exception& e)
    {
        clear();
        cout<< "WOW that was toxic DO you know how much hardwork i have to do to make sure this works smh\n";
        removePerson(1);
    }
    index -= 1;
    for (int i = index; i < numberOfPeople; ++i) {
        namesOfPeople[i] = namesOfPeople[i + 1]; // copy next element left
        agesOfPeople[i] = agesOfPeople[i + 1];
    }
    numberOfPeople -= 1;   
    enterToContinue();
    return 0;
}

int main()
{
    while (quit) {
        clear();
        int errorInReading = readData();
        if (errorInReading == 1) {
            createFile();
            emptyData();
            readData();
        }
        else if (errorInReading == 2) {
            emptyData();
            readData();
        }
        cout << "Welcome To The Name and Age Remember\n";
        cout << "Type n To put someone in\n";
        cout << "Type l to list the names\n";
        cout << "Type r to remove a name\n";
        cout << "Type q to quit\n";
        cout << "Command: ";
        string decision;
        cin >> decision;
        decision = toLower(decision);
        if (decision == "n"){
            newPerson(0);
            saveData();
        }
        else if (decision == "l") {
            listNames(0);
            saveData();
        }
        else if (decision == "r"){
            removePerson(0);
            saveData();
        }
        else if (decision == "q") {
            quit = false;
            saveData();
        }
        else {
            cout << "try again\n";
            enterToContinue();
        }
    }
}