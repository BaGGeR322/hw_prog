#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <map>
#include <cmath>
#include <fstream>
#include <queue>
#include <sstream>

using namespace std;


int main() {
	int n, s, f;
	cin >> n >> s >> f;
	--s;
	--f;
	vector<vector<pair<int, int> > > graf(n);
	vector<int> value(n, 100000000);

	value[s] = 0;
	
	bool *visited = new bool[n];

	//создать граф
	for (int i = 0, tmp; i < n; ++i) {        
		for (int j = 0; j < n; ++j) {
			cin >> tmp;
			if (i != j && tmp != -1) {
				graf[i].push_back(make_pair(j, tmp));
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		int now = -1;
		for (int j = 0; j < n; ++j)        
			//найти минимальную вершину, в которой мы не были
			if (!visited[j] && (now == -1 || value[j] < value[now]))
				now = j;

		if (value[now] == 100000000)
			break;

		visited[now] = true;

		// проверить расстояние до соседей и перезаписать расстояние, если мы пришли с меньшим 
		for (int j = 0; j < graf[now].size(); ++j) {                          
			int to = graf[now][j].first;
			int distance = graf[now][j].second;
			
			value[to] = (value[now] + distance) > value[to] ? value[to] : (value[now] + distance);
		
		}
	}

	if (value[f] == 100000000) cout << -1;
	else cout << value[f];

}