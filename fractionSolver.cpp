#include <iostream>
#include <vector>

using namespace std;

/*
  Fraction solver - given array of fractions and ratios, find the
  ratio of a fraction a/b

  Ex. a/b = 2, b/c = 3, c/d = 4 --- find a/d
      a/b * b/c * c/d = a/d = 2 * 3 * 4

  NOTE: This can be solvd using BFS

        a --> b --> c
		There are weights
		Finding a/c --> multiply weights together


*/

double fractionSolver(vector<pair<char,int>> fractions) {

	double ratio;

	bool endLoop = false;

	char numTarget = 'a';
	char denTarget = 'd';

	char currNum;
	char currDen;

	while(!endLoop) {

		for(auto it = fractions.begin(); it != fractions.end(); it++) {

			if(it->first == numTarget) {
				currNum =
			}
		}



	}



	return ratio;

}