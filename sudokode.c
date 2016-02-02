/*Neal Nguyen
  PID:2699498
  COP3502*/
#include <stdio.h>
#include <stdlib.h>
int rowTest(int arr[9][9] );
int columnTest(int ar[9][9]);
int boxTest(int ar[9][9]);
int main()
{
    int grid = 0;
    int runtime = 0;
    int ar[9][9];
    int row = 0;
    int column = 0;
    int c = 2;
    int d = 2;
    int e = 2;
	//input how many puzzle will be check
    scanf("%d",&grid);
    //input files from provided input files
    while(runtime != grid) // check and see if the program used every game given
    {
        //nested for loop to fill in the sudokode array
        for (row = 0; row<9;row++)
            {
                for(column = 0; column< 9;column++)
                {
                	//input the number to a 2D array
                    scanf("%d",&(ar[row][column]));
                }

            }

    //increase run time by one after run through the loop once
    runtime++;
    // set c,d ,e to the return value each test give
    c = rowTest(ar);
    d = columnTest(ar);
    e = boxTest(ar);
    // check if the puzzle had pass the row, column and box test
    if( (c==1) && (d==1) && (e==1) )
    {
        printf("YES\n");
    }
    else
        printf("NO\n");

    }//end of while loop
    return 0;
    }



int rowTest(int ar[9][9])
{
    int i,j,k;
    //loop through every element to check for duplicate in row
    for(i = 0; i < 9 ;i ++)
        {
            for(j = 0; j <9;j++)
            {
                for(k = (j+1); k < 9;k++)
                // k = the elements that are being compare to
                if(ar[i][j] == ar[i][k])
                //return 0 if duplicate is found
                    return 0;
            }
        }
    //return 1 if no duplicate is found after run through the whole loop
    return 1;
}

int columnTest(int ar[9][9])
{
    int i,j,k;
    // run through the puzzle to check for duplicate in column
    for(i = 0; i < 9 ;i ++)
        {
            for(j = 0; j <9;j++)
            {
                for(k = (j+1); k < 9;k++)
                if(ar[j][i] == ar[k][i])
                    //return 0 if duplicate are found
                    return 0;
            }
        }
    //return 1 if no duplicate is found
    return 1;
}

int boxTest(int ar[9][9])
{
    int arr2[9][9];
    int i,j,k = 0,l;
    // convert 3x3 boxes into row of another array
    for(l = 0;l < 9 ;l++)
    {
            for(i =(3*(l/3));i<(3*( (l/3)+1) );i++)
            {
                for(j= (3* (l%3) ); j<(3*( ( l % 3 ) + 1 ) ) ; j++)
                {
                    arr2[l][k] = ar[i][j];
                    k++;
                }
            }
            k = 0;
    }
 //call rowtest function to check for duplicate in box
 return rowTest(arr2);
}
