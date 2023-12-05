#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLUE 14
#define MAX_GREEN 13
#define MAX_RED 12

char *gameTypes[] = {"blue", "red", "green", "-1"};
int maxCubes[] = {MAX_BLUE, MAX_RED, MAX_GREEN};



/**
 * @brief 
 * 
 * @param gameToCheck 
 * @return int if valid returns the game id if invalid returns 0
 */
int checkGameValid(char *gameToCheck){
  int x = 0;
  int gameId = 0;
  while(gameTypes[x] != "-1"){
    char *found = 0;
    found = strstr(gameToCheck, gameTypes[x]);
    while(found != NULL){
      if(strtol(found-3, 0, 0) > maxCubes[x])
        return(0);
      found = found + strlen(gameTypes[x]);
      found = strstr(found, gameTypes[x]);
    }
    x++;
  }
  gameId = strtol(gameToCheck+4, 0, 0);
  return(gameId);
}

int main(){
  FILE *inputFile = 0;
  int error = 0;
  int currentLine = 0;
  int total = 0;
  char inputText[300] = "";

  inputFile = fopen("inputFile", "r");
  
  while(!error){
    fgets(inputText, sizeof(inputText), inputFile);
    
    currentLine = checkGameValid(inputText);
    total = total + currentLine;
    printf("current line: %d, total: %d\n", currentLine, total);

    if(feof(inputFile))
      error = 1;
  }
  fclose(inputFile);

  printf("Grand total result = %d\n", total);
  return(0);
}