#include <iostream>
using namespace std;
int main() {
int n, m;
cout << "Enter number of processes: ";
cin >> n;
cout << "Enter number of resources: ";
cin >> m;
int alloc[n][m], max[n][m], avail[m];
cout << "Enter Allocation Matrix:\n";
for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> alloc[i][j];
cout << "Enter Maximum Matrix:\n";
for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> max[i][j];
cout << "Enter Available Resources:\n";
for(int i=0;i<m;i++) cin >> avail[i];
int need[n][m], finish[n]={0}, safeSeq[n], work[m];
for(int i=0;i<m;i++) work[i]=avail[i];
for(int i=0;i<n;i++) for(int j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
int count=0;
while(count<n){
bool found=false;
for(int i=0;i<n;i++){
if(!finish[i]){
int j;
for(j=0;j<m;j++) if(need[i][j]>work[j]) break;
if(j==m){
for(int k=0;k<m;k++) work[k]+=alloc[i][k];
safeSeq[count++]=i;
finish[i]=1;
found=true;
}
}
}
if(!found){ cout<<"System is not in a safe state\n"; return 0; }
}
cout<<"System is in a safe state.\nSafe sequence: ";
for(int i=0;i<n;i++) cout<<"P"<<safeSeq[i]<<" ";
cout<<endl;
return 0;
}
