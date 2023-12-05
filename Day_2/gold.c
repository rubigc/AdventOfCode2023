#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BLUE 14
#define MAX_GREEN 13
#define MAX_RED 12

char *gameTypes[] = {"blue", "red", "green", "-1"};

/**
 * @brief 
 * 
 * @param gameToCheck 
 * @return int returns the power of the minimum ammount of cubes
 */
int checkGamePower(char *gameToCheck){
  int maxCubes[] = {0, 0, 0};
  int x = 0;
  int gameId = 0;
  while(gameTypes[x] != "-1"){
    char *found = 0;
    found = strstr(gameToCheck, gameTypes[x]);
    while(found != NULL){
      if(strtol(found-3, 0, 0) > maxCubes[x])
        maxCubes[x] = strtol(found-3, 0, 0);
      found = found + strlen(gameTypes[x]);
      found = strstr(found, gameTypes[x]);
    }
    x++;
  }
  gameId = strtol(gameToCheck+4, 0, 0);
  return(maxCubes[0] * maxCubes[1] * maxCubes[2]);
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
    
    currentLine = checkGamePower(inputText);
    total = total + currentLine;
    printf("current line: %d, total: %d\n", currentLine, total);

    if(feof(inputFile))
      error = 1;
  }
  fclose(inputFile);

  printf("Grand total result = %d\n", total);
  return(0);
}