/*
Given two lowercase strings, S1 and S2, sort S1 in same order as S2.
If a character in S1 doesn&#39;t exist in S2, put them at the end. If S1 is &quot;program&quot; and S2 is &quot;grapo&quot;, then return "&quot;"grrapom&quot

*/
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int charPriority[26];
bool exist[26];

bool comp(char a, char b){
	return charPriority[a-'a'] < charPriority[b-'a'];
}

string sortAByB(string A, string B){
	for (int i=0;i<26;i++)
		charPriority[i] = 27;

	int prio=0;
	for (int i=0;i<B.size();i++){
		int cur = B[i] - 'a';
		if (charPriority[cur] == 27)
			charPriority[cur] = prio++;
	}

	string result = A;
	stable_sort(result.begin(), result.end(), comp);

	return result;
}

int main(){

	string A, B;
	while (cin >>  A >> B){
		cout << sortAByB(A, B) << endl;
	}

	return 0;
}