#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int index;
    int value;
    int parent_index;
    vector<Node*> children;
};

// Hash Table of nodes
// Key: Node Index
unordered_map<int, Node*> nodes;

// Create tree
// This is all pre-processing, so it is done once
void createTree(Node* node, vector<int> first, vector<int> second, vector<int> values) {
    for (int i = 0; i < first.size(); i++) {

        // Check if matched node index is not the same as parents
        if (first[i] == node->index && node->parent_index != second[i]) {

            // If node does not already exist, then insert new node
            auto got = nodes.find(second[i]);
            if (got == nodes.end()) {
                Node* new_node = new Node();
                new_node->index = second[i];
                new_node->value = values[second[i]-1];
                new_node->parent_index = node->index;
                node->children.push_back(new_node);
                nodes.insert({new_node->index, new_node});
                createTree(new_node, first, second, values);
            }
            else {
                Node* new_node = got->second;
                node->children.push_back(new_node);
            }
        }

        // Code block is similar to above code block
        if (second[i] == node->index  && node->parent_index != first[i]) {
            auto got = nodes.find(first[i]);
            if (got == nodes.end()) {
                Node* new_node = new Node();
                new_node->index = first[i];
                new_node->value = values[first[i]-1];
                new_node->parent_index = node->index;
                node->children.push_back(new_node);
                nodes.insert({new_node->index, new_node});
                createTree(new_node, first, second, values);
            }
            else {
                Node* new_node = got->second;
                node->children.push_back(new_node);
            }
        }
    }
}

// Return the root node
Node* Root(int query, vector<int> first, vector<int> second, vector<int> values) {
    Node* root = new Node();
    root->index = query;
    root->value = values[query-1];
    root->parent_index = 0;
    nodes.insert({query, root});
    createTree(root, first, second, values);
    return root;
}

bool checkPrimeNumber(int value) {
    for (int x = 2; x*x <= value; x++) {
        if (value % x == 0) {
            return false;
        }
    }
    return true;
}

void DFS(Node* node, int& primes) {
    //cout << "Node visited: " << node->index << "; Value: " << dffvalue << endl;
    if (node == NULL) {
        return;
    }
    if (checkPrimeNumber(node->value)) {
        primes++;
    }
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
        DFS(*it, primes);
    }
    return;
}

int DFS(int query) {
    int primes = 0;
    auto got = nodes.find(query);
    if (got == nodes.end()) {
        return 0;
    }
    else {
        DFS(got->second, primes);
        //cout << "===================================" << endl;
        return primes;
    }
}

// Complete the primeQuery function below.
vector<int> primeQuery(int n, vector<int> first, vector<int> second, vector<int> values, vector<int> queries) {
    vector<int> solution;
    Node* root = Root(1, first, second, values);

    /*
    // Iterate through the tree
    for (auto it = nodes.begin(); it != nodes.end(); it++) {
        cout << "Node: " << it->second->index << "; Value: " << it->second->value << "; Children: ";
        for (auto iterator = it->second->children.begin(); iterator != it->second->children.end(); iterator++) {
            cout << (*iterator)->index << ", ";
        }
        cout << endl;
    }
    */

    for (auto query = queries.begin(); query != queries.end(); query++) {
        solution.push_back(DFS(*query));
    }
    return solution;
}

