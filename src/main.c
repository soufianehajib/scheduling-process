#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/structure.h"
#include "../libs/function.h"
#include "../libs/fcfs.h"
#include "../libs/spf.h"
#include "../libs/prioriter.h"
int main(int argc , char *argv[]){
	if(argc != 2 ){

		printf("erro to much argument ") ; 
		exit(1) ;
	}
	processList l;
	initialiser(&l);
	if(strcmp(argv[1],"fcfs")== 0 ){
		
		start_FCFS_Processor(&l);
		Afficher(&l);

	}else if (strcmp(argv[1],"spf")== 0 ){
		
		start_spf_Processor (&l) ;
		Afficher(&l);
	}else if(strcmp(argv[1] ,"pty") == 0 ){
		start_prioriter_Processor (&l);
		Afficher(&l);

	}



   
	return 0 ; 

}