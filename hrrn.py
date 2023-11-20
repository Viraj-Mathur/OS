P = ['P1', 'P2', 'P3', 'P4', 'P5']
AT = [1,3,5,7,8]
BT = [3,6,8,4,5]
CT = [0,0,0,0,0]
TAT = [0,0,0,0,0]
WT = [0,0,0,0,0]
R = [0,0,0,0,0]
RR = [0,0,0,0,0]

A = min(AT)

for x in range(len(BT)):
    for i in range(len(BT)):
        if AT[i] <=A:
            R[i] = 1
    # The inner loop sets the flag R[i] to 1 for processes that have arrived by the current time A.
    for i in range(len(BT)):
        if R[i] ==1:
            RR[i] = (A-AT[i] + BT[i] )/BT[i]
    # The inner loop calculates the response ratio RR[i] for processes that have arrived by the current time A.
    index = RR.index(max(RR)) #highest response ratio
    A = A + BT[index]
    CT[index] = A
    TAT[index] = CT[index] - AT[index]
    WT[index] = TAT[index] - BT[index]
    AT[index] = 9999
    RR[index] = -1
    
print("Process\tBT\tAT\tCT\tTAT\tWT")
for i in range(len(BT)):
    print(P[i],"\t",BT[i],"\t",AT[i],"\t",CT[i],"\t",TAT[i],"\t",WT[i])

print("Average TAT: ",sum(TAT)/len(TAT))
print("Average WT: ",sum(WT)/len(WT))
