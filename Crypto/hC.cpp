#include<bits/stdc++.h> 
using namespace std; 
#define SIZE 100

int N;


int findGCD(int a, int b, int *x, int *y)  
{  
    // Base Case  
    if (a == 0)  
    {  
        *x = 0;  
        *y = 1;  
        return b;  
    }  
  
    int x1, y1; // To store results of recursive call  
    int gcd = findGCD(b%a, a, &x1, &y1);  
  
    // Update x and y using results of  
    // recursive call  
    *x = y1 - (b/a) * x1;  
    *y = x1;  
  
    return gcd;  
} 


// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
void findCoFactors( int A[][SIZE], int temp[][SIZE], int p, int q, int n ) 
{ 
	int i = 0, j = 0; 

	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++) 
	{ 
		for (int col = 0; col < n; col++) 
		{ 
			// Copying into temporary matrix only those element 
			// which are not in given row and column 
			if (row != p && col != q) 
			{ 
				temp[i][j++] = A[row][col]; 

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1) 
				{ 
					j = 0; 
					i++; 
				} 
			} 
		} 
	} 
} 

/* Recursive function for finding determinant of matrix. 
n is current dimension of A[][]. */
int determinant(int A[][SIZE], int n ) 
{ 
	int D = 0; // Initialize result 

	// Base case : if matrix contains single element 
	if (n == 1) 
		return A[0][0]; 

	int temp[SIZE][SIZE]; // To store cofactors 

	int sign = 1; // To store sign multiplier 

	// Iterate for each element of first row 
	for (int f = 0; f < n; f++) 
	{ 
		// Getting Cofactor of A[0][f] 
		findCoFactors(A, temp, 0, f, n); 
		D += sign * A[0][f] * determinant(temp, n - 1); 

		// terms are to be added with alternate sign 
		sign = -sign; 
	} 

	return D; 
} 

// Function to get adjoint of A[N][N] in adj[N][N]. 
void adjoint(int A[][SIZE],int adj[][SIZE]) 
{ 
	if (N == 1) 
	{ 
		adj[0][0] = 1; 
		return; 
	} 

	// temp is used to store cofactors of A[][] 
	int sign = 1, temp[SIZE][SIZE]; 

	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
		{ 
			// Get cofactor of A[i][j] 
			findCoFactors(A, temp, i, j, N); 

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i+j)%2==0)? 1: -1; 

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj[j][i] = (sign)*(determinant(temp, N-1)); 
		} 
	} 
} 

// Function to calculate and store inverse, returns false if 
// matrix is singular 
bool inverse(int A[][SIZE], int inverse[][SIZE]) 
{ 
	// Find determinant of A[][] 
	int det = determinant(A, N); 
	if (det%13 == 0 || det%2 == 0 ) 
	{ 
		cout << "Can't find inverse!!,"<<endl;
		return false; 
	} 

	cout<<"The Determinant of the messages matrix is : "<<((det%26)+26)%26<<endl; 

	// Find adjoint 
	int adj[SIZE][SIZE]; 
	adjoint(A, adj); 

	int x,y;
	x = 0;
	y = 0;
	int tempDet = findGCD(26,((det%26)+26)%26,&x,&y);
	tempDet = ((y%26)+26)%26;



	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i=0; i<N; i++) 
		for (int j=0; j<N; j++) 
			inverse[i][j] = adj[i][j]*tempDet; 

	return true; 
} 

// Generic function to display the matrix. We use it to display 
// both adjoin and inverse. adjoin is integer matrix and inverse 
// is a float. 
template<class T> 
void display(T A[][SIZE]) 
{ 
	for (int i=0; i<N; i++) 
	{ 
		for (int j=0; j<N; j++) 
			cout << A[i][j] << " "; 
		cout << endl; 
	} 
} 

// Driver program 
int main() 
{ 

	cout<<"Please enter the size:";
	cin>>N;
	string messages[SIZE];
	cout<<"Please enter the "<<N<<" message strings:"<<endl;
	for(int i = 0 ; i <N ; i++)
	{
		cin>>messages[i];
		transform(messages[i].begin(), messages[i].end(), messages[i].begin(), ::toupper); 	
	}

	
	string cipherText[SIZE];
	cout<<"Please enter the "<<N<<" ciphertext strings:"<<endl;
	for(int i = 0 ; i <N ; i++)
	{
		cin>>cipherText[i];
		transform(cipherText[i].begin(), cipherText[i].end(), cipherText[i].begin(), ::toupper); 	
	}

	int A[SIZE][SIZE]; 
	int B[SIZE][SIZE];
	int encKey[SIZE][SIZE];
	int adj[SIZE][SIZE]; // To store adjoint of A[][] 

	int inv[SIZE][SIZE]; // To store inverse of A[][] 

	for(int i = 0 ; i < N ; i++)
	{
		for(int j =0 ; j < N ; j++)
		{
			A[i][j] = messages[i][j] - 65;
			B[i][j] = cipherText[i][j] - 65;
			encKey[i][j] = 0;
		}
	}

	// cout << "\nThe Adjoint is :\n"; 
	// adjoint(A, adj); 
	// //display(adj); 


	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j < N ; j++ )
			adj[i][j] = ((adj[i][j]%26)+26)%26;
	}

	// display(adj);
	// cout<<endl;

	 

	if (inverse(A, inv)) 
	{
		cout << "\nThe Inverse is :\n";
		for(int i = 0; i < N ; i++)
			for(int j = 0 ; j <N ; j++)
				inv[i][j] = (inv[i][j]%26+26)%26;

		display(inv); 
	} 

	cout<<endl<<endl;

	// int cipherText[SIZE][SIZE];
	// char cChar[SIZE][SIZE];
	char eKey[SIZE][SIZE];
	cout<<"The encryption key::"<<endl;
	for(int i = 0 ; i < N; i++)
	{
		for(int j = 0 ; j < N ; j++)
		{
			for(int k = 0 ; k < N ; k++)
				encKey[i][j] += inv[i][k]*B[k][j];
			
			// for(int l = 0 ; l < N ; l++)
			// 	cipherText[i][j] += encKey[i][l]*A[l][j];

			encKey[i][j] = encKey[i][j]%26;
			// cipherText[i][j] = cipherText[i][j]%26;

			eKey[i][j] = (char)(encKey[i][j] + 65);
			// cChar[i][j] = (char)(cipherText[i][j] + 65);
		}
	}			

	
	

	display(encKey);

	// cout<<endl<<endl;
	// cout<<"The encryption key(in characters form) is:"<<endl;	
	// display(eKey);
	// cout<<"The ciphertext(in characters form) is:"<<endl;	
	// display(cChar);

	return 0; 
} 

