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


int main() {

	int N;
	cin >> N;
	vector<vector<int> > list(N, vector<int>(2, 0));
	vector<vector<int> > list_2(N, vector<int>(2, 0));

	for (int i = 0; i < N; ++i) {

		cin >> list[i][0] >> list[i][1];

	}


	/*сортировка по времени окончания*/
	for (int i = 0; i < N - 1; ++i) {

		int k = 0;
		for (int j = 0; j < N - i - 1; ++j) {

			if (list[j][1] > list[j + 1][1]) {

				swap(list[j][0], list[j + 1][0]);
				swap(list[j][1], list[j + 1][1]);
				++k;

			}
		}
		if (k == 0)break;
	}



	int k = 0;


	for (int i = 0; i < list.size(); ++i) {
		if (list[i][0] == 0)continue;

		/*идём по массиву в порядке увеличения времени окончания*/
		for (int j = i + 1; j < list.size(); ++j) {
			if (list[j][0] == 0)continue;   

			/*если время начала одного раньше, чем окончание нанешнего, вычёркиваем первый*/
			if (list[i][1] > list[j][0])
			{
				list[j][0] = 0;     /*поставить нулевое время окончание = вычеркнуть объект*/
				k++;
			}
		}
	}

	cout << N - k;


}