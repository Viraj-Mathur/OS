#include<iostream>
using namespace std;

int main(){
    cout<<"Enter number of processes: "<<endl;
    int n=0;
    int m=0;
    cin>>n;
    cout<<"Enter number of Blocks: "<<endl;
    cin>>m;

    int sizeofprocess[n];
    int sizeofblock[m];

    for(int i=0;i<n;i++){
        sizeofprocess[i] = 0;
    }

    for(int i=0;i<m;i++){
        sizeofblock[i] = 0;
    }

    //taking input of size of processes
    for(int i = 0; i<n; i++)
    {   
        cout<<"Enter the size of "<<i+1<<" processes: ";
        cin>>sizeofprocess[i];
    }

    //taking input of size of blocks
    for(int i = 0; i<m; i++)
    {
        cout<<"Enter the size of "<<i+1<<" block: ";
        cin>>sizeofblock[i];
    }

    int allocatedblock[n];
    for(int i=0;i<n;i++){
        allocatedblock[i] = 0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(sizeofprocess[i] <= sizeofblock[j]){
                allocatedblock[i] = j+1;
                sizeofblock[j] -= sizeofprocess[i];
                break;
            }
        }
    }

    cout<<endl;

    cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] != 0)
            cout<<allocatedblock[i];
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

return 0;
}