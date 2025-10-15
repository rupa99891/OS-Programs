#include <iostream>
#include <algorithm>
using namespace std;
struct Process {
int pid, bt, priority, wt, tat;
};
// Compare function for sorting based on priority
bool compare(Process a, Process b) {
return (a.priority < b.priority);
}
int main() {
int n;
cout << "Enter number of processes: ";
cin >> n;
Process p[n];
for(int i = 0; i < n; i++) {
p[i].pid = i + 1;
cout << "Enter Burst Time and Priority for Process " << p[i].pid << ": ";
cin >> p[i].bt >> p[i].priority;
}
// Sort processes by priority
sort(p, p + n, compare);
// Calculate Waiting Time and Turnaround Time
p[0].wt = 0;
for(int i = 1; i < n; i++) {
p[i].wt = p[i-1].wt + p[i-1].bt;
}
float avgWT = 0, avgTAT = 0;
for(int i = 0; i < n; i++) {
p[i].tat = p[i].wt + p[i].bt;
avgWT += p[i].wt;
avgTAT += p[i].tat;
}
avgWT /= n;
avgTAT /= n;
cout << "\nProcess\tBT\tPriority\tWT\tTAT\n";
for(int i = 0; i < n; i++) {
cout << p[i].pid << "\t" << p[i].bt << "\t" << p[i].priority
<< "\t\t" << p[i].wt << "\t" << p[i].tat << endl;
}
cout << "\nAverage Waiting Time = " << avgWT;
cout << "\nAverage Turnaround Time = " << avgTAT << endl;
return 0;
} 
