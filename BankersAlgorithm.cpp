#include<iostream>
using namespace std;
const int n=10;


int inputFunction(int sequence[n],int processes,int resources,int alocatedResource[][n],int maxResources[][n],int availableResources[n],int var);
int calcuFunction(int sequence[n],int processes,int resources,int alocatedResource[][n],int maxResources[][n],int availableResources[n],int var);

int main()
{
    int processes,resources;
	int sequence[n],alocatedResource[n][n],maxResources[n][n],availableResources[n],var;
	
    inputFunction(sequence,processes,resources,alocatedResource,maxResources,availableResources,var);
    calcuFunction(sequence,processes,resources,alocatedResource,maxResources,availableResources,var);
   
    return 0;
}



int calcuFunction(int sequence[n],int processes,int resources,int alocatedResource[][n],int maxResources[][n],int availableResources[n],int var)
{
    int flag=0,fl=0;
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<var;j++)
            if(i==sequence[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<resources;j++)
            {
                if(availableResources[j]-maxResources[i][j]+alocatedResource[i][j]<0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
                return i;
            flag=0;
        }
        fl=0;
    }
    return -1;
}

int inputFunction(int sequence[n],int processes,int resources,int alocatedResource[][n],int maxResources[][n],int availableResources[n],int var)
{
    cout<<"Enter number of processes : ";
    cin>>processes;
    cout<<"Enter number of resources : ";
    cin>>resources;
    cout<<"Enter number of instances available of each resource : ";
    for(int i=0;i<resources;i++)
        cin>>availableResources[i];
    for(int i=0;i<processes;i++)
    {
        cout<<"Enter no. of instances of resources allocated to process processes["<<i<<"] : ";
        for(int y=0;y<resources;y++)
            cin>>alocatedResource[i][y];
    }
    for(int i=0;i<processes;i++)
    {
        cout<<"Enter max no. of instances of resources process processes["<<i<<"] needs : ";
        for(int y=0;y<resources;y++)
            cin>>maxResources[i][y];
    }
}
