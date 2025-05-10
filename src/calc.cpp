#include "config.h"
#include <math.h>

int selectedCalc = 0;
int row = 0;
int column = 0;
char* currentCalc = 0;
int calc1;
int calc2;
int opendCalc;
const char* opperand = "+";
int answer = 0;
int answered = 0;
int remain;

const char* calcsymbols[] ={
  "7","8","9","/","4","5","6","x","1","2","3","-","c","0","=","+"
};

void calcLPress(){
  if (selectedCalc > 0){
    selectedCalc--;
  }
}

void calcMPress(){
  if (selectedCalc == 3 or selectedCalc == 7 or selectedCalc == 11 or selectedCalc == 15){
    opperand = calcsymbols[selectedCalc];
    if(opendCalc == 0){
        opendCalc = 1;
    }
    else{
        opendCalc = 0;
    }
  }
  if (selectedCalc != 3 && selectedCalc != 7 && selectedCalc != 11 && selectedCalc != 14 && selectedCalc != 15){
    if (opendCalc != 1){
      if (calc1 != 0){
        calc1 = std::stoi(std::to_string(calc1) + calcsymbols[selectedCalc]);
      }
      else{
        calc1 = std::stoi(calcsymbols[selectedCalc]);
      }
    }
  else{
    if (calc2 != 0){
      calc2 = std::stoi(std::to_string(calc2) + calcsymbols[selectedCalc]);
    }
    else{
      calc2 = std::stoi(calcsymbols[selectedCalc]);
    }
  }
}
if (selectedCalc == 12){
  calc1 = 0;
  calc2 = 0;
  opendCalc = 0;
  answered = 0;
  remain = 0;
}
if(selectedCalc == 14){
  if (opperand == "+"){
    answer = calc1 + calc2;
  }
  if (opperand == "-"){
    answer = calc1 - calc2;
  }
  if (opperand == "/"){
    answer = calc1 / calc2;
    remain = calc1 % calc2;
  }
  if (opperand == "x"){
    answer = calc1 * calc2;
  }
  answered = 1;
}
}

void calcRPress(){
  if (selectedCalc < 15){
    selectedCalc++;
  }
}

void calcLoop(){
  display.setCursor(1,1);
  if (answered == 0){
    display.print(calc1);
    display.print(opperand);
    display.print(calc2);
  }

  else{
    display.print(answer);
    if (remain != 0){
      display.print(" R:");
      display.print(remain);
    }
  }
  
  int i = 0;
  while(i<16){
    int row = floor(i/4);
    int column = (i % 4);
    display.drawRect(column * 32, (row * 12)+ 12, 32, 12, COLOR);
    display.setCursor(column * 32 + 14, (row * 12)+ 14);
    display.print(calcsymbols[i]);
    i++;
  }

  display.setTextColor(BLACK);
  int selectedRow = selectedCalc / 4;
  int selectedColumn = selectedCalc % 4;
  display.fillRect(selectedColumn * 32, (selectedRow * 12) + 12, 32, 12, COLOR);
  display.setCursor(selectedColumn * 32 + 14, (selectedRow * 12)+ 14);
  display.print(calcsymbols[selectedCalc]);
  display.setTextColor(COLOR);
}