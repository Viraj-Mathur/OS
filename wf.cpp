#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<"Enter the number of processes: "<<endl;
    int n=0;
    int m = 0;
    cin>>n;
    cout<<"Enter the number of blocks: "<<endl;
    cin>>m;

    int sizeofprocess[n];
    int sizeofblock[m]; 
    

    for(int i=0; i<n; i++)
    {
        sizeofprocess[i] = 0;
    }
    for(int i=0; i<m; i++)
    {
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
    for(int i=0; i<n; i++)
    {
        allocatedblock[i] = 0;
    }

    for(int i=0;i<n;i++){
        int max_index = -1;
        for(int j=0;j<m;j++){
            if(sizeofblock[j] >= sizeofprocess[i]){
                if(max_index ==-1){
                    max_index = j;
                }
                else if(sizeofblock[max_index] < sizeofblock[j]){
                    max_index = j;
                }
                
            }
        }

        if(max_index ==-1){
            allocatedblock[i] = -1;
        }
        else{
            allocatedblock[i] = max_index + 1;
            sizeofblock[max_index] -= sizeofprocess[i];
        }
    }

    cout<<endl;
    cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0;i<n;i++){
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] !=-1){
            cout<<allocatedblock[i];
        }
        else{
            cout<<"Not Allocated";
            
        }
        cout<<endl;

    }

   

    return 0;
}