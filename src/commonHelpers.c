// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#include <time.h>
#include <math.h> 

// User-Defined Libraries
#include "commonHelpers.h"

void clearStandardInputBuffer(void)
{
  while (getchar() != '\n')
  {
    ; // On purpose: do nothing
  }
}

int getInteger(void) {
  int number;
  char term;

	do {
		if (scanf("%d%c", &number, &term) != 2 || term != '\n') {
			printf("ERROR: Value must be an integer: ");
      clearStandardInputBuffer();
      term = '\0';
		}
	} while (term != '\n');

  return number;
}

int getIntFromRange(int min, int max) {
  int number;
  
	do {
    number = getInteger();
		if (number < min || number > max) {
      printf("ERROR: Value must be between %d and %d inclusive: ", min, max);
		}
	} while (number < min || number > max);
  
  return number;
}

void getFileCString(FILE* file, char* string, int max, char endSymbol) {
  int id;
  char input = '\n';

  for (id = 0; id <= max && input != '\0'; id++) {
    input = fgetc(file);

    if (input == '\n' || input == endSymbol) {
      input = '\0';
    }

    string[id] = input;
  }
}

void timeConvert(double time, int clock[]) {
  clock[0] = (int) time;
  double decimal = time - clock[0];
  double second = decimal * 60;
  second = second + 0.5 - (second < 0);
  clock[1] = (int) second;
}