#ifndef STRUCTURES_H
#define STRUCTURES_H

#define ready 0 
#define running 1 
#define blocked 2 
#define zombie 3 

typedef struct {
   
	char processName[30];
	int arrivaleDate;
	int execTime;
	int priority;
	
	int status;
	int realExecTime;
	int endDate;



}process ; 

typedef struct {
    process* allProcess;
	int processNbr;
	
	char execString[100];
	int contextChangeNbre;


}processList ; 




#endif
