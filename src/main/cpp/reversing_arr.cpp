#include <iostream>

using namespace std;

#define MAX 10000

int nums[MAX];


void reverseArr(int* a, int size){
	for (int i=0;i<size/2;i++)
		swap(a[i], a[size-i-1]);
}

void printArr(int a[], int size){
	cout << endl;
	for (int i=0;i<size;i++)
		cout << a[i] << " ";
	cout << endl;
}

void reverseRec(int* a, int start, int end){
	if (end<start) return;

	swap(a[start], a[end]);
	reverseRec(a, start+1, end-1);
}

int main(){

	int N;
	cin >> N;

	for (int i=0;i<N;i++)
		cin >> nums[i];

	//reverseArr(nums, N);
	reverseRec(nums, 0, N-1);
	printArr(nums, N);

	return 0;
}