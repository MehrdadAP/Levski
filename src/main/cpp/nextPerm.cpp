
// Given an array of numbers (duplicate is allowed), find the next greatest lexicographical permuattion
// if not possible, rotate and return the smallest one. 
// 4,3,1,5 -> 4 3 5 1
// 3,2,1 -> 1,2,3



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> nums;
	int N;

	cin >> N;
	nums.resize(N);

	for (int i=0;i<N;i++)
		cin >> nums[i];

	int pos=N-1;
	while (pos>=1 && nums[pos] <= nums[pos-1]) pos--;
	pos--;
	if (pos!=-1){
		int maxIndex = pos+1;
		for (int i=pos+1;i<N;i++)
			if (nums[i]> nums[pos] && nums[i]<nums[maxIndex])
				maxIndex = i;

		swap(nums[pos], nums[maxIndex]);	
	}
	
	sort(nums.begin()+pos+1, nums.end());

	for (int i=0;i<N;i++)
		cout << nums[i] << " ";
	cout << endl;


	return 0;
}