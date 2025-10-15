
#include <iostream>
#include <vector>
using namespace std;
int main() {
int n, f, start, length;
cout << "Enter total number of disk blocks: ";
cin >> n;
vector<int> block(n, 0); // 0 = free, 1 = allocated
cout << "Enter number of files: ";
cin >> f;
for (int i = 0; i < f; i++) {
cout << "\nEnter starting block of file " << i+1 << ": ";
cin >> start;
cout << "Enter length of file " << i+1 << ": ";
cin >> length;
bool allocated = true;
for (int j = start; j < start + length; j++) {
if (j >= n || block[j] == 1) {
allocated = false;
break;}
}
if (allocated) {
for (int j = start; j < start + length; j++)
block[j] = 1;
cout << "File " << i+1 << " allocated blocks: ";
for (int j = start; j < start + length; j++)
cout << j << " ";
cout << endl;
} else {
cout << "File " << i+1 << " cannot be allocated." << endl;
}
}
return 0;
} 
