#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main() {
key_t key = ftok("shmfile",65);
int shmid = shmget(key,1024,0666|IPC_CREAT);
char *str = (char*) shmat(shmid,(void*)0,0);
printf("Write Data: ");
fgets(str, 1024, stdin);
printf("Data written in memory: %s\n", str);
shmdt(str);
return 0;
}#include <iostream>
using namespace std;
int main() {
int ms, ps, nop, mp[10], n;
cout << "Enter total memory size: ";
cin >> ms;
cout << "Enter partition size: ";
cin >> ps;
n = ms / ps;
cout << "Total partitions: " << n << endl;
cout << "Enter number of processes: ";
cin >> nop;
for (int i = 0; i < nop; i++) {
cout << "Enter memory required for process " << i+1 << ": ";
cin >> mp[i];
}
for (int i = 0; i < nop && i < n; i++) { if (mp[i] <= ps)
cout << "Process " << i+1 << " allocated in partition " << i+1
<< " with internal fragmentation: " << ps - mp[i] << endl;
else
cout << "Process " << i+1 << " not allocated (too large)." << endl; }
return 0;
}
