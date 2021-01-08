#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char c = 'b';

  // print value and size of char variable
  printf("char c value: %c and size: %lu bytes\n", c, sizeof(c));

  float f = 12.345;
  //print value and size of float variable
  printf("float f value: %f and size: %lu bytes\n", f, sizeof(f));

  double d = 123.456;
  //print value and size of double variable
  printf("float d value: %d and size: %lu bytes\n", d, sizeof(d));

  float z = 13.789;
  //print value and size of float variable
  printf("float z value: %z and size: %lu bytes\n", z, sizeof(z));

 int p = 13;
  //print value and size of int variable
  printf("int p value: %d and size: %lu bytes\n", p, sizeof(p));  
}

