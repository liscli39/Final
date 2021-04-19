// ===================================================================================
//  Description: Main
// ===================================================================================
//  Student Name  : Vy Le
//  Student ID    : 126487206
//  Student Email : tpvle@myseneca.ca
//  Course Section: NHH
// ===================================================================================


// User-Defined Libraries
#include "phoneDataManager.h"

// System Libraries
#include <stdio.h>

// System Data Array sizes
#define USER_LIST_SIZE 50

int main(void)
{
  struct User users[USER_LIST_SIZE] = { {0} };
  loadData(users, USER_LIST_SIZE);

  menu(users, USER_LIST_SIZE);
  return 0;
}
