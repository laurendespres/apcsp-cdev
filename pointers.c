#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);


// creating float variable 'd'
  int d;
  int* ptrtod;

  ptrtod = &d;

// assigning float variable 'd' an initial value
  d = 7;

// printing out value and address of variable 'd'
  printf("The value of d is %d\n", d);

  printf("The value of ptrtod is %p\n", (void*)ptrtod);
  printf("It stores the value %d\n", *ptrtod);
  printf("The address of d is %p\n", (void*)&d);

// ______________________________________________________________

// creating float variable 'e'
  int e;
  int* ptrtoe;

  ptrtoe = &e;

// assigning float variable 'e' an initial value
  e = 13;
 
// printing out value and address of variable 'e'
  printf("The value of e is %d\n", e);

  printf("The value of ptrtoe is %p\n", (void*)ptrtoe);
  printf("It stores the value %d\n", *ptrtoe);
  printf("The address of e is %p\n", (void*)&e);

// __________________________________________________________________

//swapping variables using pointers
  *ptrtod = 13;
  *ptrtoe = 7;
  printf("The value of d is %d\n", d);
  printf("The value of e is %d\n", e);
}
