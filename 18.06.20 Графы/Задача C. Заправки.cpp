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
	int city, road;
	cin >> city;
	vector<vector<pair<int, int> > > graf(city);
	vector<int> value(city, 0);
	vector<int> minValue(city, 100000000);
	
	bool *visited = new bool[city];
	for (int i = 0; i < city; ++i) {
		cin >> value[i];
		visited[i] = true;
	}


	
	cin >> road;
	//создать граф
	for (int i = 0, from, to; i < road; ++i) {        
		cin >> from >> to;

		//ездить можно в обе стороны 
		graf[from - 1].push_back(make_pair(to - 1, value[from - 1]));
		graf[to - 1].push_back(make_pair(from - 1, value[to - 1]));

		
	}
	
	minValue[0] = 0;
	for (int i = 0; i < city; ++i) {
		int now = -1;
		for (int j = 0; j < city; ++j)        
			//найти минимальную вершину, в которой мы не были
			if (visited[j] && (now == -1 || minValue[j] < minValue[now]))
				now = j;

		if (minValue[now] == 100000000)
			break;

		visited[now] = false;

		// проверить расстояние до соседей и перезаписать расстояние, если мы пришли с меньшим 
		for (int j = 0; j < graf[now].size(); ++j) {                          
			int to = graf[now][j].first;
			int distance = graf[now][j].second;
			
			minValue[to] = (minValue[now] + distance) > minValue[to] ? minValue[to] : (minValue[now] + distance);
		
		}
	}

	if (minValue[city - 1] == 100000000) cout << -1;
	else cout << minValue[city - 1];

}