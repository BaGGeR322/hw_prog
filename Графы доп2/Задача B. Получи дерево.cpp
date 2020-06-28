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

struct graf {
    int x, y; 
    graf() {};
    graf(int a, int b) {
        x = a;
        y = b;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector <graf>  graph(m); 
    vector <graf> tree; 
    vector <int> variety(n + 1); 

   
    for (int i = 1; i <= n; i++) {
        variety[i] = i;
    }

    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[i].x = a;
        graph[i].y = b;
    }

   
    for (int i = 0; i < m; i++) {
        int a = graph[i].x;
        int b = graph[i].y;

        if (variety[a] != variety[b]) {
            tree.push_back(graph[i]);

            int old_variety = variety[b], new_variety = variety[a];

            for (int j = 0; j < n; j++) {
                if (variety[j] == old_variety) {
                    variety[j] = new_variety;
                }
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) { 
        cout << tree[i].x << " " << tree[i].y << endl;
    };
}