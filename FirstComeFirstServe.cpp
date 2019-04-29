#include<iostream>
using namespace std;
int main()
{


    int n,BurstTime[20],WaitingTime[20],TurnedAroundTime[20],avWaitingTime=0,avTurnedAroundTime=0,i,j;
	
    cout<<"Enter total number of processes <maximum 20>:";
    cin>>n;
    cout<<"\nEnter Process Burst Time\n";
	
	
    for(i=0;i<n;i++)
    {
        cout<<"P["<<i+1<<"]:";
        cin>>BurstTime[i];
    }
	
	
    WaitingTime[0]=0;  
    for(i=1;i<n;i++)
    {
        WaitingTime[i]=0;
        for(j=0;j<i;j++)
            WaitingTime[i]+=BurstTime[j];
    }
	
	
    cout<<"\nProcess\t\tBurst Time\Waiting Time\TurnAround Time";
    
    for(i=0;i<n;i++)
    {
        TurnedAroundTime[i]=BurstTime[i]+WaitingTime[i];
        
        avWaitingTime+=WaitingTime[i];
        
        avTurnedAroundTime+=TurnedAroundTime[i];
        cout<<"\nP["<<i+1<<"]"<<"\t\t"<<BurstTime[i]<<"\t\t"<<WaitingTime[i]<<"\t\t"<<TurnedAroundTime[i];
    }
	
	
    avWaitingTime/=i;
    avTurnedAroundTime/=i;
    cout<<"\n\nAverage Waiting Time:"<<avWaitingTime;
    cout<<"\nAverage Turnaround Time:"<<avTurnedAroundTime;
    return 0;
}
