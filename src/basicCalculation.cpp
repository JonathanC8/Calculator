#include <iostream>
#include "main.h"
using namespace std;

double addition(double a, double b) {
	double output;
	output = a + b;
	return output;
}

double subtraction(double a, double b) {
	double output;
	output = a - b;
	return output;
}

double multiplication(double a, double b) {
	double output;
	output = a * b;
	return output;
}

double division(double a, double b) {
	double output;
	output = a / b;

	return output;
}

double basicCalculator(double inputA, double inputB, char op) {
	double output = 0;
	if (op == '+') {
		output = addition(inputA, inputB);
	}
	if (op == '-') {
		output = subtraction(inputA, inputB);
	}
	if (op == '*') {
		output = multiplication(inputA, inputB);
	}
	if (op == '/') {
		output = division(inputA, inputB);
	}

	return output;
}


