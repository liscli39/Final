// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
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

  printf("                          User  Call Duration\n");
  for (id = 0; id < arrSize; id ++) {
    if (copy[id].recordCount != 0) {
      timeConvert(sumDuration(copy[id]), clock);
      printf("%30s%12d:%02d\n",copy[id].name, clock[0], clock[1]);
    }
  }
}

void sortUserByDataUsage(struct User users[], int arrSize) {
  int i, j;
  for (i = 0; i < arrSize; i ++) {
    for (j = i + 1; j < arrSize; j ++) {
      if (sumDataUsage(users[i]) > sumDataUsage(users[j])) {
        swap(&users[i], &users[j]);
      }
    }
  }
}

void displayUserByDataUsage(const struct User users[], int arrSize) {
  int id, recordId;
  double callMinutes;
  struct User copy[arrSize];

  copyArray(copy, users, arrSize);
  sortUserByDataUsage(copy, arrSize);

  printf("                          User     Data Usage\n");
  for (id = 0; id < arrSize; id ++) {
    if (copy[id].recordCount != 0) {
      printf("%30s%15d\n",copy[id].name, sumDataUsage(copy[id]));
    }
  }
}

void sortUserByScreenTime(struct User users[], int arrSize) {
  int i, j;
  for (i = 0; i < arrSize; i ++) {
    for (j = i + 1; j < arrSize; j ++) {
      if (sumScreenTimes(users[i]) > sumScreenTimes(users[j])) {
        swap(&users[i], &users[j]);
      }
    }
  }
}

void displayUserByScreenTime(const struct User users[], int arrSize) {
  int id, recordId;
  int clock[2];
  double callMinutes;
  struct User copy[arrSize];

  copyArray(copy, users, arrSize);
  sortUserByScreenTime(copy, arrSize);

  printf("                          User    Screen Time\n");
  for (id = 0; id < arrSize; id ++) {
    if (copy[id].recordCount != 0) {
      timeConvert(sumScreenTimes(copy[id]), clock);
      printf("%30s%12d:%02d\n",copy[id].name, clock[0], clock[1]);
    }
  }
}

void displayAllUserData(const struct User users[], int arrSize) {
  int id, recordId, header;
  int clock[2];

  for (id = 0; id < arrSize; id ++) {
    if (users[id].recordCount != 0) {
      printf("---------------------------------------------\n");
      printf("User: %s\n", users[id].name);

      header = 0;
      for (recordId = 0; recordId < users[id].recordCount; recordId ++) {
        if (users[id].records[recordId].callMinutes != 0) {
          if (header == 0) {
            printf("  Number Called  Duration\n");
            header = 1;
          }

          timeConvert(users[id].records[recordId].callMinutes, clock);
          printf(
            "%15s %6d:%d\n", 
            users[id].records[recordId].callNumber,
            clock[0], clock[1]
          );
        }
      }

      header = 0;
      for (recordId = 0; recordId < users[id].recordCount; recordId ++) {
        if (users[id].records[recordId].dataBytes != 0) {
          if (header == 0) {
            printf("Bytes Transferred\n");
            header = 1;
          }

          printf("%18d\n", users[id].records[recordId].dataBytes);
        }
      }

      header = 0;
      for (recordId = 0; recordId < users[id].recordCount; recordId ++) {
        if (users[id].records[recordId].screenTimes != 0) {
          if (header == 0) {
            printf("Screen Minutes\n");
            header = 1;
          }

          timeConvert(users[id].records[recordId].screenTimes, clock);
          printf("%12d:%02d\n", clock[0], clock[1]);
        }
      }

    }
  }
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

      case 2: {
        displayUserByDataUsage(users, arrSize);
        break;
      }

      case 3: {
        displayUserByScreenTime(users, arrSize);
        break;
      }

      case 4: {
        displayAllUserData(users, arrSize);
        break;
      }

      default:
        break;
    }

    printf("\n");
  } while (choose != 0);
}
