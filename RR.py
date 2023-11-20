process = [1,2,3]
BT = [5,3,2]
AT = [0,1,2]
QT = 2

n = len(process)
remaining_BT = list(BT)
CT = [0] * n
TAT = [0] * n
WT = [0] * n
time = 0

while True:
    for i in range(n):
        if remaining_BT[i] > 0:
            if remaining_BT[i] > QT:
                time += QT
                remaining_BT[i] -= QT
            else:
                time += remaining_BT[i]
                CT[i] = time
                remaining_BT[i] = 0
    if all(t == 0 for t in remaining_BT):
        break
    
    for i in range(n):
        TAT[i] = CT[i] - AT[i]
        WT[i] = TAT[i] - BT[i]
        
print("Process\tBT\tAT\tCT\tTAT\tWT")
for i in range(n):
    print(process[i],"\t",BT[i],"\t",AT[i],"\t",CT[i],"\t",TAT[i],"\t",WT[i])
    
print("Average TAT: ",sum(TAT)/n)
print("Average WT: ",sum(WT)/n)
            