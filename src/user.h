// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#ifndef PHONE_H_
#define PHONE_H_

// -----------------------------------------------------------------------------------
// System Data Array sizes
// -----------------------------------------------------------------------------------
#define NAME_SIZE 31
#define CALL_NUMBER_SIZE 11
#define MAX_LIST_SIZE 150

// ----------------------------------------------------------------------------
// structures
struct Record {
  char callNumber[CALL_NUMBER_SIZE];
  double callMinutes;
  int dataBytes;
  double screenTimes;
};

struct User {
  char name[NAME_SIZE];
  struct Record records[MAX_LIST_SIZE];
  int recordCount;
};

// ----------------------------------------------------------------------------
// function prototypes

// ---------------------------------------------------------
// Sum duration
// ---------------------------------------------------------
double sumDuration(struct User user);

// ---------------------------------------------------------
// Sum data usage
// ---------------------------------------------------------
int sumDataUsage(struct User user);

// ---------------------------------------------------------
// Sum screen times
// ---------------------------------------------------------
double sumScreenTimes(struct User user);

// ---------------------------------------------------------
// Swap user
// ---------------------------------------------------------
void swap(struct User* first, struct User* second);


#endif