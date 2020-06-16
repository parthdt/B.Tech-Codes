#include<iostream>
#include<string>

using namespace std;

	char maxOccuring(string s)
	{
		int count[26]={0};
		int addr;
		char m;
		int max=0;
		
		for(int i=0;i<s.length();i++)
		{
			addr = (s[i]%26); 				//Hashing used here as all chars have an ASCII value, all alphabets are given contiguous values
										//hence mod 26 will give different value to all (a - suppose 0, then b - 1, c - 2 ......)
			count[addr]++;
			if(max < count[addr])
			{
				max = count[addr];
				m = s[i];
			}
		}
		
		return m;
	}

