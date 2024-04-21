#include "../libs/structure.h"
#include<stdlib.h>
#include<stdio.h>

void initialiser(processList  *l ) {

	printf("how many process : ") ; 
	scanf("%d",&l->processNbr); 
    //l->processNbr = 5;
	l->contextChangeNbre = 0;
	
	l->allProcess = (process*)malloc(l->processNbr * sizeof(process));
	int i ;
	for(i  = 0 ; i< l->processNbr ; i++){
		printf("what's  the name of process %d: ", i+1) ;
		scanf("%s",&l->allProcess[i].processName[0] ); 
		printf("what is the exectime of process  %d : ", i+1) ;
		scanf("%d",&l->allProcess[i].execTime ); 
		printf("what's the arrivaldate of processs %d : " ,i+1);
		scanf("%d",&l->allProcess[i].arrivaleDate ); 
		printf("what's the priority of processs %d : " ,i+1);
		scanf("%d",&l->allProcess[i].priority); 
	}


	for(int i=0; i<l->processNbr; i++){
		l->allProcess[i].status = -1;
		l->allProcess[i].realExecTime = 0;
		l->allProcess[i].endDate = 0;
	}

}

void update_all_process (processList  *l , int clock ){

    int i ; 
    for( i = 0   ; i < l->processNbr ; i++){

        if(l->allProcess[i].arrivaleDate <= clock && l->allProcess[i].realExecTime < l->allProcess[i].execTime ){

            l->allProcess[i].status = ready  ;
        }

    }

}


int isalltheprocesscomplete (processList  *l){


    int i ; 
    for( i = 0   ; i < l->processNbr ; i++){

        if(l->allProcess[i].status != zombie ){

            return 0 ; 
        }

    }

    return 1 ; 


}


float TRM(processList* l){
	int s = 0;
	
	for(int i=0; i<l->processNbr; i++){
		s += (l->allProcess[i].endDate - l->allProcess[i].arrivaleDate);
	}
	
	return (float)s/l->processNbr;
}

float TAM(processList* l){
	int s = 0;
	
	for(int i=0; i<l->processNbr; i++){
		s += (l->allProcess[i].endDate - l->allProcess[i].arrivaleDate - l->allProcess[i].execTime);
	}
	
	return (float)s/l->processNbr;
}

void Afficher(processList* l){
 	printf("Exec String = %s, Nbre de changement de context = %d \n", l->execString, l->contextChangeNbre);
 	printf("TRM = %.2f, TAM = %.2f \n", TRM(l), TAM(l));
 	
 	printf("\n##### Porcess #######\n\n");
 	
 	for(int i=0; i<l->processNbr; i++){ 
		printf("Process %s, D.arrivee = %d, D.exec = %d, status = %d, R.exec = %d, D.end = %d \n", 
		l->allProcess[i].processName, l->allProcess[i].arrivaleDate, l->allProcess[i].execTime,
		l->allProcess[i].status, l->allProcess[i].realExecTime, l->allProcess[i].endDate );
	}
 	
}

