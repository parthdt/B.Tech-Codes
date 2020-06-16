#include<iostream>

using namespace std;
  
void merge(int first, int mid, int last,int *array)
{
		int size1 = mid - first + 1;
		int size2 = last - mid;
		
		int array1[size1]={0};
		int array2[size2]={0};
		
		int i,j;
		for(i=0;i<size1;i++)array1[i]=array[first + i];
		
		for(j=0;j<size2;j++)array2[j]=array[mid + 1 + j];
		
		i=j=0;
		int k = first;
		while(i<size1 && j<size2)
		{
			if(array1[i] <= array2[j])
			{
				array[k] = array1[i];
				i++;
				k++;
			}
			else
			{
				array[k] = array2[j];
				j++;
				k++;
			}
		}
		
		while(i<size1)
		{
			array[k]=array1[i];
			i++;k++;
		}
		while(j<size2)
		{
			array[k]=array2[j];
			k++;j++;
		}
}

void mergesort(int first,int last, int *array)
{
	if(first<last)
	{
		int mid = (first + last)/2;
		
		mergesort(first,mid,array);
		mergesort(mid+1,last,array);
		merge(first,mid,last,array);
	}
}

int main()
{
	int a[10] = {1,0,1,0,1,0,1,0,1,0};

	
	mergesort(0,9,a);
	
	for(int i=0;i<10;i++)cout<<a[i]<<" ";
	
	return 0;
}

