#include <stdio.h>   //input-output
#include <stdlib.h>  //for using rand function
#include <time.h>    //for using time functions


void generating_bingo_board(int array[]);



int main() {
	int play_again=1;   //the user wants to play again(entered 1)
	while(play_again){
	int A[8];
	int i,k,m;
	int trying=0;
	int number,programs_number,index;
	int bingo_counter=0;
	
	generating_bingo_board(A);  //8element,min1,max100
	printf("\t");
	
	//displaying bingo board
	for(i=0;i<8;i++)
	{
		printf("%d ",A[i]); //an array with 8 random numbers
	}
	printf("\n");
	
	
	
    turnback:
	    printf("enter a number(or 0 for random number/-1 to quit): ");
	    scanf("%d",&number);
			
	    if(number==-1)  //exit
	    {
	    	exit(0);
		}
		
		if(number==0) //program will guess
		{
			trying++;  //it increases each step
			srand(time(0));   //time(0) - different random numbers in every execution
			programs_number=(rand()%100)+1;
			printf("%d\n",programs_number);
			int index=-1;
			for(k=0;k<8;k++)
			{
				if(programs_number==A[k])
				{
					index=i;
					break;
				}
			}
			if(index!=-1)
			{
				A[k]=3;           //symbolic number(instead of 'X' bc its ASCII code 88 and it gives a problem)
				bingo_counter++;  //it counts X
			}
		}
		
		//the user will guess
		int index_2=-1;
		for(k=0;k<8;k++)
		{
			if(number==A[k])
			{
				index_2=i;
				break;
			}
		}
		if(index_2!=-1)
		{
			trying++;  //it increases each step
			bingo_counter++; //it counts X
			A[k]=3;  //symbolic X
		}	
		
		//prints the current array
		for(m=0;m<8;m++)     
        {
		    if(A[m]==3)  //if it equals to the symbolic X (which is 3)
		    {
			    printf("X ");  //print X
		    }
		    else
		    {
			    printf("%d ",A[m]);
		    }
	    }
	    printf("\n"); //new line for next step
	
	
	
	if(bingo_counter==8) //the output: X X X X X X X X 
	{
		printf("BINGO!! You won!\n");
	    printf("Total numbers of tries: %d\n",trying);
	}
	else
	{
		goto turnback;
	}
	printf("Do you want to play again(1-Yes/0-No): ");
	scanf("%d",&play_again);
	printf("\n");


    }
	return 0;
}

void generating_bingo_board(int array[])
{
	printf("----------------------------------\n");
	printf("---------- Bingo Game! -----------\n");
	printf("----------------------------------\n");
    int random_number;
    int i,j;
    srand(time(NULL)); //random seed
    for(i=0;i<8;i++)
    {
    	random_number=(rand()%100)+1;    //between 0-100 numbers //+1 bc 100 included
    	for(j=0;j<i;j++)
    	{
    		if(random_number==array[j])
    		{
    			i--;  //i decreases bc we will go to the previous step
    			break;
			}
		}
		if(j==i)   //random_number is not in the array   
		{
			array[i]=random_number;   //add in the array
		}
	}
}





