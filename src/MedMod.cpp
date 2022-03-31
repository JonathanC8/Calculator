#include <iostream>
#include "main.h"
using namespace std;

int arrayx[] = { 1,1,2,3 };
void findMode();
int y = 0;

void MedModRun() {
	findMode();
	char input = 'a';
	cout << "\n";
	while (input != 'y') {
		cout << "Would you like to be sent back to the Calculator? y=Yes";
		cin >> input;
		if (input == 'y') {
			break;
		}
		else {
			findMode();
		}
	}
}

void findMode() {
	cout << "The Mode is: ";
	int length = (sizeof(arrayx) / 4)-1;
	int arrayy[(sizeof(arrayx) / 4)] = { };
	for (int i = 0; i <= length;i++) {
		for (int j = 0; j <= length;j++) {
			if (arrayx[i] == arrayx[j] && arrayy[j] < 2) {
				arrayy[i]++;
			}
		}
	}

	for (int i=0; i <= length; i++) {
		if (arrayy[i] >= 2) {
			for (int j = 1; j <= arrayy[i]; j++) {
				cout << arrayx[i] << " ";
			}
		}
	}
	
}