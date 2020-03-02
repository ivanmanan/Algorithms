#ifndef GLOBALS_H
#define GLOBALS_H

#include "TreeNode.h"
#include "ListNode.h"

#include <iostream>
#include <limits.h>

#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

void printQueueInt(queue<int> q) {
	cout << "Contents of queue: ";
	while(!q.empty()) {
		cout << q.front();
		q.pop();
		if(!q.empty()) {
			cout << ", ";
		}
	}
	cout << endl;
}

void printQueueTreeNode(queue<TreeNode*> q) {
	cout << "Contents of queue: ";
	while(!q.empty()) {
		cout << (q.front())->val;
		q.pop();
		if(!q.empty()) {
			cout << ", ";
		}
	}
	cout << endl;
}

void printHashTable(unordered_map<char,int> ma) {
	for(auto it = ma.begin(); it != ma.end(); it++) {
		cout << it->first << ":" << it->second << endl;
	}
}

#endif
