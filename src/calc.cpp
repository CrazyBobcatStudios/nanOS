#include "config.h"
#include <math.h>

int selectedCalc = 0;
int row = 0;
int column = 0;
char* currentCalc = 0;

const char* calcsymbols[] ={
    "7","8","9","/","4","5","6","x","1","2","3","-","c","0","=","+"
};

void calcLPress(){
    if (selectedCalc < 16){
        selectedCalc++;
    }
}

void calcMPress(){
    
}

void calcRPress(){
    if (selectedCalc > 0){
        selectedCalc--;
    }
}

void calcLoop(){
    int i = 0;
    while(i<16){
        int row = floor(i/4);
        int column = (i % 4);
        display.drawRect(column * 32, (row * 12)+ 12, 32, 12, COLOR);
        i++;
    }

    int selectedRow = selectedCalc / 4;
    int selectedColumn = selectedCalc % 4;
    display.fillRect(selectedColumn * 32, (selectedRow * 12) + 12, 32, 12, COLOR);
    Serial.println(selectedCalc);
}