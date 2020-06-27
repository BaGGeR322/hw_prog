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

void dfs(vector <vector <int> > graf, vector <int> color, int index, bool &cycle) {
	color[index] = 1;
	for (int i = 0; i < color.size(); ++i)
	{
		if (cycle)return;
		
		if (graf[index][i] == 1) {
			if (color[i] == 0) {
				dfs(graf, color, i, cycle);
			}
			else if (color[i] == 1) {
				cycle = true;
				return;
			}

		}

	}
	color[index] = 2;
	
}

int main() {
	int n;
	cin >> n;
	vector <int> color(n, 0);
	vector< vector<int> > graf(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> graf[i][j];
		
	int i = 0;
	bool cycle = false;
	for (int i = 0; i < n; i++)
	{


		dfs(graf, color, i, cycle);
	}
	if (cycle) cout << 1;
	else cout << 0;
	


}