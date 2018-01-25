#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAX 10000
#define NA -1e9

typedef pair<int,int> pii;

int numbers[MAX];

// O(nlogn)
pii twoSumUsingTwoPointer(int target, int arrSize){
	vector< pii > arr;
	for (int i=0;i<arrSize;i++)
		arr.push_back(pii(numbers[i], i+1));

	//if array is not sorted
	sort(arr.begin(), arr.end());

	//using two pointers to iterat
	int l=0, r=arrSize-1;

	while (l<r){
		if (arr[l].first+arr[r].first == target) return pii(arr[l].second,arr[r].second);
		if (arr[l].first + arr[r].first > target) r--;
		else l++;
	}

	return pii(-1,-1);
}

// O(n)
pii twoSumUsingHashMap(int target, int arrSize){
	unordered_map<int,vector<int>> mp;

	for (int i=0;i<arrSize; i++)
		mp[numbers[i]].push_back(i+1);

	for (int i=0;i<arrSize;i++){
		int comp = target - numbers[i];
		if (comp == numbers[i] && mp[comp].size() > 1) //if target - arr[i] == arr[i], we should make sure we have more than one arr[i] 
			return pii(mp[comp][0], mp[comp][1]);
		else if (comp != numbers[i] && mp.find(comp)!=mp.end())// otherwise, just check if there is any target - arr[i]
			return pii(i+1, mp[comp][0]);
	}

	return pii(-1, -1);
}


int main(){
	int target, arrSize;

	while (cin >> arrSize){
		for (int i=0; i< arrSize; i++)
			cin >> numbers[i];
		cin >> target;

		pii ansTwoPointer = twoSumUsingTwoPointer(target, arrSize);
		pii ansHashMap = twoSumUsingHashMap(target, arrSize);
		
		// the answer of the two could be different since the answer to the problem is not unique!
		cout << "Two pointer approach: "<< ansTwoPointer.first << "," << ansTwoPointer.second << endl;
		cout << "Two hashmap approach: "<< ansHashMap.first << "," << ansHashMap.second << endl;
	}
}