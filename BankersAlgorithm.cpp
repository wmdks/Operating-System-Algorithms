#include<iostream>
using namespace std;


class BankersAlgorithm
{
    int processes,resources,sequence[20],al[20][20],rn[20][20],avl[20],ed;
    int com_pr();
    
public:
    void getdata();
    void safe_seq();
};


void BankersAlgorithm::getdata()
{
    cout<<"Enter number of processes : ";
    cin>>processes;
    cout<<"Enter number of resources : ";
    cin>>resources;
    cout<<"Enter number of instances available of each resource : ";
    for(int i=0;i<resources;i++)
        cin>>avl[i];
    for(int i=0;i<processes;i++)
    {
        cout<<"Enter no. of instances of resources allocated to process processes["<<i<<"] : ";
        for(int y=0;y<resources;y++)
            cin>>al[i][y];
    }
    for(int i=0;i<processes;i++)
    {
        cout<<"Enter max no. of instances of resources process processes["<<i<<"] needs : ";
        for(int y=0;y<resources;y++)
            cin>>rn[i][y];
    }
}


int BankersAlgorithm::com_pr()
{
    int flag=0,fl=0;
    for(int i=0;i<processes;i++)
    {
        for(int j=0;j<ed;j++)
            if(i==sequence[j])
            {
                fl=1;
                break;
            }
        if(fl!=1)
        {
            for(int j=0;j<resources;j++)
            {
                if(avl[j]-rn[i][j]+al[i][j]<0)
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
void BankersAlgorithm::safe_seq()
{
	
    int temp,flag=0;
    ed=0;
    
    
    for(int i=0;i<processes;i++)
    {
        temp=com_pr();
        if(temp!=-1)
        {
            for(int y=0;y<resources;y++)
                avl[y]+=al[temp][y];
            sequence[ed++]=temp;
        }
        else
        {
            cout<<"\nSystem is in Unsafe State ";
            flag=1;
            break;
        }
    }
    
    if(flag!=1)
    {
        cout<<"Safe Sequence is : ";
        for(int i=0;i<ed;i++)
            cout<<"processes["<<sequence[i]<<"]  ";
    }
}
int main()
{
    BankersAlgorithm banker;
    banker.getdata();
    banker.safe_seq();
    return 0;
}
