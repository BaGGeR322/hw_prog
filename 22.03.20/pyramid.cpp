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

class Heap
{

private:

	int p, index, root = 0;
	int size = 0;
	vector <int> piramid;

public:

	//добавление в пирамиду 
	void heapify(int number) {

		index = size;
		piramid.push_back(number);
		size++;
		p = (index - 1) / 2;
		while (p >= 0 && piramid[p] < piramid[index]) {

			p = (index - 1) / 2;;
			swap(piramid[p], piramid[index]);
			index = p;
			p = (index - 1) / 2;;

		}

	}

	//числа опускается на своё место
	void inplace(int i) {
		int cur = i;
		if (2 * i + 1 < size && piramid[2 * i + 1] > piramid[cur])
			cur = 2 * i + 1;
		if (2 * i + 2 < size && piramid[2 * i + 2] > piramid[cur])
			cur = 2 * i + 2;
		if (cur != i)

		{
			swap(piramid[i], piramid[cur]);
			inplace(cur);
		}
	}



	//удаление из кучи
	void del(int i) {

		swap(piramid[i], piramid[size - 1]);
		size--;
		inplace(i);

	}


	//пирамидальная сортировка
	void sorted() {
		int s = size;
		for (int i = 0; i < s; ++i) {

			del(0);

		}
		print();

	}


	void maximum() {
		cout << piramid[0];
	}

	void minimum() {
		int m = piramid[0];
		for (int i = 1; i < size; ++i) {
			m = m > piramid[i] ? piramid[i] : m;
		}
		cout << m;
	}


	void print() {
		for (int i = 0; i < piramid.size(); ++i)
			cout << piramid[i] << " ";
	}

};



int main()
{
	Heap heap;
	int N, k;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> k;
		heap.heapify(k);
	}

	heap.sorted();

}
