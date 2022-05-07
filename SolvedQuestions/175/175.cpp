// https://www.geeksforgeeks.org/how-to-determine-if-a-binary-tree-is-balanced/


#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* A binary tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution{
    public:
    int maxHD = 0;
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        if(abs(maxHDiffCalc(root))>1){
            return false;
        }else{
            return true;
        }
    }

    int maxHDiffCalc(Node *node){
        
        if (node==NULL){
            return 0;
        }

        int lheight = height(node->left);
        int rheight = height(node->right);

        if (abs(lheight-rheight)>maxHD){
            maxHD = lheight-rheight;
        }

        maxHDiffCalc(node->left);
        maxHDiffCalc(node->right);

        return maxHD;
    }

    int height(Node* node)
    {
        if (node == NULL)
            return 0;
        else {
            /* compute the height of each subtree */
            int lheight = height(node->left);
            int rheight = height(node->right);
 
            /* use the larger one */
            if (lheight > rheight) {
                return (lheight + 1);
            }
            else {
                return (rheight + 1);
            }
        }
    }
};


// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   Node* root = newNode(7);
    root->left = newNode(9);
    root->right = newNode(7);
    root->left->left = newNode(8);
    root->left->right = newNode(8);
    root->right->left = newNode(6);
    root->left->left->left = newNode(10);
    root->left->left->right = newNode(9);
    
    Solution ob;
    cout << ob.isBalanced(root) << endl;
    return 0;
}
  // } Driver Code Ends




// /* C++ program to check if a tree
// is height-balanced or not */
// #include <bits/stdc++.h>
// using namespace std;
// #define bool int
 
// /* A binary tree node has data,
// pointer to left child and
// a pointer to right child */
// class node {
// public:
//     int data;
//     node* left;
//     node* right;
// };
 
// /* The function returns true if root is
// balanced else false The second parameter
// is to store the height of tree. Initially,
// we need to pass a pointer to a location with
// value as 0. We can also write a wrapper
// over this function */
// bool isBalanced(node* root, int* height)
// {
 
//     /* lh --> Height of left subtree
//     rh --> Height of right subtree */
//     int lh = 0, rh = 0;
 
//     /* l will be true if left subtree is balanced
//     and r will be true if right subtree is balanced */
//     int l = 0, r = 0;
 
//     if (root == NULL) {
//         *height = 0;
//         return 1;
//     }
 
//     /* Get the heights of left and right subtrees in lh and rh
//     And store the returned values in l and r */
//     l = isBalanced(root->left, &lh);
//     r = isBalanced(root->right, &rh);
 
//     /* Height of current node is max of heights of left and
//     right subtrees plus 1*/
//     *height = (lh > rh ? lh : rh) + 1;
 
//     /* If difference between heights of left and right
//     subtrees is more than 2 then this node is not balanced
//     so return 0 */
//     if (abs(lh - rh) >= 2)
//         return 0;
 
//     /* If this node is balanced and left and right subtrees
//     are balanced then return true */
//     else
//         return l && r;
// }
 
// /* UTILITY FUNCTIONS TO TEST isBalanced() FUNCTION */
 
// /* Helper function that allocates a new node with the
// given data and NULL left and right pointers. */
// node* newNode(int data)
// {
//     node* Node = new node();
//     Node->data = data;
//     Node->left = NULL;
//     Node->right = NULL;
 
//     return (Node);
// }
 
// // Driver code
// int main()
// {
//     int height = 0;
 
//     /* Constructed binary tree is
//             1
//             / \
//             2 3
//             / \ /
//             4 5 6
//             /
//             7
//     */
//     node* root = newNode(1);
//     root->left = newNode(2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);
//     root->right->left = newNode(6);
//     root->left->left->left = newNode(7);
 
//     if (isBalanced(root, &height))
//         cout << "Tree is balanced";
//     else
//         cout << "Tree is not balanced";
 
//     return 0;
// }