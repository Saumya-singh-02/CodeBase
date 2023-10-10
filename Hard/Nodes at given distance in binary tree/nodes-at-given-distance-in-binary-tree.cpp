//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
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
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:
vector<int> result;

    // Helper function to find nodes at distance k down the tree from the given node
    void findKDistanceNodesDown(Node* root, int k)
    {
        if (!root || k < 0)
            return;

        if (k == 0)
        {
            result.push_back(root->data);
            return;
        }

        // Recur for left and right subtrees with decremented k
        findKDistanceNodesDown(root->left, k - 1);
        findKDistanceNodesDown(root->right, k - 1);
    }

    // Helper function to find nodes at distance k from the target node
    int findKDistanceNodes(Node* root, int target, int k)
    {
        if (!root)
            return -1;

        if (root->data == target)
        {
            // If the target is found, start finding nodes at distance k downwards
            findKDistanceNodesDown(root, k);
            return 0;
        }

        // Search in left subtree
        int leftDistance = findKDistanceNodes(root->left, target, k);
        if (leftDistance != -1)
        {
            if (leftDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodesDown(root->right, k - leftDistance - 2);
            return leftDistance + 1;
        }

        // Search in right subtree
        int rightDistance = findKDistanceNodes(root->right, target, k);
        if (rightDistance != -1)
        {
            if (rightDistance + 1 == k)
                result.push_back(root->data);
            else
                findKDistanceNodesDown(root->left, k - rightDistance - 2);
            return rightDistance + 1;
        }

        // If target is not found in the current subtree
        return -1;
    }

public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
       result.clear();  // Clear the result vector before each call
        findKDistanceNodes(root, target, k);  
        sort(result.begin(), result.end());  // Sort the result in ascending order
        return result;   // return the sorted vector of all nodes at k dist
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends