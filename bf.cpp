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

    for(int i=0; i<n; i++){
    int min_index = -1;

    // Iterate through each memory block
    for(int j=0; j<m; j++){
        // Check if the size of the memory block is greater than or equal to the size of the process
        if(sizeofblock[j] >= sizeofprocess[i]){
            // If min_index is -1, it means we haven't found a block yet, so set min_index to the current block
            if(min_index == -1){
                min_index = j;
            }
            // If min_index is not -1, compare the sizes of the current block and the block at min_index
            else if (sizeofblock[min_index] > sizeofblock[j]){
                // If the current block is smaller, update min_index to the current block
                min_index = j;
            }
        }
    }

    // If min_index is still -1, no suitable block was found for the current process
    if(min_index == -1){
        allocatedblock[i] = -1; // Set allocated block index to -1 to indicate allocation failure
    }
    else{
        allocatedblock[i] = min_index + 1; // Set allocated block index to min_index + 1 (blocks are 1-indexed)
        sizeofblock[min_index] -= sizeofprocess[i]; // Reduce the size of the allocated block by the size of the process
    }
}


     cout<<"Process No. \tProcess Size \tBlock No. \n";
    for(int i=0; i<n; i++)
    {
        cout<<" "<<i+1<<"\t\t"<<sizeofprocess[i]<<"\t\t";
        if(allocatedblock[i] != -1)
            cout<<allocatedblock[i];
        else
            cout<<"Not Allocated";
        cout<<endl;
    }

    return 0;
}