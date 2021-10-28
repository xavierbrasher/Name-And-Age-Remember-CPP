#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
using namespace std;
string namesOfPeople[999];
fstream file;
int agesOfPeople[999];
int numberOfPeople = 0;
bool quit = true;
bool nameInput = false;

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
    saveFile << "," << endl;
    if (nameInput == true) {
        saveFile << "1";
    }
    else if (nameInput == false) {
        saveFile << "0";
    }
    saveFile.close();
    return 0;
}

int emptyData() {
    fstream fillDefult;
    fillDefult.open("savedData.dat", ios::out);
    fillDefult << "0" << endl;
    fillDefult << ",," << endl;
    fillDefult << ",," << endl;
    fillDefult << "0" << endl;
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
        else if (numberOfLines == 3) {
            if (lines == "0") {
                nameInput = false;
            }
            else if (lines == "1") {
                nameInput = true;
            }
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

void checkFileDoesntCrash() {
    fstream check;
    check.open("savedData.dat", ios::in);
    int thingywowIHateLIfe = 0;
    int checkIfItWorks = 0;
    string lines;
    try
    {
        while (getline(check,lines)) {
                if (thingywowIHateLIfe == 0)
                {
                    checkIfItWorks = stoi(lines);
                }
                thingywowIHateLIfe++;
        }
    }
    catch(const std::exception& e)
    {
        emptyData();
    }    
}

string toLower(string data){    
    for_each(data.begin(), data.end(), [](char & c) {
        c = ::tolower(c);
    });
    return data;
}

int newPerson(int clearOrNot, int type, string preName) {
    if (clearOrNot == 0) {
        clear();
    }
    string name;
    if (type == 0) {

        cout << "What is the persons name (Type c to cancel):  ";
        cin >> name;
        if (name == "c" || name == "C") {
            cout << "Canceled. " << endl;
            enterToContinue();
            return 0;
        }
    }
    else if (type == 1) {
        name = preName;
    }
    
    string BasicBitchAge;
    cout << "What is the " + name + " age (Type c to cancel): ";
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
        if (preName == "") {
            newPerson(1,0,"");
        }
        else {
            newPerson(1,1,preName);
        }
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
    listNames(1);
    enterToContinue();
    return 0;
}

string checkNameInput() {
    if (nameInput == true) {
        return "enabled";
    }
    else if (nameInput == false) {
        return "disabled";
    }
    return "crash";
}

void setupFile() {
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
}

int main()
{
    checkFileDoesntCrash();
    while (quit) {
        setupFile();
        clear();
        cout << "Welcome To The Name and Age Remember\n";
        cout << "Type n To put someone in\n";
        cout << "Type l to list the names\n";
        cout << "Type r to remove a name\n";
        cout << "Type f to toggle input name through command (" << checkNameInput() << ")" << endl; 
        cout << "Type q to quit\n";
        cout << "Command: ";
        string decision;
        string beforeLower;
        cin >> decision;
        beforeLower = decision; 
        decision = toLower(decision);
        if (decision == "n"){
            newPerson(0, 0, "");
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
        else if (decision == "f") {
            if (nameInput == false) {
                nameInput = true;
            }
            else if (nameInput == true) {
                nameInput = false;
            }
            saveData();
        }
        else if (decision == "q") {
            quit = false;
            saveData();
        }
        else {
            if (nameInput == true) {
                newPerson(0,1,beforeLower);
                saveData();
            } 
            else {
                cout << "try again\n";
                enterToContinue();  
            }
            
        }
    }
}