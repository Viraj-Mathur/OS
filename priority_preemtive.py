p1 = ['p1', 'p2', 'p3', 'p4']
BT = [10, 5, 7, 8]
CT = [0, 0, 0, 0]
TAT = [0, 0, 0, 0]
WT = [0, 0, 0, 0]
AT = [0, 0, 0, 0]

PRIORITY = [3, 4, 1, 2]

A = 0  # A variable to keep track of the current time.

while True:
    remaining_processes = [i for i in range(len(BT)) if BT[i] > 0]

    if not remaining_processes:
        break  # All processes are completed.

    min_priority = min(PRIORITY[i] for i in remaining_processes)
    min_priority_processes = [i for i in remaining_processes if PRIORITY[i] == min_priority]

    min_index = min_priority_processes[0]

    A += 1
    BT[min_index] -= 1

    for i in remaining_processes:
        if i != min_index and AT[i] <= A:
            PRIORITY[i] += 1

    if BT[min_index] == 0:
        CT[min_index] = A
        TAT[min_index] = CT[min_index] - AT[min_index]
        WT[min_index] = TAT[min_index] - BT[min_index]
        PRIORITY[min_index] = 9999

print("Process\tBT\tAT\tCT\tTAT\tWT")
for i in range(len(BT)):
    print(p1[i], "\t", BT[i], "\t", AT[i], "\t", CT[i], "\t", TAT[i], "\t", WT[i])

print("Average TAT: ", sum(TAT) / len(TAT))
print("Average WT: ", sum(WT) / len(WT))
