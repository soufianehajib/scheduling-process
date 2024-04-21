#include "../libs/function.h"
#include <stddef.h>
#include<string.h>



process *chossingaprocessspf(processList* l){

    process *selectprocess ; 
    selectprocess = NULL  ; 
    int i ; 
    for( i=0; i<l->processNbr; i++){
        if(l->allProcess[i].status == ready ){
            selectprocess = l->allProcess + i ; 
            break ; 


        }
		
	}
    if(selectprocess == NULL ){


        return 0 ; 
    }
    if(selectprocess->realExecTime != 0 ){
        for(i=0; i<l->processNbr; i++){
            if( l->allProcess[i].status == ready  && selectprocess->arrivaleDate > l->allProcess[i].arrivaleDate){
                
                    selectprocess = l->allProcess + i ; 
                
                    
            

            }
        
		
	    }
    }else{
        for(i=0; i<l->processNbr; i++){
            if( l->allProcess[i].status == ready  && selectprocess->execTime > l->allProcess[i].execTime){
                
                    selectprocess = l->allProcess + i ; 
                
                    
            

            }
        
		
	    }

    }
    
  
    
    return selectprocess ; 


}

void start_spf_Processor (processList* l){ 

    int clock = 0  ; 
    process * runningprocess ; 
    runningprocess = NULL ; 
    int i ; 
   
    while(isalltheprocesscomplete(l) != 1 ){
        update_all_process (l,clock);
        runningprocess = chossingaprocessspf(l) ;  

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
        
        




    }






}