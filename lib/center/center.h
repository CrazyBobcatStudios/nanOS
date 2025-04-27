#ifndef CENTER_H
#define CENTER_H
#include "config.h"

inline int centerw(int padding){
  return(SCREEN_WIDTH - 2 * padding);
}

inline int centerh(int padding){
  return(SCREEN_HEIGHT - 2 * padding);
}

#endif