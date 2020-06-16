#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int findHighest(vector <int> a){				//to find element with most Age

	int maxV = a[0],maxI = 0;
	for(int i=1;i<a.size();i++){
		if(a[i]>maxV){
			maxI=i;
			maxV=a[i];
		}
	}
	
	return maxI;
}

int inPF(vector <int> pageFrame,int element){			//to find if element is in any frame

	for(int i=0;i<pageFrame.size();i++){
		if(pageFrame[i]==element)return i;
	}
	return -1;
}
	
	
void displayVector(vector <int> a){				//display int vector; below overloaded fn displays char vector
	
	for(int i=0;i<a.size();i++)cout<<a[i]<<" ";
}
void displayVector(vector <char> a){
	
	for(int i=0;i<a.size()-1;i++)cout<<a[i];
}
int main(){

	ifstream fp;
	fp.open("ref.dat");
	
	vector <char> tRef;
	int tSize = 0;
	char write1[3] = "*,",write2[2] = ",";		//used for op ref string
	char dump;					//used for , input in file
	
	vector <int> aging,pf;
	//int reference[13] = {3,2,1,0,0,2,5,4,2,1,3,2,-1};
	vector <int> reference;
	int N = 0,faults = 0;
	int id;
	
	//cout<<"Enter the no. of page frames:";
	//cin>>N;
	int rSize = 0;
	fp>>N;
	//cout<<N<<endl;
	reference.resize(1000,-2);
	while(1){							//input reference/seq string
		fp>>reference[rSize]>>dump;
		if(reference[rSize]==-1)break;
		rSize++;
	}
	reference.resize(rSize);	
	//displayVector(reference);
	aging.resize(N,1000);
	pf.resize(N,-1);
	tRef.resize(5*rSize);
	

	
	for(int i=0;reference[i]!=-1;i++){
	
		for(int i=0;i<N;i++){
		if(aging[i]>=0 && aging[i]<1000)aging[i]++;
		}
		
		cout<<endl;
		//cout<<"Age: ";displayVector(aging);
		//cout<<endl;
		//cout<<"Page Frame: ";displayVector(pf);
		id=inPF(pf,reference[i]);
		
		if(id==-1){								//if element not in any frame, replace with max age one
			id=findHighest(aging);
			cout<<reference[i]<<" Page Fault -";
			if(pf[id]==-1)cout<<"No page replaced as empty frame available";
			else cout<<"Page replaced "<<pf[id];
			pf[id] = reference[i];
			aging[id]=0;
			faults++;
			tRef[tSize]=reference[i]+48;
			tRef[tSize+1]='*';
			tRef[tSize+2]=',';
			tSize+=3;
			
		}
		else{									//if element in frame, age = 0
			cout<<reference[i]<<" - No page fault";
			aging[id]=0;
			tRef[tSize]=reference[i]+48;
			tRef[tSize+1]=',';
			tSize+=2;
			
		}
		
	}
	tRef.resize(tSize);
	
	cout<<endl<<endl<<"Reference String: ";
	displayVector(tRef);
	
	cout<<"\nNo. of page faults: "<<faults<<endl<<"Hit Ratio = "<<((float)(rSize-faults)/rSize)*100;
	return 0;
}
			
			
			
