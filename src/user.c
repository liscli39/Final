// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================
#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "user.h"

double sumDuration(struct User user) {
  int id;
  double duration = 0;
  for (id = 0; id < user.recordCount; id ++) {
    duration += user.records[id].callMinutes;
  }

  return duration;
}

int sumDataUsage(struct User user) {
  int id, data;
  data = 0;
  for (id = 0; id < user.recordCount; id ++) {
    data += user.records[id].dataBytes;
  }

  return data;
}

double sumScreenTimes(struct User user) {
  int id;
  double times = 0;
  for (id = 0; id < user.recordCount; id ++) {
    times += user.records[id].screenTimes;
  }

  return times;
}

void swap(struct User* first, struct User* second) {
  struct User temp = *first;
  *first = *second;
  *second = temp;
}
