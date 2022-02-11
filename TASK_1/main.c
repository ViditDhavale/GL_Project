/***************************************************************************/
/**                      Include Section                                   */
/***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <poll.h> 
#include "compile_standards.h"
#include "types.h"
#include "main.h"


/***************************************************************************/
/**                      Initialization of variables                       */
/***************************************************************************/
/* Global variables*/
uint8 loop_iteration_counter= 0;
uint8 txt_arr[MAX_LIMIT];
uint8 start_flag= 0;
uint8 pat_arr[MAX_LIMIT]= "GLROX";
uint8 Clear_string_var= 0;


/***************************************************************************/
/**                      Static variables                                  */
/***************************************************************************/
struct pollfd mypoll = { STDIN_FILENO, POLLIN|POLLPRI };
static clock_t start_time = 0;



/******************************************************************************/
/** Function Name        : Search_Func	 	                             	  */
/**                                                                           */
/** Description          : This operation performs the bubble sorting of the  */
/**                        data pattern received and comparison with the      */
/**						   pattern "GLROX"	                    			  */
/**                        			                          				  */
/******************************************************************************/
void Search_Func
(
uint8* pat_arr,
uint8* txt_arr
)
{
	uint8 Pattern_Max = strlen(pat_arr);
	uint8 Character_Max = strlen(txt_arr);

	uint8 Pattern_loop_var ;
	uint8 value_var ;
 
	uint8 temp_arr[5]="";
	uint8 Character_loop_var ;

	
	
    /* A loop to slide pat_arr[] one by one */ 
 for (Character_loop_var = 0; Character_loop_var <= Character_Max ; Character_loop_var++) 
	{
        /* For current index Character_loop_var, check for pattern match */
        for ( Pattern_loop_var=0 ;Pattern_loop_var<Pattern_Max;Pattern_loop_var++ )
		{
			if (txt_arr[Character_loop_var] == pat_arr[Pattern_loop_var])
			{
				strncat(temp_arr, &txt_arr[Character_loop_var], 1);
				if (temp_arr[4]!= '\0')
				{
					goto exitloop;//Exit when 'temp_arr' filled
				}
			}
			else
			{
        //printf("\nString NOT found yet!!\nFALSE");
			}
		}   
    }
	
exitloop:
 printf("\nAfter search function temp_arr is :%s", temp_arr);		
 value_var = strcmp(temp_arr,pat_arr); 
		if (value_var == 0)
		{
			printf("\n\n!!String ""GLROX"" has been Found!!");
			printf("\nTRUE");
			printf("\nContinue giving the next set of input");
		}

		else
		{
			printf("\n\n!!String Not Found yet!!");
			printf("\nFALSE");
			printf("\nContinue giving the input characters");
		}
			
}


/******************************************************************************/
/** Function Name        : Bsw_100ms_Core0 	                             	  */
/**                                                                           */
/** Description          : This operation performs the processing of data 	  */
/**                        every 100ms and prints the time it waits for next  */
/**                        input	                          				  */
/**                        			                          				  */
/** Function(s) invoked  : 1. clock		                         			  */
/**                        			                          				  */
/******************************************************************************/
void Bsw_100ms_Core0
(
	void
)
{
	/*Local variables*/
	uint8 wait_in_ms = 100;
	
	//Introduces a wait for 100ms
	start_time = clock();
	printf("\n\nStart time = %ld ms", start_time);
	while (clock() < (start_time + wait_in_ms))
		{
			clock();
		}
	   printf("\nEnd time = %ld ms", clock());//(start_time + wait_in_ms));
	   printf("\nWaited %ld ms before next input",(clock() - start_time));
 
}/*End of Bsw_100ms_Core0*/



/******************************************************************************/
/** Function Name        : ProcessFunc 	                                  	  */
/**                                                                           */
/** Description          : This operation performs the processing of received */
/**                        input characters and waits for 2 seconds for next  */
/**                        input and if no character is provided it calls a   */
/**                        timeout     										  */
/**                        			                          				  */
/** Function(s) invoked  : 1. Search_Func		                         	  */
/**                        			                          				  */
/******************************************************************************/
void ProcessFunc
(
	void
)
{
	/*Local variables*/
	uint8 input; /*Stores the input from user*/
	
	if( poll(&mypoll, 1, 3000) ) //Modify timeout (3000 for 2 seconds)
	{
		scanf("%s", &input);
	}
	else
	{
		loop_iteration_counter=0;
		printf("\n \nTimeout...! No input for 2 seconds\n");
    /*Clears the temp_arr at timeout*/
    for (size_t Clear_loop_var = 0; Clear_loop_var < sizeof txt_arr; ++Clear_loop_var)
    {
      txt_arr[Clear_loop_var]=0;
      Clear_string_var=1;
    }
    
   
	}
    strncat(txt_arr, &input, 1);

		++loop_iteration_counter;
		printf("\n Iteration for input character: %d", loop_iteration_counter);
	/*Clears the printing of temp_arr at timeout*/
    if(Clear_string_var==1)
    {
      printf("\n\nInput String for compare is emptied");
    }
    else
    {
		printf("\nThe string entered = %s", txt_arr);
    }


	if (loop_iteration_counter > 4) 
	{
      printf("\n\nInput String for compare is: %s", txt_arr);
		  Search_Func(pat_arr, txt_arr);
		
	} 
}/*End of ProcessFunc*/



/******************************************************************************/
/** Function Name        : main 	                                  */
/**                                                                           */
/** Description          : This operation performs the scanning of input 	  */
/** 				       character by character. It inputs characters every */
/**                        100ms											  */
/**                                                                           */
/** Function(s) invoked  : 1. Bsw_100ms_Core0                        	      */
/**                        2. ProcessFunc			                          */
/******************************************************************************/
int main()
{
printf("\n!!....Please Input single character to buffer....!! \n!!....and press ENTER to input next character....!! \n\n!.....Please input character within 2 seconds....! ");

/* This is a continuous loop for taking input from user */
	while(1)
		{
		/* 100ms processing of data function  */
			Bsw_100ms_Core0();
			
		/* Processing of input data and searching of the pattern  */
			ProcessFunc();
		}

}/*End of main*/

/***************************************************************************************************
*                                          End of File                                            *
**************************************************************************************************/
