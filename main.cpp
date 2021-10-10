#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;
string holdBeforeEnd;
string namesOfPeople[999];
int agesOfPeople[999];
int numberOfPeople = 0;
bool quit = true;
int clear(){
    system("cls");
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
    cout << "What is the persons name: ";
    cin >> name;
    string BasicBitchAge;
    cout << "\nWhat is the " + name + " age: ";
    cin >> BasicBitchAge;
    int age;
    try
    {
        age = stoi(BasicBitchAge);
    }
    catch(const std::exception& e)
    {
        clear();
        cout<< "WOW that was toxic DO you know how much hardwork i have to do to make sure this works smh\n";
        newPerson(1);
    }
    namesOfPeople[numberOfPeople] = name;
    agesOfPeople[numberOfPeople] = age;
    numberOfPeople += 1;
    return 0;
}
int enterToContinue() {
    cout << "Press Enter to continue\n";
    cin.get();
    cin.ignore();
    return 0;
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
        }
        else if (decision == "l") {
            listNames(0);
        }
        else if (decision == "r"){
            removePerson(0);
        }
        else if (decision == "q") {
            quit = false;
        }
        else {
            cout << "try again\n";
            enterToContinue();
        }
    }
}