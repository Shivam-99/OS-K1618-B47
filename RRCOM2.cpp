#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
int TimeQuantum;
struct process
{
    int burstTime,arrivalTime,processNumber,totalBurst;
}processQueue[30];
struct processList
{
    int burstTime,arrivalTime,waitTime=0,processNumber,totalBurst;
    processList *next=NULL;
}*head=NULL;
int n;
void getProcesses();
void AddToList(int);
void delNode(processList *);
bool SortByArrival(process a, process b)
{
	return a.arrivalTime < b.arrivalTime;
}
int main()
{
    int i=0,j=0,k,e=0,AllotedTime=0,TimeQuantum;
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
    processList *ptr=head,*save=NULL;
    while(i<k)
    {
        while(processQueue[j].arrivalTime<=i&&j<n)
        {
            AddToList(j);
            j++;
            if(ptr==NULL)
            {
                ptr=head;
            }
        }
            if(save!=NULL)
            {
            if(save->next!=NULL)
            {
                ptr=save->next;
            }
            }
        if(ptr!=NULL)
        {
            if(ptr->burstTime<=TimeQuantum)
            {
                i+=ptr->burstTime;
                ptr->burstTime=0;
                cout<<"Process "<<ptr->processNumber<<" executed at "<<i<<" with Waiting time:"<<i-ptr->totalBurst-ptr->arrivalTime<<" and TurnAround Time:"<<i-ptr->arrivalTime<<endl;
                save=ptr;
                delNode(ptr);
                ptr=ptr->next;
                e++;
            }
            else
            {
                i+=TimeQuantum;
                ptr->burstTime-=TimeQuantum;
                save=ptr;
                ptr=ptr->next;
               // cout<<i<<endl;
            }
            if(ptr==NULL)
            {
                ptr=head;
            }
        }
        else
            i++;
        if(e==n)
        {
            break;
        }
        processList *pt=head;
        while(pt!=NULL)
        {
            pt=pt->next;
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
void AddToList(int j)
{
    processList *ptr,*pt;
    ptr=new processList;
    ptr->arrivalTime=processQueue[j].arrivalTime;
    ptr->burstTime=processQueue[j].burstTime;
    ptr->processNumber=processQueue[j].processNumber;
    ptr->totalBurst=processQueue[j].totalBurst;
    if(head==NULL)

    {
        head=ptr;
    }
    else
    {
        pt=head;
        pt->next=ptr;
    }
}
void delNode(processList *ptr)
{
    if(head==ptr)
    {
        head=head->next;
    }
    else
    {
        processList *pt=head;
        while(pt->next!=ptr)
        {
            pt=pt->next;
        }
        pt->next=ptr->next;
    }
}
