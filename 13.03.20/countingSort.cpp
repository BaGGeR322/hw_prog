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
#include <sstream>

using namespace std;

int main()
{
	int N, value;
	int negative[10001] = { 0 };
	int positive[10001] = { 0 };

	cin >> N;

	for (int i = 0; i < N; ++i) {

		cin >> value;
		if (value >= 0) positive[value]++;
		else negative[abs(value)]++;

	}
	
	for (int i = 10000; i > 0; i--) {

		for (int j = 0; j < negative[i]; ++j) {
			cout << -i << " ";
		}

	}

	for (int i = 0; i <= 10000; i++) {

		for (int j = 0; j < positive[i]; ++j) {
			cout << i << " ";
            
		}
	}
}