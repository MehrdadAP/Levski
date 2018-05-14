// topological order
/*
https://careercup.com/question?id=5661961281863680

Determine the alphabet order. 

Ex- 
6
<A, B> 
<C, D> 
<C, E> 
<D, E> 
<A, C> 
<B, C> 

6
A B
C D
C E
D E
A C
B C

*/


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

#define MAX 1000

vector<int> adj[MAX];
vector<bool> visited;
vector<int> topol;
unordered_map<char, int> mp;
char revmp[MAX];


void dfs(int v){
	visited[v]=true;
	for (int i=0;i<adj[v].size();i++){
		int u = adj[v][i];
		if (!visited[u]) dfs(u);
	}
	topol.push_back(v);
}

int main(){
	int cnt=0, N;
	cin >> N;
	char x,y;
	for (int i=0;i<N; i++){
		cin >> x >> y;
		if (mp.find(x)==mp.end()){
			mp[x] = cnt;
			revmp[cnt] = x;
			cnt++;
		}
		if (mp.find(y) == mp.end()){
			mp[y] = cnt;
			revmp[cnt] = y;
			cnt++;
		}

		adj[mp[x]].push_back(mp[y]);
	}

	visited.resize(cnt, false);
	topol.clear();
	for (int i=0;i<cnt; i++){
		if (!visited[i])
			dfs(i);
	}
	reverse(topol.begin(), topol.end());
	for (int i=0;i<cnt;i++){
		cout << revmp[topol[i]] << " ";
	}
	cout << endl;

	return 0;
}