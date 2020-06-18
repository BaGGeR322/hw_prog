
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <set>
#include <ctime>
#include <algorithm>
#include <limits.h>
#include <stdio.h>
#include <map>
#include <cmath>
#include <fstream>
#include <sstream>
using namespace std;


const int max_len = 1024; // максимальный размер хеш-таблицы

struct Node {
    string key;
    string value;
    Node* next = NULL;
    Node* prev = NULL;

    Node(string key, string value) {
        this->key = key;
        this->value = value;
    }
};

void createWords() {   //создать данные для Хеш-таблицы      

    srand(time(0));
    ofstream fout("input.txt");

    int i = 0;

   

    char* key_value = new char[20];


    for (int j = 0; j < 10000; ++j)
    {

        int size_key = 1 + rand() % 7;
        int size_value = 1 + rand() % 10;

        for (i = 0; i < size_key; ++i)
        {
            key_value[i] = 'A' + rand() % 26;
        }

        key_value[i] = ' ';
        ++i;

        for (i; i < size_value + size_key + 1; ++i)
        {
            key_value[i] = 'a' + rand() % 26;
        }

        key_value[i] = '\n';
        key_value[i + 1] = '\0';

        fout << key_value;

    }
}





int Hash(string text) {

    int sum = 0;
    for (int i = 0; i < text.length(); ++i) {
        sum += text[i];
    }

    return sum;
}

void Set(Node* table[], string key, string value) {

    int index = Hash(key) % max_len;
    Node* cur = table[index];

    if (table[index] == NULL) {
        table[index] = new Node(key, value);
        return;
    }


    table[index] = new Node(key, value);
    table[index]->next = cur;
    cur->prev = table[index];


}

string search(Node* table[], string key) {

    int index = Hash(key) % max_len;
    Node* cur = table[index];

    while (cur != NULL)
    {
        if (cur->key == key)
            return cur->value;
        cur = cur->next;
    }

    return "0";
}

void print(Node* table[]) {
    int count = 0;

    for (int i = 0; i < max_len; i++)
    {
        cout << i << ')' << endl;

        Node* cur = table[i];

        while (cur != NULL)
        {
            cout << cur->key << " " << cur->value << endl;
            cur = cur->next;
            count++;
        }

        cout << endl;
    }

    cout << count;
}

void get(Node* table[], string key) {
    int index = Hash(key) % max_len;
    Node* cur = table[index];

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            if (cur->next != NULL) {
                if (cur != table[index]) {
                    cur->next->prev = cur->prev;
                    cur->prev->next = cur->next;

                    delete cur;
                    return;
                }
                else table[index] = cur->next;
            }
            
            cur->prev->next = NULL;
            delete cur;

            return;
        }

        cur = cur->next;
    }

    cout << "Takogo key net" << endl;
}

int main() {
    ifstream fin("input.txt");
   

    Node* table[max_len]{ NULL };

    //createWords();


    string key;
    string value;



    while (fin >> key, fin >> value)
    {

        Set(table, key, value);

    }

    fin.close();

  
    ifstream f("input.txt");
    int count = 0;



     unsigned int start_time = clock();
     while (f>>key)
     {
         cout << search(table, key) << endl;
         f >> key;
         count++;
         

     }
     unsigned int end_time = clock();
     cout << end_time - start_time << endl;
     cout << count;



}
