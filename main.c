#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  FILE *file = NULL;
  char message[100];
  
  while(true){
    printf("Enter w, r or c: ");
    fflush(stdin);
    scanf("%s", message);

    if(!strcmp(message, "w")) {
      puts("Enter text: ");
      fflush(stdin);
      scanf("%s", message);
      file = fopen("text.txt", "w");

      if(file == NULL){
        puts("Impossible to open a file!");
        exit(0);
      }

      fprintf(file, "%s", message);
      fclose(file);
      }

    else if(!strcmp(message, "c")) {
      unlink("text.txt");
      }

    if(!strcmp(message, "r")) {
      file = fopen("text.txt", "r");
      if(file == NULL){
        puts("The file is empty!");
        exit(0);
      }

      fgets(message, 50, file);
      fclose(file);
      puts(message);
    }
  }
}