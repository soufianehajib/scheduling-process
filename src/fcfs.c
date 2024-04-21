#include "../libs/function.h"
#include <stddef.h>
#include<string.h>
process *chossingaprocess(processList* l){

    process *selectprocess ; 
    selectprocess = NULL  ; 

    for(int i=0; i<l->processNbr; i++){
        if(l->allProcess[i].status == ready ){
            selectprocess = l->allProcess + i ; 
            break ; 


        }
		
	}
    if(selectprocess == NULL ){


        return 0 ; 
    }
    for(int i=0; i<l->processNbr; i++){
        if( l->allProcess[i].status == ready  && selectprocess->arrivaleDate > l->allProcess[i].arrivaleDate){
            selectprocess = l->allProcess + i ; 
           


        }
		
	}
    
    return selectprocess ; 


}
void start_FCFS_Processor (processList* l){ 

    int clock = 0  ; 
    process * runningprocess ; 
    runningprocess = NULL ; 
    int i ; 
   
    while(isalltheprocesscomplete(l) != 1 ){
        update_all_process (l,clock);
        runningprocess = chossingaprocess(l) ; 
       if(runningprocess -> status == ready ){

            runningprocess->realExecTime += 1;
            runningprocess->status = running;
            clock ++ ; 
            l->contextChangeNbre++;
            l->execString[strlen(l->execString)+1] = '\0';
			l->execString[strlen(l->execString)] = runningprocess->processName[0];

            if(runningprocess->realExecTime == runningprocess->execTime){
				runningprocess->status = zombie;
				runningprocess->endDate = clock;
			}
       }else{
        clock++ ; 
       }
        //runningprocess = chossingaprocess( l) ;
        




    }






}