#include <bits/stdc++.h>

using namespace std;


class process
{
    public:
    int pid;
    int at;
    int bt;
    int rt;
    int et;
    int tat;
    int wt;
    int st;
};

int main()
{
    cout<<"Enter the number of processes: "<<endl;
    int n;
    cin>>n;

    float total_tat = 0;
    float total_wt = 0;

    process p[n];
    bool visited[n];

    for(int i=0; i<n; i++)
    {
        cout<<"Enter arrival time for "<<i+1<<" process: "<<endl;
        cin>>p[i].at;
        cout<<"Enter burst time for "<<i+1<<" process: "<<endl;
        cin>>p[i].bt;
        p[i].pid = i+1;
    }

    int curr_time = 0;
    int process_completed = 0;

    while(process_completed != n)
    {
        int index = -1;
        int min_bt = INT_MAX;

        for(int i=0; i<n; i++)
        {
            if(p[i].at <= curr_time && visited[i] == 0)
            {
                if(p[i].bt < min_bt)
                {
                    index = i;
                    min_bt = p[i].bt;
                }
                if(p[i].bt == min_bt)
                {
                    if(p[i].at < p[index].at)
                    {
                        index = i;
                        min_bt = p[i].bt;
                    }
                }
            }
        }

        if(index != -1)
        {
            p[index].st = curr_time;
            p[index].et = p[index].st + p[index].bt;
            p[index].tat = p[index].et - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            total_tat += p[index].tat;
            total_wt += p[index].wt;

            visited[index] = 1;
            process_completed++;
            curr_time += p[index].bt;
        }
        else
        {
            curr_time++;
        }
    }

    cout<<endl<<endl;

    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"ET\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i=0; i<n; i++)
    {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].et<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }

    cout<<endl<<endl;

    cout<<"Average Turnaround Time is : "<<(float)total_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)total_wt/n<<endl;

return 0;
}