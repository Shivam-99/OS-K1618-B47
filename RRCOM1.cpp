#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int TimeQuantum;
struct process
{
    int burstTime,arrivalTime,waitTime=0,processNumber,totalBurst;
}processQueue[30];
int n;
void getProcesses();
bool SortByArrival(process a, process b)
{
	return a.arrivalTime < b.arrivalTime;
}
int main()
{
    int i=0,j=0,k,e=0,AllotedTime=0,inExc=0,indx=-1,TimeQuantum,counter;
    cout<<"Enter CPU running time:";
    cin>>k;
    cout<<"Enter the time Quantum";
    cin>>TimeQuantum;
    getProcesses();
    sort(processQueue,processQueue+n,SortByArrival);
    while(i<processQueue[0].arrivalTime)
    {
        i++;
    }
    cout<<"A";
    while(i<k)
    {
        i++;
        while(processQueue[j].arrivalTime<i)
        {
            inExc++;
            j++;
            cout<<"C";
        }
        cout<<i;
       // getch();
        if(inExc>0)
        {
            cout<<"E";
            if(AllotedTime==0)
            {
                cout<<"F";
                if(processQueue[indx].burstTime==0)
                {
                    cout<<"Process "<<processQueue[indx].processNumber<<" executed at "<<i-1<<endl;
                    inExc--;
                    e++;
                }
                indx++;
                if(indx>=j)
                {
                    indx=indx=0;
                }
                counter=0;
                while(processQueue[indx].burstTime<=0&&counter<n)
                {
                    indx++;
                    counter++;
                }
                if(processQueue[indx].burstTime>TimeQuantum)
                {
                    AllotedTime=TimeQuantum;
                }
                else
                {
                    AllotedTime=processQueue[indx].burstTime;
                }
            }
            processQueue[indx].burstTime--;
            if(AllotedTime>0)
                AllotedTime--;
            if(e==n)
            {
                break;
            }
        }
        else
        {
            while(i<processQueue[j].arrivalTime&&i<k)
            {
                i++;
            }
        }
    }
}
void getProcesses()
{
    int i;
    cout<<"Enter the number of processes:";
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"Enter the Arrival Time of Process "<<i+1<<":";
        cin>>processQueue[i].arrivalTime;
        cout<<"Enter the Burst Time of Process "<<i+1<<":";
        cin>>processQueue[i].burstTime;
        processQueue[i].totalBurst=processQueue[i].burstTime;
        processQueue[i].processNumber=i+1;
    }
}
