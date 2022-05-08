#include "main.h"
#include <iostream>
#include <string>
using namespace std;

float extra::expressionCalculator(float floatyExpr[256], int order[256]) {
		float solution = 0.f;
		int paraCount1 = 0;
		int paraCount2 = 0;
		int paraLocator[256] = {};
		/*
		for (int x = 0; x < exLength; x++) {
			if (expression[x] == '(') {
					paraCount1++;
					paraLocator[x] = paraCount1;
			}
			else if(expression[x] == ')') {
					paraCount2--;
					paraLocator[x] = paraCount2;
			}
		}

		float orderedFloats[256][2] = { };
		string number = "";
		bool ordered = false;
		if (paraCount1 != 0) {
			int x = 0;
			int y = 0;
			int order = 0;
			while (ordered) {
				x++;
				if (paraLocator[x] == paraCount1) {
					int counter = x;
					while (expression[counter] != ')') {
						if (expression[counter] == '+') {
							orderedFloats[order][0] = atof(number.c_str());
							orderedFloats[order++][1] = 5;
						}
						else {
							number[y++] = expression[counter++];
						}
					}
					x = 0;
					paraCount1--;
				}

				if (paraCount1 == 0)
					ordered = true;
			}
		}
		else {
			int x = 0;
			int y = 0;
			for (int i = 0; i < exLength; i++) {
				if (expression[i] == '*') {
					orderedFloats[y][1] = 3;
					orderedFloats[y++][0] = atof(number.c_str());
					x = 0;
				}
				else if(expression[i] == '/') {
					orderedFloats[y][1] = 4;
					orderedFloats[y++][0] = atof(number.c_str());
					x = 0;
				}
				else if (expression[i] == '+') {
					orderedFloats[y][1] = 5;
					orderedFloats[y++][0] = atof(number.c_str());
					x = 0;
				}
				else if (expression[i] == '-') {
					orderedFloats[y][1] = 6;
					orderedFloats[y++][0] = atof(number.c_str());
					x = 0;
				}
				else {
					number[x++] = expression[i];
				}
			}
			orderedFloats[y][0] = atof(number.c_str());

			while (ordered) {

			}
		}
		
		const int flLength = sizeof(orderedFloats) / sizeof(orderedFloats[0][0]);
		for (int i = 0; i < flLength-1; i++) {
			if (orderedFloats[i][1] == 5) {
				if(i == 0)
					solution = orderedFloats[i][0] + orderedFloats[i + 1][0];
				solution += orderedFloats[i + 1][0];
			}
		}
		

		*/
		
		solution = floatyExpr[0];

		for (int i = 0; i < 256; i++) {

			if (order[i] == 5) {
				solution += floatyExpr[i];
			}
			else if (order[i] == 6) {
				solution -= floatyExpr[i];
			}
			else {
				return solution;
			}
		}

		return solution;
}
