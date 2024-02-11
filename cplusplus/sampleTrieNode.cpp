#include "globals.h"

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

void printTrieNode(TrieNode* root) {

	cout << root->val << "--> {";

	for(int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->val;
		if(i != root->children.size()-1) {
			cout << ", ";
		}
	}
	cout <<"} "<< (root->leaf ? "--> Is Word" : "") << endl;
	for(auto it = root->children.begin(); it != root->children.end(); it++) {
		printTrieNode(*it);
	}
}


void deleteTrieNode(TrieNode* root) {
	for(auto it = root->children.begin(); it != root->children.end(); it++) {
		deleteTrieNode(*it);
	}
	delete root;
}

int main() {
	vector<string> words = {
		"aba","baa","bab","aaab","aaa","aaaa","aaba"
	};

	TrieNode* root = createTrie(words);

	printTrieNode(root);
	deleteTrieNode(root);
}