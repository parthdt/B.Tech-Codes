#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>

#define MAXELEMENT 50                           //maxelement size
#define MAXARRSIZE 10                           //max array size
#define MAXSUM 500                              //max sum = MAXELEMENT*MAXARRSIZE
int lookup[MAXELEMENT][MAXSUM] = {0};           //this is the lookup table for memoization

// Return 1 if there exists a subarray of array[0..n] with given sum
int subsetSum(int arr[], int n, int sum)
{
	// return 1 if sum becomes 0 (subset found)
	if (sum == 0)
		return 1;

	// base case: no items left or sum becomes negative, return -1
	if (n < 0 || sum < 0)
		return -1;

    int include=0,exclude=0;

	// if sub-problem is seen for the first time, solve it and store it in the lookup table
	if (lookup[n][sum]==0)
	{
		// Case 1. include current item in the subset (arr[n]) and recur
		// for remaining items (n - 1) with remaining sum (sum - arr[n])
        #pragma omp task shared(include)
		include = subsetSum(arr, n - 1, sum - arr[n]);

		// Case 2. exclude current item n from subset and recur for
		// remaining items (n - 1)
        #pragma omp task shared(exclude)    
		exclude = subsetSum(arr, n - 1, sum);

        #pragma omp taskwait

		//if any one value is 1, sum found, else not found
		if(include==1 || exclude==1)lookup[n][sum]=1;
        else lookup[n][sum]=-1;
	}

	// return solution to current sub-problem
	return lookup[n][sum];
}

// Subset Sum Problem
int main()
{
	// Input: set of items and a sum, compile each time you change, too lazy to implement runtime here
	int arr[] = {15,20,32};
	int sum = 53;
    int answer;         //temp variable to store answer
    if(sum<=0)
    {
        printf("Sum should be greater than 0");
        exit(-1);
    }
	// number of items
	int n = sizeof(arr) / sizeof(arr[0]);
    if(n<=0)
    {
        printf("Size of array should be greater than 0");
        exit(-1);
    }

    #pragma omp parallel
    #pragma omp single
    answer=subsetSum(arr, n - 1, sum);

	if (answer==1)
		printf("\nA subset that sums up to given value is found.\n");
	else
		printf("\nNo subset summing up to the given value is found.\n");

	return 0;
}