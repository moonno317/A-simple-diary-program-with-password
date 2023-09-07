#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 20
int main() {
  char input[2046];
  char password[20];
  int diaryNumber = 1;
  char inputPassword[MAX_PASSWORD_LENGTH];
  char storedPassword[MAX_PASSWORD_LENGTH];

  FILE *passfile = fopen("password.txt", "r");
  if(passfile == NULL) {
      printf("Enter Password\n> ");
      fgets(password, sizeof(password), stdin);
      password[strcspn(password, "\n")] = '\0';
      passfile = fopen("password.txt", "w");
      if(passfile == NULL) {
          printf("error\n");
          return 1; }
      fprintf(passfile, "%s\n", passfile);
      fclose(passfile);
      printf("Password file created success\n"); } else {
      fclose(passfile);
      printf("Finish"); }


  int ret = mkdir("Diary", 0755);
  if (ret != 0) {
      printf("Error\n");
      return 1; }

  struct stat st;
  while (1) {
      char diaryFileName[20];
      sprintf(diaryFileName, "Diary%d.txt", diaryNumber);
      if (stat(diaryFileName, &st) != 0 || !S_ISREG(st.st_mode)) {
          break; }
      diaryNumber++; }

  printf("Enter text\n> ");
  fgets(input, sizeof(input), stdin);
  char diaryFileName[20];
  sprintf(diaryFileName, "Diary%d.txt", diaryNumber);

  FILE *file = fopen(diaryFileName, "w");
  if (file == NULL) {
      printf("Error");
      return 1; }

          fprintf(file, "%s\n", input);
  fclose(file);

  printf("Finish, Thank You For Test :))\n");
return 0; }
