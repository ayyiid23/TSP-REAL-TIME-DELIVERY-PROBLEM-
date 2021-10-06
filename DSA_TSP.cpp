#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float max_value= 10000.0;
int arr[10];
float queue(float cost_array[10][10],int n)					// Classic Queue implementation
{
    float queue_cost=0;
    for(int i=0; i<n; i++)
    {
        if(i==(n-1))
            queue_cost+=cost_array[i][0];
        else
            queue_cost+=cost_array[i][i+1];
    }
    return queue_cost;
}
/*
    start from 1st position in duplicate cost matrix.
    find minimum in that sub array(1D),add it to the cost variable, and make (all the elements of that row and all elements of the column 
	to which we are going) as a maximum value.
    Repeat the steps till the complete matrix is having same maximum value.
*/
float matrix(float orig_array[10][10],int n)		
{											// Time Complexity
    float cost=0.0,min, cost_array[10][10];
    int pos=0,new_pos=0,count=0;
    for(int i=0; i<n; i++)								// n
    {
    	for(int j=0; j<n; j++)							        // n*n					
    	{
			if(j==0 || i==j)
    			cost_array[i][j]=max_value;
    		else
				cost_array[i][j]=orig_array[i][j];
		}
	}
    for(int i=0; i<n; i++)									// n
    {	arr[i]=pos;		
        count++;
		min=max_value;
		printf("After Processing the above: \n");
		for(int k=0; k<n; k++)								// n*n
        {
        	printf("\n");
			for(int l=0; l<n; l++)							// n*n*n 	
        		printf("%f	",cost_array[k][l]);
        	printf("\n");
		}
        if(count<n)											// n	
        {
        	for(int j=0; j<n ; j++)							// n*n			
        	{
	            if(cost_array[pos][j] < min )
	            {
	                min=cost_array[pos][j];
	                new_pos=j;
	            }
        	}
		}
		else												// n
		{
			min = orig_array[pos][0];
			new_pos=0;
		}
        printf("\n\nmin: %f		",min);
        printf("new_pos: %d		",new_pos);
        cost=cost + min;
        printf("cost: %f\n\n",cost);
        for(int j=0; j<n; j++)								// n*n
        {
             cost_array[pos][j]=max_value;
             cost_array[j][new_pos]=max_value;
        }
        pos=new_pos;
    }
    return cost;
}
/*
	float branch_bound(float cost_array[10][10],int n)				// Branch & Bound
	Since, Worst case time complexity of Branch and Bound method can be (n-1)!, It is not an efficient solution. 
*/
int main()
{
	int n,ar[10][2];
	float cost[10][10],res1,res2;
	printf("Enter Number of Delivery Addresses: ");
    scanf("%d",&n);
    printf("\nEnter The Coordinates of Addresses : \n");
	for(int i=0; i<n; i++)
		scanf("%d%d",&ar[i][0],&ar[i][1]);
	for(int i =0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cost[i][j]= (float)sqrt(pow((ar[i][0]-ar[j][0]),2)+ pow((ar[i][1]-ar[j][1]),2));     // Cost Matrix
	}
	for(int i =0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			printf("%f	",cost[i][j]);
		printf("\n");
	}
	res1=queue(cost,n);
	res2=matrix(cost,n);
	printf("\n\n%f\n",res1);
    printf("\n\nOUR RESULT IS : %f\n",res2);
    for(int i=0; i<n; i++)
    	printf("%d-->",arr[i]+1);
	return 0;
}
