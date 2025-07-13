#include "config.h"

int snekLength = 10;
int snekFacing = 1;
int boardsize = 20;
int snekXPos[] = {9,8,7,6,5,4,3,2,1,0};
int snekYPos[] = {0,0,0,0,0,0,0,0,0,0};
int fruitXPos[] = {0,1,2};
int fruitYPos[] = {0,1,2};
int cellWidth = SCREEN_WIDTH / boardsize;
int cellHeight = SCREEN_HEIGHT /boardsize;

void snekLoop(){
  //for(int i = 0; i < boardsize; i++){
  //  for(int x = 0; x < boardsize; x++){
  //    for(int y = 0; y < boardsize; y++){
  //      display.drawRect(x * cellWidth, y * cellHeight, cellWidth, cellHeight, COLOR);
  //    }
  //  }
  //}
  //for(int i = 0; i < 3; i++){
  //  display.fillRect(fruitXPos[i] * cellWidth, fruitYPos[i] * cellHeight, cellWidth, cellHeight, COLOR);
  //}
  for(int i = 0; i < snekLength; i++){
    display.fillRect(snekXPos[i] * cellWidth, snekYPos[i] * cellHeight, cellWidth, cellHeight, COLOR);
  }

  for (int i = snekLength - 1; i > 0; i--) {
    snekXPos[i] = snekXPos[i - 1];
    snekYPos[i] = snekYPos[i - 1];
  }

  if (snekFacing == 1) snekXPos[0]++;
    else if (snekFacing == 3) snekXPos[0]--;
    else if (snekFacing == 0) snekYPos[0]--;
    else if (snekFacing == 2) snekYPos[0]++;
  }

void SnekLPress(){
  if(snekFacing != 0){
    snekFacing--;
  }
  else{
    snekFacing = 3;
  }
}
void SnekMPress(){

}
void SnekRPress(){
  if(snekFacing != 3){
    snekFacing++;
  }
  else{
    snekFacing = 0;
  }
}