//
// Created by Steven Turner on 9/8/24.
//

#ifndef ASSIGN1ST_ASSIGNHEADER_H
#define ASSIGN1ST_ASSIGNHEADER_H

#endif //ASSIGN1ST_ASSIGNHEADER_H
#include <utility>
using namespace std;

//should return index if num exists
int intExists(int userNum, const int userArray[], int size);

//should return new value user wants to insert and old value that was replaced
pair<int, int> modifyElement(int userNum, int userIndex, int userArray[], int size);

//should add an integer to end of array
int addToEnd(int userNum, int userArray[], int currentSize, int maxSize);

//takes an index from user, replace that value with 0
int removeFromArray (int userIndex, int userArray[], int size);