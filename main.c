// ===================================================================================
//
//  Description: Main
//
//
// ===================================================================================

#include <stdio.h>

#include "phoneDataManager.h"

// System Data Array sizes
#define USER_LIST_SIZE 10

int main(void)
{
  struct User users[USER_LIST_SIZE] = { {0} };
  loadData(users, USER_LIST_SIZE);

  menu(users, USER_LIST_SIZE);
  return 0;
}
