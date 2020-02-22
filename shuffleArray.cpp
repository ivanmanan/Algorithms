#include "globals.h"

vector<int> shuffleSongs(vector<int> songs) {
	int len = songs.size();
	cout << "Random numbers generated: ";
	for(int i = 0; i < len; i++) {

		/*
		  EXPLANATION
		  rand() --> gives a random integer value
		  random() % (len - i) --> Generates a random number between 0 and (len - i)
		  i + rand() % (len - i) --> assures no duplicate indices
		*/

		int r = i + (rand() % (len - i));
		cout << r << " ";
		swap(songs[i], songs[r]);
	}
	cout << endl;
	return songs;
}

int main() {
	vector<int> songs = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	// Initialize seed randomly
    srand(time(0));

	songs = shuffleSongs(songs);

	for(int i = 0; i < songs.size(); i++) {
		cout << songs[i] << " ";
	}
	cout << endl;
}