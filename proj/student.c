//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"


const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

  Student* st = malloc(sizeof(Student));

  st -> firstName = malloc(strlen(fname)+1);
  strcpy(st -> firstName, fname);

  st -> lastName = malloc(strlen(lname) + 1);
  strcpy(st -> lastName, lname);

  st -> age = age;
  st -> id = id;

  students[numStudents] = st;
  numStudents++;

}


void deleteStudent(Student* student)
{
  // free the memory associated with a student including the strings

free(student -> firstName);
free(student -> lastName);

free(student);
}
void deleteStudents()
{
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0

for (int i = 0; i < numStudents; i++){
  deleteStudents(students[i]);
}
  numStudents = 0;
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532
  // the best way to do this is to convert the student data to a string using sprintf and then
  // (optionally) encrypt the whole string before writing it to disk (see cdemo/fileio3.c)

FILE* fp = fopen(STUFILE, "w");
if(fp){

for(int i = 0; i < numStudents; i++){
  int keys[1];
  keys[0]=key;
  encrypt(students[i]->firstName, keys, 1);
  encrypt(students[i]->lastName, keys, 1);
  char ageString[256];
  char idString[256];
  sprintf(ageString, "%d", students[i]->age);
  sprintf(idString, "%ld", students[i]->id);
  encrypt(ageString, keys, 1);
  encrypt(idString, keys, 1);
 
     printf("saving: %s %s %s %s\n", students[i]->firstName, students[i]->lastName, ageString, idString);
     fprintf(fp, "%s %s %s %s\n", students[i]->firstName, students[i]->lastName, ageString, idString);
}
	printf("saved %d students\n", numStudents);
	fclose(fp);
}
}

void loadStudents(int key)
{
  // load the students from the data file overwriting all exisiting students in memory
  //  - make sure you first deleteStudents before loading new ones
  //  - when loading it is best to load data into four strings and then (optionally) decrypt the
  //    strings
  //  - call createStudent to correctly create the students
deleteStudents();

FILE* fp = fopen(STUFILE, "r");
if (fp){
  char firstName[256];
  char lastName[256];
  char ageString[256];
  char idString[256];
  int age;
  long id;
  int n = 0;
  numStudents = 0;
  do{
	n = fscanf(fp, "%s %s %s %s\n", firstName, lastName, ageString, idString);
	if(n>0){

	int keys[1];
	keys[0]=key;
	decrypt(firstName, keys, 1);
	decrypt(lastName, keys, 1);
	decrypt(ageString, keys, 1);
	decrypt(idString, keys, 1);
	sscanf(ageString, "%d", &age);
	sscanf(idString, "%ld", &id);
	createStudent(firstName, lastName, age, id);
}
}
while(n>0);
fclose(fp);
}
}

void printStudent(Student* students)
{
  printf("  Student: %s %s\n", students->firstName, students->lastName);
  printf("    age: %d\n", students->age);
  printf("    id: %ld\n", students->id); 


}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




