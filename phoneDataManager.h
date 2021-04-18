// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#ifndef PHONE_DATA_MANAGER_H_
#define PHONE_DATA_MANAGER_H_

#include "user.h"

// ----------------------------------------------------------------------------
// function prototypes

int findUserIndexByUserName(char* name, const struct User users[], int arrSize);

void loadData(struct User users[], int arrSize);

void copyArray(struct User destin[], const struct User source[], int arrSize);

void displayUserByCallDuration(const struct User users[], int arrSize);

void displayUserByDataUsage(const struct User users[], int arrSize);

void displayUserByScreenTime(const struct User users[], int arrSize);

void displayAllUserData(const struct User users[], int arrSize);

int menu(const struct User users[], int arrSize);

#endif
