

 #ifndef SYMBOL
 #define SYMBOL  
 
 namespace bgcc {

 	#include "log.h"

    #define  INFO(DEVICE ,FORMAT...)   BGCC_NOTICE(DEVICE,FORMAT...)
    #define  WARN(DEVICE ,FORMAT...)   BGCC_WARN(DEVICE,FORMAT...)
    #define  ERROR(DEVICE ,FORMAT...)  BGCC_ERROR(DEVICE,FORMAT...)


 
 } // bgcc

   




 #endif