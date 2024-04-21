#include "./structure.h"


void initialiser(processList  *l ) ; 
void update_all_process (processList  *l, int clock );
int isalltheprocesscomplete (processList  *l); 
float TRM(processList* l);
float TAM(processList* l);
void Afficher(processList* l);