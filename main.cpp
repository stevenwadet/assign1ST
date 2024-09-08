//
// Created by Steven Turner on 9/8/24.
//
#include <iostream>
#include <fstream>
#include "assignHeader.h"
#include <utility>


using namespace std;

int main() {
    //array setup
    int userArray[120];
    int maxSize = 120;

    //opening file
    ifstream file("A1input.txt");
    if (!file) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    //inserting values from input file into array
    int count = 0;
    while (file >> userArray[count] && count < 100) {
        ++count;
    }

    //closing file after done using it
    file.close();

    //setting up user menu for function utilization
    int userMenuInput = 0;
    while (userMenuInput != 5) {
        cout << "What would you like to do to your array?" << endl;
        cout << "1 - input a number and see if it exists in your array " << endl;
        cout << "2 - modify an element of an array" << endl;
        cout << "3 - add an element to the end of the array" << endl;
        cout << "4 - replace an element with the value 0" << endl;
        cout << "5 - quit" << endl;
        cout << "choose an option (1-5): ";

        cin >> userMenuInput;
        if (userMenuInput == 1) {
            int userNum = 0;
            cout << "Enter a number" << endl;
            cin >> userNum;
            int foundIndex = intExists(userNum,userArray,count);
            if (foundIndex == -1) {
                cout << "Number not found in array" << endl;
            }
            else {
                cout << "The index of your number is " << foundIndex << endl;
            }

        }
        else if (userMenuInput == 2) {
            int newElement = 0;
            int userIndex = 0;
            cout << "enter the index you want to replace:" << endl;
            cin >> userIndex;
            cout << "What value would you like to insert?" << endl;
            cin >> newElement;
            pair <int,int> result = modifyElement(newElement,userIndex,userArray,count);
            int newNum = result.first;
            int oldNum = result.second;
            //randomly selected values, absolutely not the best way to handle the out of range for index
            if (newNum == -1 && oldNum == 24) {
                cout << "Index is out of range" << endl;
            }
            else {
                cout << "The old value " << oldNum << " was replaced with " << newNum << endl;
                for (int i = 0; i < count; i++) {
                    cout << userArray[i] << " ";
                }
                cout << endl;
            }


        }
        else if (userMenuInput == 3) {
            int elementToAdd;
            cout << "type a value to add to the end of the array" << endl;
            cin >> elementToAdd;
            int newSize = addToEnd(elementToAdd, userArray, count, maxSize);
            if (newSize == count) {
                //error handling for a full array
                cout << "Error: Cannot add more elements to the array" << endl;
            }
            else {

                count = newSize;
                //telling the user it was successful and printing the array
                cout << "value successfully added" << endl;
                for (int i = 0; i < count; i++) {
                    cout << userArray[i] << " ";
                }
                cout << endl;
            }
        }
        else if (userMenuInput == 4) {
            int removeIndex;
            cout << "type an index to remove the associated value from the array" << endl;
            cin >> removeIndex;
            int status = removeFromArray(removeIndex, userArray, count);
            if (status == 0) {
                cout << "Error: Index is out of bounds" << endl;
            }
            else {
                cout << "Value at index " << removeIndex << " has successfully been replaced with 0." << endl;
                for (int i = 0; i < count; i++) {
                    cout << userArray[i] << " ";
                }
                cout << endl;
            }
        }
        else {
            cout << "invalid choice, select an option (1-5)." << endl;
            cout << "1 - input a number and see if it exists in your array " << endl;
            cout << "2 - modify an element of an array" << endl;
            cout << "3 - add an element to the end of the array" << endl;
            cout << "4 - replace an element with the value 0" << endl;
            cout << "5 - quit" << endl;
            cin >> userMenuInput;
        }
    }



}

