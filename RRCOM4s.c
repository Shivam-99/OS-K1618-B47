#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int TimeQuantum;
struct process
{
    int burstTime,arrivalTime,processNumber,totalBurst;
}processQueue[30];
struct processList
{
    int burstTime,arrivalTime,processNumber,totalBurst;
    struct processList *next;
}*head=NULL;
int n;
void getProcesses();
void AddToList(int);
void delNode(struct processList *);
int main()
{
    int i=0,j=0,k,e=0,AllotedTime=0,TimeQuantum,t;
    printf("Enter CPU running time:");
    scanf("%d",&k);
    printf("Enter the time Quantum");
    scanf("%d",&TimeQuantum);
    getProcesses();
    int min_index;
    for (i = 0; i < n-1; i++)
    {
        min_index = i;
        for (j = i+1; j < n; j++)
          if (processQueue[j].arrivalTime < processQueue[min_index].arrivalTime)
            min_index = j;
        t=processQueue[min_index].arrivalTime;
        processQueue[min_index].arrivalTime=processQueue[i].arrivalTime;
        processQueue[i].arrivalTime=t;
        t=processQueue[min_index].burstTime;
        processQueue[min_index].burstTime=processQueue[i].burstTime;
        processQueue[i].burstTime=t;
        t=processQueue[min_index].processNumber;
        processQueue[min_index].processNumber=processQueue[i].processNumber;
        processQueue[i].processNumber=t;
        t=processQueue[min_index].totalBurst;
        processQueue[min_index].totalBurst=processQueue[i].totalBurst;
        processQueue[i].totalBurst=t;
    }
    i=j=0;
    while(i<processQueue[0].arrivalTime)
    {
        i++;
    }
    struct processList *ptr=head,*save=NULL;
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
                printf("Process %d executed at %d with Waiting Time:%d and Turn Around Time:%d\n",ptr->processNumber,i,i-ptr->totalBurst-ptr->arrivalTime,i-ptr->arrivalTime);
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
        struct processList *pt=head;
        while(pt!=NULL)
        {
            pt=pt->next;
        }
    }
}
void getProcesses()
{
    int i;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the Arrival Time of Process %d:",i+1);
        scanf("%d",&processQueue[i].arrivalTime);
        printf("Enter the Burst Time of Process %d:",i+1);
        scanf("%d",&processQueue[i].burstTime);
        processQueue[i].totalBurst=processQueue[i].burstTime;
        processQueue[i].processNumber=i+1;
    }
}
void AddToList(int j)
{
    struct processList *ptr,*pt;
    ptr = (struct processList*)malloc(sizeof(struct processList));
    ptr->arrivalTime=processQueue[j].arrivalTime;
    ptr->burstTime=processQueue[j].burstTime;
    ptr->processNumber=processQueue[j].processNumber;
    ptr->totalBurst=processQueue[j].totalBurst;
    ptr->next=NULL;
    if(head==NULL)

    {
        head=ptr;
    }
    else
    {
        pt=head;
        if(pt->next!=NULL)
        {
            pt=pt->next;
        }
        pt->next=ptr;
    }
}
void delNode(struct processList *ptr)
{
    if(head==ptr)
    {
        head=head->next;
    }
    else
    {
        struct processList *pt=head;
        while(pt->next!=ptr)
        {
            pt=pt->next;
        }
        pt->next=ptr->next;
    }
}
