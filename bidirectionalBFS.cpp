#include "globals.h"

using namespace std;

// Algorithm done in O(b^(d/2))
// Return true if intersection exists, return false otherwise
bool bidirectionalBFS(TreeNode* s, TreeNode* t) {

    // Number of vertices
    const int V = 30;

    vector<int> connection;

    bool s_visited = new bool[V];
    bool t_visited = new bool[V];

    for (int i = 0; i < V; i++) {
        s_visited[i] = false;
        t_visited[i] = false;
    }

    queue<TreeNode*> q_s;
    queue<TreeNode*> q_t;

    q_s.push(s);
    q_t.push(t);

    s_visited[s->val] = true;
    t_visited[t->val] = true;

    int intersectionFound = -1;

    while (!q_s.empty() && !q_t.empty()) {
        TreeNode* node1 = q_s.front();
        TreeNode* node2 = q_t.front();

        BFS(q_s, s_visited);
        BFS(q_t, t_visited);


        intersectionFound = isIntersecting(s_visted, t_visited);
        if (intersectionFound != -1) {
            cout << "Intersection found at " << intersectionFound;
            return true;
        }
    }

    return false;
}

int main() {

}