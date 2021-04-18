// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// User-Defined Libraries
#include "phoneDataManager.h"
#include "commonHelpers.h"

int findUserIndexByUserName(char* name, const struct User users[], int arrSize) {
  int id, position;

  position = -1;
  for (id = 0; id < arrSize; id ++) {
    if (!strcmp(name, users[id].name)) {
      position = id;
      break;
    }
  }

  return position;
}

void loadData(struct User users[], int arrSize) {
  int id, index, recordCount, dataBytes;
  double callMinutes, screenTime;
  char name[NAME_SIZE];
  char callNumber[CALL_NUMBER_SIZE];

  FILE *fp;
  fp = fopen("phoneIn.txt", "r");

  id = 0;
  do {
    getFileCString(fp, name, NAME_SIZE, '|');

    if (name[0] != EOF) {
      index = findUserIndexByUserName(name, users, arrSize);

      if (index == -1) {
        strcpy(users[id].name, name);
        index = id ++;
      }

      recordCount = users[index].recordCount ++;
      getFileCString(fp, users[index].records[recordCount].callNumber, CALL_NUMBER_SIZE, '|');
      fscanf(fp, "%lf|", &users[index].records[recordCount].callMinutes);
      fscanf(fp, "%d|", &users[index].records[recordCount].dataBytes);
      fscanf(fp, "%lf\n", &users[index].records[recordCount].screenTimes);
    }
  } while (name[0] != EOF);  
  
  fclose (fp);
}

void copyArray(struct User destin[], const struct User source[], int arrSize) {
  int i;
  for (i = 0; i < arrSize; i ++) {
    destin[i] = source[i];
  }
}

void sortUserByDuration(struct User users[], int arrSize) {
  int i, j;
  for (i = 0; i < arrSize; i ++) {
    for (j = i + 1; j < arrSize; j ++) {
      if (sumDuration(users[i]) > sumDuration(users[j])) {
        swap(&users[i], &users[j]);
      }
    }
  }
}

void displayUserByCallDuration(const struct User users[], int arrSize) {
  int id, recordId;
  int clock[2];
  double callMinutes;
  struct User copy[arrSize];

  copyArray(copy, users, arrSize);
  sortUserByDuration(copy, arrSize);

  printf("User  Call Duration\n");
  for (id = 0; id < arrSize; id ++) {
    if (copy[id].recordCount != 0) {
      timeConvert(sumDuration(copy[id]), clock);
      printf("%s %10d:%02d\n",copy[id].name, clock[0], clock[1]);
    }
  }
}

void displayUserByDataUsage(const struct User users[], int arrSize) {

}

void displayUserByScreenTime(const struct User users[], int arrSize) {

}

void displayAllUserData(const struct User users[], int arrSize) {

}

int menu(const struct User users[], int arrSize) {
    int index, choose;

  do {
    printf("Select one of the following options:\n");
    printf("0 - Exit\n");
    printf("1 - Show users by call duration\n");
    printf("2 - Show users by data usage\n");
    printf("3 - Show users by screen time\n");
    printf("4 - Show all user data\n");

    choose = getIntFromRange(0, 4);

    switch (choose) {
      case 1: {
        displayUserByCallDuration(users, arrSize);
        break;
      }

      default:
        break;
    }

    printf("\n");
  } while (choose != 0);
}
