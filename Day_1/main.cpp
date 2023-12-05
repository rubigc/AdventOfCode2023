#include <string.h>
#include <stdio.h>
#include <list>
#include <stdlib.h>

char *numbersArray[] = {"one","two","three","four","five","six","seven","eight","nine","zero","1","2","3","4","5","6","7","8","9","0", "-1"};

int stringToNum(char* numberString){
  int returnNumber = 0;
  int x = 0;
  //cut out the rest of the string (since we got sent a buffer nothing should happen to the original pointer)
  while(numbersArray[x] != "-1"){
    char *found = 0;
    found = strstr(numberString, numbersArray[x]);
    if(found == numberString) {
      numberString[strlen(numbersArray[x])] = 0;
    }
    x++;
  }

  returnNumber = strtol(numberString, 0, 0);
  if(returnNumber != 0)
    return(returnNumber);
  else if(!strcmp(numberString,"one")){
    return(1);
  }
  else if(!strcmp(numberString,"two")){
    return(2);
  }
  else if(!strcmp(numberString,"three")){
    return(3);
  }
  else if(!strcmp(numberString,"four")){
    return(4);
  }
  else if(!strcmp(numberString,"five")){
    return(5);
  }
  else if(!strcmp(numberString,"six")){
    return(6);
  }
  else if(!strcmp(numberString,"seven")){
    return(7);
  }
  else if(!strcmp(numberString,"eight")){
    return(8);
  }
  else if(!strcmp(numberString,"nine")){
    return(9);
  }
  else
    return(0);
}

int findFirstNumber(char *inputLine){
  std::list<char*> numberList{};
  int x = 0;
  char foundBuffer[200] = "";
  while(numbersArray[x] != "-1"){
    char *found = 0;
    found = strstr(inputLine, numbersArray[x]);
    while (found != NULL) {
      strcpy(foundBuffer, found);
      numberList.push_back(found);
      foundBuffer[strlen(numbersArray[x])] = 0;
      found = found + strlen(numbersArray[x]);
      found = strstr(found, numbersArray[x]);
    }
    x++;
  }
  numberList.sort();
  strcpy(foundBuffer, numberList.front());
  return(stringToNum(foundBuffer));
}

int findLastNumber(char *inputLine){
  std::list<char*> numberList{};
  int x = 0;
  char foundBuffer[200] = "";
  while(numbersArray[x] != "-1"){
    char *found = 0;
    found = strstr(inputLine, numbersArray[x]);
    while (found != NULL) {
      strcpy(foundBuffer, found);
      numberList.push_back(found);
      foundBuffer[strlen(numbersArray[x])] = 0;
      found = found + strlen(numbersArray[x]);
      found = strstr(found, numbersArray[x]);
    }
    x++;
  }
  numberList.sort();
  strcpy(foundBuffer, numberList.back());
  return(stringToNum(foundBuffer));
}

int main(){
  FILE *inputFile = 0;
  char inputText[200] = "";
  int currentDigit10 = 0;
  int currentDigit0 = 0;
  int currentNum = 0;
  int error = 0;
  int total = 0;
  inputFile = fopen("inputFile", "r");
  while(!error){
    fgets(inputText, sizeof(inputText), inputFile);

    currentDigit10 = findFirstNumber(inputText);
    currentDigit0 = findLastNumber(inputText);
    currentDigit10 *= 10;
    currentNum = currentDigit0 + currentDigit10;

    total = total + currentNum;
    printf("The Number for this line %d, Total = %d\n", currentNum, total);
    if(feof(inputFile))
      error = 1;
  }
  fclose(inputFile);

  printf("\nThe final Total number is: %d\n", total);
  return(0);
}