#include <iostream>
#include <queue>
using namespace std;
struct Process {
int pid, bt, rt, wt, tat;
};
int main() {
int n, tq;
cout << "Enter number of processes: ";
cin >> n;
Process p[n];
for(int i = 0; i < n; i++) {
p[i].pid = i + 1;
cout << "Enter Burst Time for Process " << p[i].pid << ": ";
cin >> p[i].bt;
p[i].rt = p[i].bt; // remaining time
}
cout << "Enter Time Quantum: ";
cin >> tq;
int time = 0, completed = 0;
queue<int> q;
for(int i = 0; i < n; i++) q.push(i);
while(!q.empty()) {
int i = q.front();
q.pop();
if(p[i].rt > tq) {
time += tq;
p[i].rt -= tq;
q.push(i); // re-queue the process
} else {
time += p[i].rt;
p[i].wt = time - p[i].bt;
p[i].tat = time;
p[i].rt = 0;
completed++;
} }
float avgWT = 0, avgTAT = 0;
cout << "\nProcess\tBT\tWT\tTAT\n";
for(int i = 0; i < n; i++) {
cout << p[i].pid << "\t" << p[i].bt
<< "\t" << p[i].wt << "\t" << p[i].tat << endl;
avgWT += p[i].wt;
avgTAT += p[i].tat;
}
cout << "\nAverage Waiting Time = " << avgWT / n;
cout << "\nAverage Turnaround Time = " << avgTAT / n << endl; return 0;
}
