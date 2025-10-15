

#include <iostream>

#include <vector>

using namespace std;

int main() {

int n, f, indexBlock, length;

cout <<"Enter total number of disk blocks: ";

cin>> n;

vector<int> block(n, 0);

cout << "Enter number of files: ";

cin >> f;

for (int i = 0; i<f; i++) {

cout << "\nEnter index block for file " << i+1 <<": ";


cin >> indexBlock;

if (block[indexBlock] == 1) {

cout << "Index block already allocated. File cannot be stored.\n";

continue;

block[indexBlock] = 1;

cout <<"Enter number of blocks needed for file "<< i+1 <<": ";

cin>> length;

vector<int> allocated;

cout << "Enter block numbers: ";

for (int j= 0; j< length; j++) {

int b;

cin >> b;

if (b<n && block[b]== 0) { block[b] = 1;

allocated.push_back(b);

} else {

cout << "Block "<<b <<" already allocated or invalid.\n";

return 0;

Output:

cout << "File " << i+1 <<" stored using index block "<< indexBlock << ">";

for (int b: allocated){
cout <<b<<""<<endl;
}
}
