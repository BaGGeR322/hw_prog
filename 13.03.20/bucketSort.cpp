#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <time.h>
#include <algorithm>
#include <limits.h>
#include <cstdlib>
#include <stdio.h>
#include <map>
#include <cmath>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


//функция проверки работы алгоритма 

bool checking(vector <int>& arr) {

    vector <int> check(0);
    for (int i = 0; i < arr.size(); ++i)
        check.push_back(arr[i]);

    sort(check.begin(), check.end());

    cout << endl << "Проверка:  ";
    for (int i = 0; i < check.size(); ++i) {

        if (check[i] != arr[i]) return false;

    }

    return true;



}


//генератор чисел для сортировки 
void random(vector <int> &arr, int n) {

    srand(time(NULL));
    cout << endl << "Входные данные:  ";
    for (int i = 0; i < n; ++i) {

        arr[i] = rand();
        cout << arr[i] << " ";

    }
    cout << endl << "-------------------------------------------------------------------------" << endl;
    

}

//алгоритм 
void bucketSort(vector <int>& arr , int n) {

    vector<vector<int>> buckets(n / 2);

    int Min = arr[0];
    int Max = arr[0];
    int numBuckets = n / 2;

    for (int i = 0; i < n; ++i) {

        if (Min > arr[i])
            Min = arr[i];

        else if (Max < arr[i])
            Max = arr[i];
    }

    int r = (Max - Min) / n;
    int index;

    for (int i = 0; i < n; ++i) {

        index = (int)((arr[i] - Min) / r);

        buckets[index >= numBuckets ? numBuckets - 1 : index].push_back(arr[i]);
    }

    for (int i = 0; i < numBuckets; ++i) {

        sort(buckets[i].begin(), buckets[i].end());

    }

    cout << endl << "Выходные данные:  ";
    for (int i = 0, k = 0; i < numBuckets; ++i)
        for (int j = 0; j < buckets[i].size(); ++j, ++k) {
            arr[k] = buckets[i][j];
            cout << arr[k] << " ";

        }
            

    cout << endl << "-------------------------------------------------------------------------" << endl;

}

int main()
{
    setlocale(LC_ALL, "ru");

    int n;
    cin >> n;
    vector<int> arr(n);

    random(arr, n);

    bucketSort(arr, n);

    if (checking(arr)) cout << "TRUE";
    else cout << "FALSE";




}