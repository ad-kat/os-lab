#include <iostream>
using namespace std;
int m,n;


int index(int need[][10],int visited[],int work[])
{
    for(int i=0;i<n;i++)
    {
        int success=1;
        for(int j=0;j<m;j++)
        {
            if(need[i][j]>work[j])
                success=0;
        }
        if(success==1&& visited[i]==0)
        {
            visited[i]=1;
            return i;
        }

    }
    return -1;
}
int main()
{

    cout<<"Enter the number of processes(m): ";cin>>m;
    cout<<"Enter the number of resources(n): ";cin>>n;
    //Develop the Matrices and Vectors
    int allocation[10][10], maxx[10][10], need[10][10], available[10];
    cout<<"Enter the Max matrix :"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>maxx[i][j];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<maxx[i][j]<<"\t";
        }
        cout<<endl;
         }


    cout<<"Enter the Allocation matrix :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>allocation[i][j];

        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<allocation[i][j]<<"\t";
        }
        cout<<endl;
         }


     for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            need[i][j] = maxx[i][j] - allocation[i][j];

    cout<<"Enter the available vector:";
    for(int i=0;i<m;i++)
        cin>>available[i];




         for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<need[i][j]<<"\t";
        }
        cout<<endl;
         }


    // Apply Safety Algorithm
    int work[m], visited[n];
    for(int i=0;i<m;i++)
    {
       work[i]=available[i];

    }
for(int i=0;i<n;i++)
    {

       visited[i]=0;
    }



    for(int i=0;i<n;i++)
    {
        int success=1;
        for(int j=0;j<m;j++)
        {
            if(need[i][j]>available[j]){
                success = 0;

        }
        }
        if(success==0)
        {
            cout<<"Process "<<i<<" is not safe."<<endl;
            success=1;
        }

    }
    int p=0;
    int order[n];
    int k=0;

    while(p!=-1)
    {
        p=index(need,visited,work);order[k++]=p;
        for(int i=0;i<m;i++)
        {

           work[i]+=need[p][i];
        }

    }

    cout<<"the safe sequence:"<<endl;
    for(int i=0;i<n;i++)
        cout<<order[i]<<"\t";

    return 0;
}
