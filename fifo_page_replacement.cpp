#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {
int n, f, page, faults = 0;
cout << "Enter number of frames: ";
cin >> f;
cout << "Enter number of pages: ";
cin >> n;
vector<int> pages(n);
cout << "Enter reference string: ";
for (int i = 0; i < n; i++) cin >> pages[i];
vector<int> frame;
unordered_map<int,int> lastUsed;
for (int i = 0; i < n; i++) {
page = pages[i];
bool found = false;
for (int x : frame) if (x == page) found = true;
if (!found) {
if (frame.size() < f) frame.push_back(page);
else {
int lru_index = 0;
int min_last = i;
for (int j = 0; j < frame.size(); j++) {
if (lastUsed[frame[j]] < min_last) {
min_last = lastUsed[frame[j]]; 
lru_index = j;
}
}
frame[lru_index] = page; 
}
faults++;
}
lastUsed[page] = i;
cout << "Frames: ";
for (int x : frame) cout << x << " ";
cout << endl;
}
cout << "Total Page Faults: " << faults << endl;
return 0;
} 
