struct TreeNode {
    int index;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

// Create BST
TreeNode* createTree(int root_index, int max_index) {
    TreeNode* root = new TreeNode;
    root->index = root_index;
    root->parent = NULL;
    int left = --root_index;
    int right = ++root_index;

    if (left > 0)
        root->left = createBST(left, max_index);
    else
        root->left = NULL;
    if (right <= max_index)
        root->right = createBST(right, max_index);
    else
        root->right = NULL;
    return root;
}

// K = criteria for number of longs
// M = number of long blossoming groups
int solution(vector<int> &A, int K, int M) {
    // write your code in C++14 (g++ 6.2.0)

    // There is only one long group at last day
    int longs = 1;
    int day = A.size();

    // Create BST with root the last element of the array
    TreeNode* root = createTree(A[A.size()-1], A.size());

    // Create for-loop iterating through the vector from end to beginning
    // Each element in vector sets that parent pointer to NULL

    // Create a vector of pointers
    // Iterate through all the pointers and count how many has NULL parents
    // Then count the number of children including the root pointer
    // If there are K nodes, then that is one long group
    // This determines the number of long groups
    // Compare number of long groups to M

    if (day) {
        return day;
    }
    else {
        return -1;
    }
}