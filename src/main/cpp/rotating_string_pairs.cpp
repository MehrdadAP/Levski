
/*

You are given an array of strings. For example, 	[&quot;AB&quot;, &quot;BC&quot;, &quot;FOO&quot;, &quot;ZA&quot;, &quot;BAZ&quot;]
- 	Output strings where you can get from one to the other using any ROT transformation.

	ROT_1(AB) = BC
	ROT_1(BC) = CD
	ROT_25(AB) = ZA
	AB,BC you can go from one to the other using ROT_1
	Input: list of strings
	Output: strings where you can get from one to the other using any ROT transformation.
	Example:
	Input : [&quot;AB&quot;, &quot;BC&quot;, &quot;FOO&quot;, &quot;ZA&quot;, &quot;BAZ&quot;]
	Output: [ [ab, bc] , [ab, za] ]
	AB,BC because you can go from one to the other using ROT_1
	AB,ZA because you can go from one to the other using ROT_25
	Do not return FOO, BAZ you can’t get from one to the other.

*/


#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;


string rotate(string str){
	string res="";
	for (int i=0;i<str.size();i++){
		res += (char)((((str[i]-'a') + 1)%26) + 'a');
	}

	return res;
}


int main(){
	unordered_set<string> st;
	string s;
	int N;
	cin >> N;

	for (int i=0;i<N;i++){
		cin >> s;
		string rotated = s;
		for (int k=0;k<25;k++){
			rotated = rotate(rotated);
			if (st.find(rotated)!=st.end())
				cout << s << " " << rotated << endl;
		}
		st.insert(s);
	}


	return 0;
}