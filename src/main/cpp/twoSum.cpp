#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define MAX 10000
#define NA -1e9

typedef pair<int,int> pii;

int arr[MAX];

// O(nlogn)
pii twoSumUsingTwoPointer(int target, int arrSize){
	//if array is not sorted
	sort(arr, arr+arrSize);

	//using two pointers to iterat
	int l=0, r=arrSize-1;

	while (l<r){
		if (arr[l]+arr[r] == target) return pii(arr[l],arr[r]);
		if (arr[l] + arr[r] > target) r--;
		else l++;
	}

	return pii(NA,NA);
}

// O(n)
pii twoSumUsingHashMap(int target, int arrSize){
	unordered_map<int,int> mp;

	for (int i=0;i<arrSize; i++)
		mp[arr[i]]++;

	for (int i=0;i<arrSize;i++){
		int comp = target - arr[i];
		if (comp == arr[i] && mp[comp] > 1) //if target - arr[i] == arr[i], we should make sure we have more than one arr[i] 
			return pii(comp, comp);
		else if (comp != arr[i] && mp.find(comp)!=mp.end())// otherwise, just check if there is any target - arr[i]
			return pii(arr[i], comp);
	}

	return pii(NA,NA);
}


int main(){
	int target, arrSize;

	while (cin >> arrSize){
		for (int i=0; i< arrSize; i++)
			cin >> arr[i];
		cin >> target;

		pii ans = twoSumUsingHashMap(target, arrSize);
		if (ans.first == NA)
			cout << "not possible" << endl;
		else
			cout << ans.first << "," << ans.second << endl;
	}
}