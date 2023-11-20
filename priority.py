p1 = ['p1','p2','p3','p4']
BT = [10,5,7,8]
CT = [0,0,0,0]
TAT = [0,0,0,0]
WT = [0,0,0,0]
AT = [0,0,0,0]

PRIORITY = [3,4,1,2]

A = 0 #A variable to keep track of the current time.

for i in range(len(BT)):
    index = PRIORITY.index(min(PRIORITY))
    A = A + BT[index]
    CT[index] = A  
    TAT[index] = CT[index] - AT[index]
    WT[index] = TAT[index] - BT[index]
    PRIORITY[index] = 9999

print("Process\tBT\tAT\tCT\tTAT\tWT")
for i in range(len(BT)):
    print(p1[i],"\t",BT[i],"\t",AT[i],"\t",CT[i],"\t",TAT[i],"\t",WT[i])
    
print("Average TAT: ",sum(TAT)/len(TAT))
print("Average WT: ",sum(WT)/len(WT))
