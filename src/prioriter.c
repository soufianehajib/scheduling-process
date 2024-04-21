#include "../libs/function.h"
#include <stddef.h>
#include<string.h>
process *chossingaprocessprioriter(processList* l){

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
    int i ; 
     if(selectprocess->realExecTime != 0 ){
        for(i=0; i<l->processNbr; i++){
            if( l->allProcess[i].status == ready  && selectprocess->arrivaleDate > l->allProcess[i].arrivaleDate){
                
                    selectprocess = l->allProcess + i ; 
                
                    
            

            }
        
		
	    }
    }else{
        for(i=0; i<l->processNbr; i++){
            if( l->allProcess[i].status == ready  && selectprocess->priority > l->allProcess[i].priority){
                
                    selectprocess = l->allProcess + i ; 
                
                    
            

            }
        
		
	    }

    }
    
    return selectprocess ; 


}
void start_prioriter_Processor (processList* l){ 

    int clock = 0  ; 
    process * runningprocess ; 
    runningprocess = NULL ; 
    int i ; 
   
    while(isalltheprocesscomplete(l) != 1 ){
        update_all_process (l,clock);
        runningprocess = chossingaprocessprioriter(l) ; 
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
       
        //runningprocess = chossingaprocess( l) ;
        




    





    }
}