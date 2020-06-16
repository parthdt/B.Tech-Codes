#include<bits/stdc++.h>
using namespace std;

string plainText = "";
int keyLength = 0;
float checkError = 10;
float rIndex = 0; 
int countVar = 0 ;
string key = "";
float probabilityMatrix[26] = {0.082, 0.015 , 0.028 , 0.043, 0.127, 0.022 , 0.020 , 0.061 , 0.07 , 0.002 , 0.008, 0.040 , 0.024, 0.067 , 0.075, 0.019 , 0.001, 0.060 , 0.063 , 0.091, 0.028, 0.01 , 0.023 , 0.001, 				0.02 , 0.001};

void findKeyLength(string input, int size){
	for(int r = 1; r<=20 ; r++)
	{
		rIndex = 0;
		
		for(int i = 0 ; i<r ; i++)
		{
			countVar  = 0 ;
			float idx = 0;
			int alphabet[26] = {0};
			for(int j = i ; j < size ; j+=r)
			{
				alphabet[input[j]-'A']++;
				countVar++;
	
			}	
	
			for(int j = 0; j < 26 ;j++)
			{
				idx+=alphabet[j]*alphabet[j];
			}
			
			idx = (idx*1.0)/(countVar*countVar*1.0);
			rIndex += idx;
		
		
		}
		rIndex = rIndex/r;

		if((rIndex-0.065)*(rIndex-0.065) < checkError)
		{
			checkError = (rIndex-0.065)*(rIndex-0.065);
			keyLength = r; 
		}
		

	}
}

void findKey(string input, int size){
	for(int i = 0 ; i < keyLength ; i++)	
	{
		int countVar = 0;
		int shiftMin = 0;
		float closest = 10.0;
		float temp;
		float arr[26] = {0.0};
		for(int j = i ; j < size  ; j+=keyLength)
		{
			arr[input[j] - 'A']+=1.0;
			countVar++;
		}

		for(int j = 0 ; j<26 ; j++)
		{
			arr[j] = (arr[j]*1.0)/(countVar*1.0);
		}

		for(int shift = 0 ; shift <26 ;shift++ )
		{
			temp = 0.0 ; 
			for(int j = 0 ; j<26 ; j++)
			{
				temp += (arr[(j+shift)%26]* probabilityMatrix[j]); 
			}

			if(abs(temp-0.065) < closest)
			{
				closest = abs(temp - 0.065);
				shiftMin = shift;
			}
		}

		key += char(65 + shiftMin);
	}
}

void findPlainText(string input, int size){

	for(int i = 0 ; i < size ; i++)
	{
		plainText += char(((input[i]-'A')-(key[i%keyLength]-'A')+26)%26 +'A');
	}
	
}
int main()
{
	string input;
	cin>>input;
	int size = input.size();
    for(int i=0;i<size;i++)input[i] = toupper(input[i]);
	// findKeyLength(input,size);
	// cout<<"Error is: "<< checkError <<endl<<"Key Length is: "<< keyLength <<endl;
	keyLength = 1;
    findKey(input,size);
	cout<<"Key is:"<<key<<endl;
	findPlainText(input,size);
	cout<<"Finally, plain text is: "<<plainText<<endl;			
	return 0;
}
