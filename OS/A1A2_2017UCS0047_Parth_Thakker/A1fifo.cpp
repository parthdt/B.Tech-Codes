#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


bool comparefn(vector <int> a, vector <int> b){
    return a[0]<b[0];
}

int main(){
    ifstream ip;
    ip.open("input.dat");
    int n;
    ip>>n;
    vector<vector<int>> p;
    vector<int> priority;
    p.resize(n);
    priority.resize(n,0);
    for(int j=0;j<n;j++)p[j].resize(3,0);
    int i;
    for(i=0;i<n;i++){
        ip>>p[i][0]>>p[i][1]>>priority[i];
        p[i][2]=i+1;
    }
    ip.close();
    sort(p.begin(),p.end(),comparefn);
    // cout<<"No. of processes:"<<n;
    // i++;
    // cout<<endl;
    // for(i=0;i<n;i++){
    //     cout<<"Process "<<i+1<<"Arrival Time: "<<p[i][0]<<"Burst Time: "<<p[i][1]<<endl;
    // }
    vector <int> tt,wt,rt;
    tt.resize(n,0);         //Turnaround Time
    wt.resize(n,0);         //Waiting Time
    rt.resize(n,0);         //Response Time

    int ct=0;
    for(i=0;i<n;i++){
        tt[i]=ct+p[i][1]-p[i][0];
        wt[i]=rt[i]=ct-p[i][0];
        ct+=p[i][1];
        
    }
    for(i=0;i<n;i++){
        cout<<"Process: "<<p[i][2]<<" Turnaround: "<<tt[i]<<" Response: "<<rt[i]<<" Waiting :"<<wt[i]<<endl;
    }

    cout<<"AVERAGES:\n";
    cout<<"Turnaround Time Average: "<<float(accumulate(tt.begin(),tt.end(),0))/float(n)<<endl;
    cout<<"Response Time Average: "<<float(accumulate(rt.begin(),rt.end(),0))/float(n)<<endl;
    cout<<"Waiting Time Average: "<<float(accumulate(wt.begin(),wt.end(),0))/float(n)<<endl;
    return 0;
}