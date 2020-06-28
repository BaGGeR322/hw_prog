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

bool permut(int* arr, int n) {

	int i = n - 2;
	while (i != -1 && arr[i] >= arr[i + 1]) --i;
	if (i == -1)
		return false;

	int k = n - 1;
	while (arr[i] >= arr[k]) --k;

	swap(arr[i], arr[k]);
	int l = i + 1, r = n - 1; 
	while (l < r) {
		swap(arr[l++], arr[r--]);
	}

	return true;
}
int main(){
	int n;
	cin >> n;
	int* arr = new int[n];
    
	for (int i = 0; i < n; ++i) {
		arr[i] = i + 1;
		cout << arr[i];
	}
	cout << endl;

	while (permut(arr, n)) {
		for (int i = 0; i < n; ++i) cout << arr[i];
		cout << endl;
	}
	


}