// Probability-RandomWalk-Scores.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
using namespace std;

int currentPosition; // Holds the user input for starting position
int trials; // Amount of trials we will do
int reachedTen = 0; // Accumulates the number of times we've reached 10
int reachedZero = 0; // Accumulates the number of times we've reached 0

void randomWalk(int position) {
	while (position > 0 && position < 10) {
		// i will be a random integer from 0 to 1 inclusive.
		int i = rand() % 2;
		// If it's 0, we decrement our position.
		if (i == 0) {
			//cout << "left" << endl;
			position--;
		}
		//Otherwise if it's 1, we increment our position.
		else if (i == 1) {
			//cout << "right" << endl;
			position++;
		}
	}
	if (position == 10) {
		reachedTen++; // once we've hit 10, we increment that counter
	}
	else {
		reachedZero++; // likewise for hitting 0
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	* Will loop and prompt until program is exited.
	* Prompts for current position (1 through 10).
	* Prompts for number of trials to run.
	* Prints the number of times we hit 10 and the number of times we hit 0,
	*	and the probability that we reach 10 before 0 is calculated by dividing the number of times we hit 10 by the number of trials the user inputs.
	*/

	while (1) {
		cout << "Where would you like to start? ";
		cin >> currentPosition;
		cout << "How many trials would you like to run? ";
		cin >> trials;

		for (int i = 0; i < trials; i++) {
			int start = currentPosition;
			randomWalk(start);
		}

		cout << "\nNumber of times you reached 10: " << reachedTen;
		cout << "\nNumber of times you reached 0 : " << reachedZero;
		float probability = (float)reachedTen / (float)trials;
		cout << "\n\nEmpirically determined probability of reaching 10 before reaching 0 : " << probability << "\n=========================\n\n";

		// reset the counters for the next loop
		reachedTen = 0;
		reachedZero = 0;
	}
	return 0;
}