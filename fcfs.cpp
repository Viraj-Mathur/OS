#include <bits/stdc++.h>

using namespace std;

class process
{
public:
    int pid;
    int at;
    int bt;
    int st;
    int rt;
    int tat;
    int wt;
    int et;
};

int main()
{
    int n;
    cout << "Enter number of processes: " << endl;
    cin >> n;

    process p[n];
    bool visited[n];
    int process_completed = 0;
    float avg_tat = 0;
    float avg_wt = 0;
    int curr_time = 0;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival time for " << i + 1 << " process: " << endl;
        cin >> p[i].at;
        cout << "Enter burst time for " << i + 1 << " process: " << endl;
        cin >> p[i].bt;
        p[i].pid = i + 1;
    }

    while (process_completed != n)
    {
        int index = -1;
        int min_at = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= curr_time && !visited[i])
            {
                if (p[i].at < min_at)
                {
                    index = i;
                    min_at = p[i].at;
                }
            }
        }

        if (index != -1)
        {
            p[index].st = curr_time;
            p[index].et = p[index].st + p[index].bt;
            p[index].tat = p[index].et - p[index].at;
            p[index].wt = p[index].tat - p[index].bt;
            p[index].rt = p[index].st - p[index].at;

            avg_tat += p[index].tat;
            avg_wt += p[index].wt;

            curr_time += p[index].bt;
            visited[index] = 1;
            process_completed++;
        }
        else
        {
            curr_time++;
        }
    }

    cout << endl << endl;

    cout << "PID\t" << "AT\t" << "BT\t" << "ST\t" << "ET\t" << "TAT\t" << "WT\t" << "RT\t" << "\n" << endl;

    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].et << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t" << "\n" << endl;
    }

    cout << endl << endl;

    cout<<"Average Turnaround Time is : "<<(float)avg_tat/n<<endl;
    cout<<"Average Waiting Time is : "<<(float)avg_wt/n<<endl;
	
    return 0;

   
}