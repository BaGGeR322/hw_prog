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

	int n, maximum = 0;
	cin >> n;
	vector< vector<int> > graf(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> graf[i][j];

	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				graf[i][j] = min(graf[i][j], graf[i][k] + graf[k][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			maximum = max(graf[i][j], maximum);

	cout << maximum;
}