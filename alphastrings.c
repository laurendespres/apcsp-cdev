#include <stdio.h>
#include <string.h>

int main() {

//first string for alphabet
char str1[27];

for (int i = 0; i < 26; i++) {
  str1[i] = 'a' + i;
}
  str1[26] = '\0';

printf("%s\n", str1);
printf("The length of str1 is %d\n", strlen(str1));

//second string for alphabet
char str2[27] = "abcdefghijklmnopqrstuvwxyz";

printf("%s\n", str2);
printf("The length of str2 is %d\n", strlen(str2));

//comparing the strings
if (strcmp(str1, str2) == 0)
	printf("the strings are identical\n");
else
	printf("the strings are different\n");

// changing str1 to uppercase
for (int i = 0; i < 26; i++) {
  str1[i] -=32;
}
printf("%s\n", str1);
printf("The length of str1 is %d\n", strlen(str1));

//comparing the updated strings
if (strcmp(str1, str2) == 0)
	printf("the strings are identical\n");
else
	printf("the strings are different\n");

//third string
strcat(str2, str1);
printf("%s\n", str2);
}
