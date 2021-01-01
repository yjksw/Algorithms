//wrong answer
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int> > alphaDegree(26, vector<int>(26, 0));
vector<string> graph[26][26];
vector<int> in(26, 0);
vector<int> out(26, 0);
vector<string> wordlist;
vector<int> ans;
vector<string> print;

int n;

void dfs(int index) {
	for (int next = 0; next < 26; next++) {
		while(alphaDegree[index][next] > 0) {
			alphaDegree[index][next]--;
			dfs(next);
		}
	}
	ans.push_back(index);
}

int main() {

	scanf("%d", &n);
	wordlist.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> wordlist[i];
	}

	sort(wordlist.begin(), wordlist.end());


	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			graph[i][j].clear();
		}
	}

	for (int i = 0; i < n; i++) {
		int front = wordlist[i].front() - 'a';
		int back = wordlist[i].back() - 'a';
		graph[front][back].push_back(wordlist[i]);
		alphaDegree[front][back]++;
		out[front]++;
		in[back]++;
	}

	int impossible = 0; 
	int start = 0;
	int end = 0;

	for (int i = 0; i < 26; i++) {
		if (out[i] - in[i] > 1 || out[i] - in[i] < -1) {
			impossible = 1;
			break;
		}
		if (out[i] - in[i] == 1) 
			start++;
		if (out[i] - in[i] == -1)
			end++;
	}

	/*if (impossible == 1 || (start != -1 && end == -1) || (start == -1 && end !=-1)) {
	  cout << "0";
	  return 0;
	  }*/

	impossible |= !((start == 1 && end == 1) || (start == 0 && end == 0));

	if (impossible) {
		cout << "0";
		return 0;
	}

	int done = 0;
	for(int i = 0; i < 26 && done == 0; i++) {
		if (out[i] == in[i] + 1) {
		//if (start != -1 && end != -1) {
			dfs(i);
			done = 1;
		}
	}

	for(int i = 0; i < 26 && done == 0; i++) {
		if(out[i]) {
			dfs(i);
			done = 1;
		}
	}

	/*for (int i = 0; i < ans.size(); i++) {
		cout << "a " << ans[i] << endl;
	}*/

	if (ans.size() != n + 1) {
		cout << "0";
		return 0;
	}

	reverse(ans.begin(), ans.end());

	for (int i = 1; i < ans.size(); i++) {
		print.push_back(graph[ans[i-1]][ans[i]].front());
		graph[ans[i-1]][ans[i]].erase(graph[ans[i-1]][ans[i]].begin());
	}

	for(int i = 0; i < n; i++) {
		cout << print[i] << endl;
	}

	return 0;
}
