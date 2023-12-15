#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
  The program first copies everything into a 2 dimesional array which makes parsing the string easier afterwards
  Then searches through each line until it finds a symbol 
  (it skips the first line and asumes the input doesnt have any symbols on edges since this is the case atleast with my input)
*/

char symbols[] = {'@', '*', '#', '+', '-', '$', '/', '&', '=', '%'};

//should return an int of the adjecent numbers of the string sent
int adjecentNumbersCheck(char *charArray){
  int result = 0;
  int length = 0;
  char *searchArray = charArray;
  char *firstNum = 0;
  char *lastNum = 0;

  if(!isdigit(*searchArray)){
    return (0);
  }
//search first number
  if(isdigit(*(searchArray-1))){
    if(isdigit(*(searchArray-2))){
      if(isdigit(*(searchArray-3)))
        firstNum = searchArray-3;
      else
        firstNum = searchArray-2;
    }
    else
      firstNum = searchArray-1;
  }
  else
    firstNum = searchArray;

//search last number
  if(isdigit(*searchArray+1)){
    if(isdigit(*searchArray+2))
      lastNum =searchArray+2;
    else
      lastNum = searchArray+1;
  }
  else
    lastNum = searchArray;

//hoping atoi doesnt troll me
  result = atoi(firstNum);

//hacky approach to not find the same number twice
  length = lastNum - firstNum;
  for(int x = 0; length > x; x++)
    firstNum[x] = '.';

  return(result);
}

int numbersCheck(char charArray[140][141], int row, int column){
  int totalNum = 0;

  totalNum = totalNum + adjecentNumbersCheck(charArray[row]+column+1);
  totalNum = totalNum + adjecentNumbersCheck(charArray[row]+column-1);

  totalNum = totalNum + adjecentNumbersCheck(charArray[row+1]+column+1);
  totalNum = totalNum + adjecentNumbersCheck(charArray[row+1]+column);
  totalNum = totalNum + adjecentNumbersCheck(charArray[row+1]+column-1);

  totalNum = totalNum + adjecentNumbersCheck(charArray[row-1]+column+1);
  totalNum = totalNum + adjecentNumbersCheck(charArray[row-1]+column);
  totalNum = totalNum + adjecentNumbersCheck(charArray[row-1]+column-1);



  return(totalNum);
}

int isSymbol(char checkChar){
  if(checkChar == symbols[0] 
    || checkChar == symbols[1]
    || checkChar == symbols[2]
    || checkChar == symbols[3]
    || checkChar == symbols[4]
    || checkChar == symbols[5]
    || checkChar == symbols[6]
    || checkChar == symbols[7]
    || checkChar == symbols[8]
    || checkChar == symbols[9]
    ){
    return(1);
  }

  return(0);
}



int ArraySymbolCheck(char inputArray[140][141]){
  int total = 0;
  for(int row = 0; row < 140; row++){
      for(int column = 0; column < 141;column++){
        if(isSymbol(inputArray[row][column])){
          total = total + numbersCheck(inputArray, row, column);
        }
      }
  }
  return(total);
}

int main(){
  FILE *inputFile = 0;
  char inputArray[140][141];
  int result = 0;

  for (int i = 0; i < 140; i++) {
    memset(inputArray[i], 0, 141);
  }

  inputFile = fopen("inputFile", "r");

  for(int x = 0; x < 140; x++){
    fscanf(inputFile, "%s", inputArray[x]);
  }
  result = ArraySymbolCheck(inputArray);
  printf("%d\n", result);

  fclose(inputFile);
  return(0);
}