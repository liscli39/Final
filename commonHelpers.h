// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#ifndef COMMON_HELPERS_H_
#define COMMON_HELPERS_H_

// ----------------------------------------------------------------------------
// function prototypes

// ---------------------------------------------------------
// Clear standard input Buffer
// ---------------------------------------------------------
void clearStandardInputBuffer(void);

// ---------------------------------------------------------
// Get user input: Integer
// ---------------------------------------------------------
int getInteger(void);

// ---------------------------------------------------------
// Get user input: Integer from range
// ---------------------------------------------------------
int getIntFromRange(int min, int max);

// ---------------------------------------------------------
// Get file input: CS String
// ---------------------------------------------------------
void getFileCString(FILE* file, char* string, int max, char endSymbol);

#endif