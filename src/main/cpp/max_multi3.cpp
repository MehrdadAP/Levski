/*
A unsorted array of integers is given; you need to find the max product formed my multiplying three numbers. 
(You cannot sort the array, watch out when there are negative numbers)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000

int arr[MAX];
int maxi[MAX][3], mini[MAX][3];


int main(){

	int N;
	cin >> N;

	for (int i=0;i<N;i++){
		cin >> arr[i];
	}

	maxi[0][1] = mini[0][1]= arr[0];

	for (int i=1;i<N;i++){
		maxi[i][1] = max(maxi[i-1][1], arr[i]);
		mini[i][1] = min(mini[i-1][1], arr[i]);
	}

	for (int j=2;j<=3;j++){
		for (int i=1;i<N;i++){
			maxi[i][j] = max(maxi[i-1][j], max(maxi[i-1][j-1]*arr[i], mini[i-1][j-1]* arr[i]));
			mini[i][j] = min(mini[i-1][j], min(mini[i-1][j-1]*arr[i], maxi[i-1][j-1]* arr[i]));
		}
	}

	cout << maxi[N-1][3] << endl;

	return 0;
}