#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int main() {
  char input[2046];
  char password[20];

  FILE *passfile = fopen("password.txt", "r");
  if(passfile == NULL) {
  printf("Enter Password.\n> ");
  fgets(password, sizeof(password), stdin);
  password[strcspn(password, "\n")] = '\0';

  passfile = fopen("password.txt", "w");
  if (passfile == NULL) {
    printf("Error\n");
    return 1; }
  fprintf(passfile, "%s", password);
  fclose(passfile);
  printf("Password file created success\n"); } else {
    fclose(passfile);
    printf("Finish"); }

  int ret = mkdir("Diary1", 0755);
  if (ret != 0) {
    printf("Error\n");
    return 1; }

  printf("Enter text\n> ");
  fgets(input, sizeof(input), stdin);
  FILE *file = fopen("Diary1/Diary1.txt", "w");
  if(file == NULL) {
    printf("Error opening diary file.\n");
    return 1; }

  fprintf(file, "%s\n", input);
  fclose(file);

  printf("Diary successfully.\n");
  return 0; }
