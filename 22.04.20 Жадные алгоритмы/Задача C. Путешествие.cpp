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

	/*Путь,  на сколько хватит безнина,   количество заправок,  количество остановок   */
	int S , gas_km, stations, stops = 0;

	cin >> S >> gas_km >> stations;

	/*расстояние до каждой остановки*/
	vector <int> station_km(stations, 0);

	for (int i = 0; i < stations; ++i) {

		cin >> station_km[i];

	}


	/*если первая остановка дальше, чем может проехать автомобиль*/
	if (station_km[0] > gas_km) {
		cout << -1;
		return 0;
	}

	/*точно проехал*/
	int kilometers = gas_km;


	/*подсчёт сколько может проехать автомобиль*/
	for (int i = 0; i < stations; ++i) {

		if (kilometers >= S) {
			break;
		}

		if (station_km[i] == kilometers) {

			kilometers = station_km[i] + gas_km;
			stops++;

		}

		else if (station_km[i] > kilometers) {

			kilometers = station_km[i - 1] + gas_km;
			stops++;

		}

	}


	/*если проехал меньше, чем весь путь*/
	if (kilometers < S) {
		cout << -1;
		return 0;
	}

	cout << stops;
}