//to find the number of ways of the matrix multiplication using recursion

#include <stdio.h>

	
int arrangement(int n)		//function to find the number of arrangements
{
    if(n==1||n==2)		//base case
    {
        return 1;
    }
    else
    {
        return arrangement(n-1)+(n-1)*arrangement(n-2);		//recursive call
    }
}

int main()		//main function
{
    int n;		//number of matrices to be multiplied
    printf("Enter the number of matrices to be multiplied ");
    scanf("%d",&n);
    int t=arrangement(n);	//number of arrangements
    printf("The number of ways of arranging the matrices for multiplication = %d",t);
	return 0;
}



