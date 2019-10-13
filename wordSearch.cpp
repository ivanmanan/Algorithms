/*
  PROBLEM
  Boggle
  Given a dictionary - list of defined words
  Given an NxM grid of characters
  Find all possible defined words in the grid

  SOLUTION
  1. Create a Trie from the dictionary
  2. Find all characters from the grid which are child of the root of trie
  3. Create boolean visited matrix
  4. Call a SearchWord() function for every cell (i,j) that contains the first
     letters from the dictionary
  6. SearchWord() function:
  * If root->leaf is true, then word exists
  * If first time seeing element, mark as visited
  * Traverse all child of current node


  https://www.geeksforgeeks.org/boggle-set-2-using-trie/

*/

#include <iostream>
#include <vector>

using namespace std;

struct TrieNode {
	vector<TrieNode*> children;
	char letter;

    // leaf is true if the node represents the end of a word
    bool leaf;
};


TrieNode* createTrie(const vector<string>& words) {
	TrieNode* root = new TrieNode();

	TrieNode* curr = root;

	vector<TrieNode*> children;

	for(auto it = words.begin(); it != words.end(); it++) {
		string s = *it;
		for(int i = 0; i < s.length(); i++) {
			TrieNode* temp = new TrieNode();
			temp->letter = s[i];
			temp->leaf = false;

			if(i == s.length() - 1) {
				temp->leaf = true;
			}

			curr->children.push_back(temp);
			curr = temp;
		}
	}
	return root;
}

void findWord(int r, int c, vector<vector<char>>& board, vector<string>& foundWords) {

	// Check if word is safe - e.g. not negative (r,c) and not visited yet

	// Determine if board[r][c] is found in TrieNode

	// Mark visited[r][c] as true

	// Determine if any neighboring cells contains children node
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	vector<string> foundWords;
	TrieNode* root = createTrie(words);

	for(int r = 0; r < board.size(); r++) {
		for(int c = 0; c < board[0].size(); c++) {
			// TODO: CREATE a visited array
			findWord(r, c, board, root, foundWords);
		}
	}
	return foundWords;
}
