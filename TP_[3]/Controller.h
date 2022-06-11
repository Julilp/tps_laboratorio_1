#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger,Type* eTipo);
int controller_removePassenger(LinkedList* pArrayListPassenger,Type* eTipo);
int controller_ListPassenger(LinkedList* pArrayListPassenger,Type eTipo[]);
int controller_sortPassenger(LinkedList* pArrayListPassenger,Type* eTipo);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);


