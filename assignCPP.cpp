//
// Created by Steven Turner on 9/8/24.
//

#include "assignHeader.h"
#include <utility>

//should return index if num exists
int intExists (int userNum, const int userArray[], int size) {
    for (int i=0; i < size; i++) {
        if (userArray[i] == userNum) {
            return i;
        }
    }
    return -1;
}

//should return new value user wants to insert and old value that was replaced
pair<int, int> modifyElement(int userNum, int userIndex, int userArray[], int size) {
    // Check if the index is within bounds
    if (userIndex >= 0 && userIndex < size) {
        int oldValue = userArray[userIndex];
        userArray[userIndex] = userNum;
        return make_pair(userNum, oldValue); // Return new and old values
    } else {
        // If index is out of bounds
        return make_pair(-1, 24);
    }
}

//should add an integer to end of array
int addToEnd(int userNum, int userArray[], int currentSize, int maxSize) {
    //checking to see if the array is at its limit
    if (currentSize < maxSize) {
        userArray[currentSize] = userNum;
        return currentSize + 1;
    }
    else {
        return currentSize;
    }
}

//takes an index from user, replace that value with 0
int removeFromArray (int userIndex, int userArray[], int size) {
    // Check if the index is within bounds
    if (userIndex >= 0 && userIndex < size) {
        userArray[userIndex] = 0;
        return 1;
    }
    else {
        return 0;
    }

}

