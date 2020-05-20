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

ifstream fin("input.txt");
ofstream fout("output.txt");


class RadixSort
{
private:
    vector<int> sequence;
    int size = 0;
    int range = 10;
    int value;
    int Max = -1000000;

public:

    RadixSort();
    void Sort(int t);
    void print();

};

RadixSort::RadixSort()
{

    while (fin>>value)
    {
        sequence.push_back(value);
        Max = max(value, Max);
    }

    this->size = sequence.size();

    for (int t = 1; Max / t > 0; t *= 10) Sort(t);
    
    print();
};

void RadixSort::Sort(int t) {

    vector<vector<int> >count(range, vector<int>(1, -1));

    for (int i = 0; i < size; ++i) {

        if(count[(sequence[i] / t) % 10][0]==-1)
            count[(sequence[i] / t) % 10][0] = sequence[i];

        else count[(sequence[i] / t) % 10].push_back(sequence[i]);
    }

    int k = 0;

    for (int i = 0; i < range; ++i) {

        if (count[i][0] != -1)
            for (int j = 0; j < count[i].size(); ++j) {

                 sequence[k] = count[i][j];
                 k++;

            }
    }
    

}

void RadixSort::print() {

    for (int i = 0; i < size; ++i)cout << sequence[i] << " ";

}


int main()
{

    RadixSort sort;

}