/***************************************************************************/
/**                      Include Section                                   */
/***************************************************************************/
#include <stdio.h>



/******************************************************************************/
/** Function Name        : main 	                                  		  */
/**                                                                           */
/** Description          : This operation performs the scanning of input 	  */
/** 				       lowest and highest number of the range and then	  */
/**                        evaluate the number is divisible by 3,5 or both.   */
/**                                                                           */
/******************************************************************************/
int main()
{
    int input_number;
	int max_number;
	int iteration_counter;
	
    /* Input lower and higher number from user */
    printf("Enter lowest number of range:\n ");
    scanf("%d", &input_number);
	printf("Enter highest number of range:\n ");
    scanf("%d", &max_number);
	for (iteration_counter=input_number ;iteration_counter<= max_number;iteration_counter++)
		{
			if (input_number==0)
			{
				printf("%d\n",input_number);
			}
			else if((input_number % 3 == 0) && (input_number % 5 == 0))
    		{
        		printf("GlobalLogic\n");/* Input divisible by both 3 and 5 */
   			}
    		else if ((input_number % 3 == 0))
    		{
       			 printf("Global\n");/* Input divisible by 3 */
    		}
			else if ((input_number % 5 == 0))
			{
				printf("Logic\n");/* Input divisible by 5 */
			}
			else
			{
				printf("%d\n",input_number);
			}
			input_number++;
		}
    
    return 0;
}/*End of Main_Function*/

/***************************************************************************************************
*                                          End of File                                            *
**************************************************************************************************/
