#include <iostream>
#include <vector>
#include <fstream>

/*at = Arrival time,
bt = Burst time,
quantum= Quantum time
tat = Turn around time,
wt = Waiting time*/

using namespace std;

int main(){
	int i,n,time,remain,temps=0,quantum;

	int wt=0,tat=0;
    ifstream ip;
    ip.open("input.dat");
    
    ip>>n;
	remain=n;

	vector<int>at(n);
	vector<int>bt(n);
	vector<int>rt(n);
	vector<int>priority(n);
	
	for(i=0;i<n;i++)
	{
		ip>>at[i];
		ip>>bt[i];
		ip>>priority[i];
		rt[i]=bt[i];
	}

	ip>>quantum;

	cout<<"\n\nProcess\t\t:Turnaround Time: Waiting Time\n\n";
	for(time=0,i=0;remain!=0;)
	{
		if(rt[i]<=quantum && rt[i]>0)
		{
			time += rt[i];
			rt[i]=0;
			temps=1;
		}

		else if(rt[i]>0)
		{
			rt[i] -= quantum;
			time += quantum;
		}

		if(rt[i]==0 && temps==1)
		{
			remain--;
			printf("Process-%d\t:\t%d\t:\t%d\n",i+1,time-at[i],time-at[i]-bt[i]);
			cout<<endl;

			wt += time-at[i]-bt[i];
			tat += time-at[i];
			temps=0;
		}

		if(i == n-1)
			i=0;
		else if(at[i+1] <= time)
			i++;
		else
			i=0;
	}

	cout<<"Average waiting time "<<wt*1.0/n<<endl;
	cout<<"Average turn around time "<<tat*1.0/n<<endl;;

	return 0;
}
