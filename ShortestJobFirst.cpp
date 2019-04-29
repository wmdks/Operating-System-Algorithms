#include <iostream>
#include <algorithm>
#include <cstring>


using namespace std;

typedef struct proccess
{
	int ArrivalTime,BurstTime,CompletionTime,TurnAroundTime,WaitingTime, btt;
	string processID;

}Schedule;


bool compare(Schedule a,Schedule b)
{
	return a.ArrivalTime<b.ArrivalTime;

	
}


bool compare2(Schedule a,Schedule b)
{
	return a.BurstTime<b.BurstTime;


}

int main()
{
	Schedule procss[10];

	int n,i,j,pcom;
	

	cout<<"Enter number of Process:";
	cin>>n;

	cout<<"Enter Process ID arrivalTime burstTime "<<endl;

	for(i=0;i<n;i++)
	{
		cin>>procss[i].processID;
		cin>>procss[i].ArrivalTime;
		cin>>procss[i].BurstTime;
		
		procss[i].btt=procss[i].BurstTime;
	}

	sort(procss,procss+n,compare);
	i=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(procss[j].ArrivalTime>i)
			break;
		}
		sort(procss,procss+j,compare2);
		if(j>0)
		{
			for(j=0;j<n;j++)
			{
				if(procss[j].BurstTime!=0)
				break;
			}
			if(procss[j].ArrivalTime>i)
			{
				i=procss[j].ArrivalTime;

			}
			procss[j].CompletionTime=i+1;
			procss[j].BurstTime--;
		}
		i++;
		pcom=0;
		for(j=0;j<n;j++)
		{
			if(procss[j].BurstTime==0)
			pcom++;
		}
	}
	cout<<"ProID\tAtime\tBtime\tCtime\tTtime\tWtime\n";
	for(i=0;i<n;i++)
	{
		procss[i].TurnAroundTime=procss[i].CompletionTime-procss[i].ArrivalTime;
		procss[i].WaitingTime=procss[i].TurnAroundTime-procss[i].btt;
		cout<<procss[i].processID<<"\t"<<procss[i].ArrivalTime<<"\t"<<procss[i].btt<<"\t"<<procss[i].CompletionTime<<"\t"<<procss[i].TurnAroundTime<<"\t"<<procss[i].WaitingTime;
		cout<<endl;
	}
	return 0;
}
