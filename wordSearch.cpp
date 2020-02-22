#include "globals.h"

// Word Search I
// Find if a given word exists in the board

// This is essentially DFS with backtracking
void dfs(int r, int c, vector<vector<char>>& board, string& word, int wordIndex, bool& res) {


	if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != word[wordIndex]) {
		return;
	}

	// NOTE: This is an alternative to having a visited boolean grid
	char curr = board[r][c];
	board[r][c] = '*';

	if(wordIndex == word.length()-1) {
		res = true;
		return;
	}
	else {
		vector<int> rowNeighbors = {1, -1, 0,  0};
		vector<int> colNeighbors = {0,  0, 1, -1};

		for(int i = 0; i < rowNeighbors.size(); i++) {
			dfs(r+rowNeighbors[i], c+colNeighbors[i], board, word, wordIndex+1, res);
		}
	}
	board[r][c] = curr;
}

bool exist(vector<vector<char>>& board, string word) {
	bool res = false;
	const int maxRow = board.size();
	const int maxCol = board[0].size();

	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {
			dfs(r, c, board, word, 0, res);
			if(res) {
				return res;
			}
		}
	}
	return res;
}

// Word Search II
// Given a dictionary, find all existing words in the board

struct TrieNode {
	TrieNode(char letter, bool endOfWord) {
		val = letter;
		leaf = endOfWord;
	}
	char val;
	bool leaf; // Indicates end of word or not
	vector<TrieNode*> children;
};

TrieNode* createTrie(const vector<string>& words) {
	vector<string> res;

	// Asterik indicates root node
	TrieNode* root = new TrieNode('*', false);

	for(int w = 0; w < words.size(); w++) {
		string s = words[w];
		TrieNode* curr = root;
		for(int i = 0; i < s.length(); i++) {
			bool childExists = false;

			for(int c = 0; c < curr->children.size(); c++) {
				// Child node exists
				if(curr->children[c]->val == s[i]) {
					childExists = true;
					curr = curr->children[c];
				}
			}

			if(!childExists) {
				bool endOfWord = (i == s.length()-1);
				curr->children.push_back(new TrieNode(s[i], endOfWord));
				curr = curr->children.back();
			}
		}
	}
	return root;
}

void dfs(int r, int c, vector<vector<char>>& board, TrieNode* root, unordered_set<string>& res, string s) {
	if(r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
		return;
	}

	vector<int> rowNeighbors = {0,  0, 1, -1};
	vector<int> colNeighbors = {-1, 1, 0,  0};

	// Check if initial position is equivalent to a first letter of any of the words
	for(auto it = root->children.begin(); it != root->children.end(); it++) {
		if((*it)->val == board[r][c]) {
			s += (*it)->val;
			// Check if end of word
			if((*it)->leaf) {
				res.insert(s);
			}

			// Used to track what part of the board has been visited
			char temp = board[r][c];
			board[r][c] = '^';

			// Continue dfs
			for(int i = 0; i < rowNeighbors.size(); i++) {
				dfs(r + rowNeighbors[i], c + colNeighbors[i], board, *it, res, s);
			}
			board[r][c] = temp;
		}
	}
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

	// Create the root node
	TrieNode* root = createTrie(words);

	// Used to eliminate duplicates
	unordered_set<string> res;

	// Iterate the board
	int maxRow = board.size();
	int maxCol = board[0].size();
	for(int r = 0; r < maxRow; r++) {
		for(int c = 0; c < maxCol; c++) {
			dfs(r, c, board, root, res, "");
		}
	}

	return vector<string>(res.begin(), res.end());
}