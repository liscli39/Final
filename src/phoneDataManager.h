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

// ---------------------------------------------------------
// Find user index by user name
// ---------------------------------------------------------
int findUserIndexByUserName(char* name, const struct User users[], int arrSize);

// ---------------------------------------------------------
// Load data from text file
// ---------------------------------------------------------
void loadData(struct User users[], int arrSize);

// ---------------------------------------------------------
// Copy list user to another
// ---------------------------------------------------------
void copyArray(struct User destin[], const struct User source[], int arrSize);

// ---------------------------------------------------------
// Sort list user by call duration
// ---------------------------------------------------------
void sortUserByDuration(struct User users[], int arrSize);

// ---------------------------------------------------------
// Display list user order by call duration
// ---------------------------------------------------------
void displayUserByCallDuration(const struct User users[], int arrSize);

// ---------------------------------------------------------
// Sort list user by data usage
// ---------------------------------------------------------
void sortUserByDataUsage(struct User users[], int arrSize);

// ---------------------------------------------------------
// Display list user order by data usage
// ---------------------------------------------------------
void displayUserByDataUsage(const struct User users[], int arrSize);

// ---------------------------------------------------------
// Sort list user by screen times
// ---------------------------------------------------------
void sortUserByScreenTime(struct User users[], int arrSize);

// ---------------------------------------------------------
// Display list user order by screen times
// ---------------------------------------------------------
void displayUserByScreenTime(const struct User users[], int arrSize);

// ---------------------------------------------------------
// Display all user and data
// ---------------------------------------------------------
void displayAllUserData(const struct User users[], int arrSize);

// ---------------------------------------------------------
// Menu 
// ---------------------------------------------------------
int menu(const struct User users[], int arrSize);

#endif
