#include <bits/stdc++.h>

using namespace std;

class Process {
public:
    int pid;
    int at;
    int bt;
    int et;
    int st;
    int rt;
    int tat;
    int wt;
};

int main() {
    cout << "Enter number of processes: " << endl;
    int n;
    cin >> n;

    Process p[n];
    float avg_tat = 0;
    float avg_wt = 0;

    int process_completed = 0;
    int curr_time = 0;
    bool visited[n];
    int remaining_bt[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time for " << i + 1 << " process: " << endl;
        cin >> p[i].at;
        cout << "Enter burst time for " << i + 1 << " process: " << endl;
        cin >> p[i].bt;

        remaining_bt[i] = p[i].bt;
        p[i].pid = i + 1;
    }

    while (process_completed != n) {
        int index = -1;
        int max_bt = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= curr_time && !visited[i]) {
                if (remaining_bt[i] > max_bt) {
                    index = i;
                    max_bt = remaining_bt[i];
                }
                if (remaining_bt[i] == max_bt) {
                    if (p[i].at < p[index].at) {
                        index = i;
                        max_bt = remaining_bt[i];
                    }
                }
            }
        }

        if (index != -1) {
            if (remaining_bt[index] == p[index].bt) {
                p[index].st = curr_time;
            }

            remaining_bt[index] -= 1;
            curr_time++;

            if (remaining_bt[index] == 0) {
                p[index].et = curr_time;
                p[index].tat = p[index].et - p[index].at;
                p[index].wt = p[index].tat - p[index].bt;
                p[index].rt = p[index].st - p[index].at;

                process_completed++;
                visited[index] = 1;

                avg_tat += p[index].tat;
                avg_wt += p[index].wt;
            }
        } else {
            curr_time++;
        }
    }

    cout << endl << endl;

    cout << "PID\t" << "AT\t" << "BT\t" << "ST\t" << "ET\t" << "TAT\t" << "WT\t" << "RT\t" << "\n" << endl;

    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].st << "\t" << p[i].et << "\t" << p[i].tat << "\t" << p[i].wt << "\t" << p[i].rt << "\t" << "\n" << endl;
    }

    cout << endl << endl;

    return 0;
}
