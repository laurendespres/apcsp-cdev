#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], float* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%f", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
double areaOfCircle(double start){

  return start * start * M_PI;
}

int main(int argc, char* argv[]) 
{
//check to see if two args were inputted

if (argc != 3){
	printf("%s : expected 2 args, please enter two integers\n", argv[0]);
	return 1;
}

// scan arg1 to see if it is an integer
int arg1; 

 int found = sscanf(argv[1], "%d", &arg1);
   if (found != 1)
{
	printf("first arg is not an integer, enter two ints\n");
	return 1;
}
//positive check for arg1 
int integer =  sscanf(argv[1], "%d", &arg1);
  if (integer <= 0) 
{
	printf("first arg is a negative integer, enter a positive integer\n");
	return 1;
}
//scan arg2 to see if it is an integer
   int arg2;
   found = sscanf(argv[2], "%d", &arg2);
   if (found != 1)
{
	printf("second arg is not an integer, enter two ints\n");
	return 1;
}
//positive check for arg2
  integer =  sscanf(argv[2], "%d", &arg2);
  if (integer <= 0) 
{
        printf("second arg is a negative integer, enter a positive integer\n");
        return 1;
}
//check to see that arg2 is greater than arg1
  if (arg1 >= arg2)
{
	printf("please make sure that arg2 is greater than arg1\n");
	return 1;
}

  // the two variables which control the number of times areaOfCircle is called
  // in this case 5.2, 6.2, 7.2
  float start = arg1;
  int reps = 3;
  
  // for testing only - do not change
  getTestInput(argc, argv, &start, &reps);

  printf("input lower: %d\n", arg1);
  printf("input upper: %d\n", arg2);
  
  // add your code below to call areaOfCircle function with values between
  // start and end

for (float i = arg1; i < arg2+1; i++){
	printf("The area of the circle is %f\n", areaOfCircle(i));
}
}
