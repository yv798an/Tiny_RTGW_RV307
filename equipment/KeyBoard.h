#ifndef __KeyBOARD_H
#define __KeyBOARD_H

#include "ch32v30x.h"

void Keypad_Init(void);
char Key_Scan(void);
void Keypad_Task(void *parameter);

#endif