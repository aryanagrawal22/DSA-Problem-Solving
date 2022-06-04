//O(n) solution^ : https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/


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
    int maxSum = 0;

    int treeTraverse(Node *node){
        
        if (node==NULL){
            return 0;
        }

        int sumSaveLoc=0;
        int sum = subTreeSum(node, &sumSaveLoc);

        if (sum>maxSum){
            maxSum = sum;
        }

        treeTraverse(node->left);
        treeTraverse(node->right);

        return maxSum;
    }

    int subTreeSum(Node* node, int* sumSaveLoc)
    {
        if (node == NULL)
            return 0;
        else {
            /* compute the height of each subtree */
            *sumSaveLoc += node->data;
            int lheight = subTreeSum(node->left, sumSaveLoc);
            int rheight = subTreeSum(node->right, sumSaveLoc);
 
            return *sumSaveLoc;
        }
    }
};


// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   Node* root = newNode(3);
    root->left = newNode(-2);
    root->right = newNode(10);
    Solution ob;
    cout << ob.treeTraverse(root) << endl;
    return 0;
}



// // C++ program to find largest subtree
// // sum in a given binary tree.
// #include <bits/stdc++.h>
// using namespace std;
 
// // Structure of a tree node.
// struct Node {
//     int key;
//     Node *left, *right;
// };
 
// // Function to create new tree node.
// Node* newNode(int key)
// {
//     Node* temp = new Node;
//     temp->key = key;
//     temp->left = temp->right = NULL;
//     return temp;
// }
 
// // Helper function to find largest
// // subtree sum recursively.
// int findLargestSubtreeSumUtil(Node* root, int& ans)
// {
//     // If current node is null then
//     // return 0 to parent node.
//     if (root == NULL)    
//         return 0;
     
//     // Subtree sum rooted at current node.
//     int currSum = root->key +
//       findLargestSubtreeSumUtil(root->left, ans)
//       + findLargestSubtreeSumUtil(root->right, ans);
 
//     // Update answer if current subtree
//     // sum is greater than answer so far.
//     ans = max(ans, currSum);
 
//     // Return current subtree sum to
//     // its parent node.
//     return currSum;
// }
 
// // Function to find largest subtree sum.
// int findLargestSubtreeSum(Node* root)
// {
//     // If tree does not exist,
//     // then answer is 0.
//     if (root == NULL)    
//         return 0;
     
//     // Variable to store maximum subtree sum.
//     int ans = INT_MIN;
 
//     // Call to recursive function to
//     // find maximum subtree sum.
//     findLargestSubtreeSumUtil(root, ans);
 
//     return ans;
// }
 
// // Driver function
// int main()
// {
//     /*
//                1
//              /   \
//             /     \
//           -2       3
//           / \     /  \
//          /   \   /    \
//         4     5 -6     2
//     */
 
//     Node* root = newNode(1);
//     root->left = newNode(-2);
//     root->right = newNode(3);
//     root->left->left = newNode(4);
//     root->left->right = newNode(5);
//     root->right->left = newNode(-6);
//     root->right->right = newNode(2);
 
//     cout << findLargestSubtreeSum(root);
//     return 0;
// }