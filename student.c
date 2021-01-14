#include <stdio.h>
#include <string.h>


// student structure
//struct Student...

struct Student {
	char firstname[50];
	char lastname[50];
	int age;
	int studentid;
};

void printStudent(struct Student* student)
{
  printf("––––––––––––––––––Student–––––––––––––––––––––\n");
  printf("First name: %s\n", student->firstname);
  printf("Last name: %s\n", student->lastname);
  printf("Age: %d\n", student->age);
  printf("Student ID: %d\n", student->studentid);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for (int i = 0; i < num; i++){
	printStudent(students + i);
}
}

int main()

{

struct Student students[7];
char input[256];

  // an array of students
  //xxx students;

  int numStudents = 0;
  while (1)
  {
    char c;
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
    printf("What is your first name?\n");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &students[numStudents].firstname);

    printf("What is your last name?\n");
	fgets(input, 256, stdin);
	sscanf(input, "%s", &students[numStudents].lastname);

    printf("What is your age?\n");
    while(1){
	fgets(input, 256, stdin);
	if (sscanf(input, "%d", &students[numStudents].age) == 1) break;
	printf("Not a valid age - try again!\n");
}
    printf("What is your student ID?\n");
    while(1){
	fgets(input, 256, stdin);
	if (sscanf(input, "%d", &students[numStudents].studentid) == 1) break;
	printf("Not a valid student ID - try again!\n");
}

      numStudents++;
    }
  }
  
  printf("\nGoodbye!\n");
}
