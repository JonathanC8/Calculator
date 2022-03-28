#include "main.h"

void MedModRun();
void otherActions();
void basicCalculator();
void main() {
	string input;
	cout << "Welcome to my calculator!\n";
	while(input != "end") {
		cout << "Type Basic for the basic Calculator: ";
		cin >> input;
		if (input == "Basic") {
			basicCalculator();
		}
		else if (input == "o") {
			otherActions();
		}
	}
}

void otherActions() {
	char input = 'a';
	while (input == 'a') {
		cout << "Welcome to other actions for testing!";
		cout << "Enter letter according to the action you want to use: ";
		cin >> input;
		if (input == 'M') {
			MedModRun();
		}
	}
}

void basicCalculator() {
	double output = 0;
	double inputA = 0;
	double inputB = 0;
	char op = 'a';
	while (op != 'e') {
		cout << "Enter expression: ";
		cin >> inputA;
		cin >> op;
		cin >> inputB;
		if (op == '+') {
			output = addition(inputA, inputB);
		}
		else if (op == '-') {
			output = subtraction(inputA, inputB);
		}
		else if (op == '*') {
			output = multiplication(inputA, inputB);
		}
		else if (op == '/') {
			output = division(inputA, inputB);
		}

		cout << "Output: ";
		cout << output;
		cout << "\n";
	}
}
