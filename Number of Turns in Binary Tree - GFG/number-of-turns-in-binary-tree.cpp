//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    void dfs(Node* lca,int val,int prev,int curr_steps,int &ans) {
        if(not lca) return;
        if(lca->data==val) {
            ans+=curr_steps;
            return ;
        }

        if(prev==0) {
            dfs(lca->left,val,-1,curr_steps+1,ans);
            dfs(lca->right,val,1,curr_steps+1,ans);
        }else if(prev==1) {
            dfs(lca->left,val,-1,curr_steps+1,ans);
            dfs(lca->right,val,1,curr_steps,ans);
        }else {
            dfs(lca->left,val,-1,curr_steps,ans);
            dfs(lca->right,val,1,curr_steps+1,ans);
        }
    }
  
  
    Node* lowest_ancestor(struct Node* curr_node,int first,int second) {
        if(not curr_node or curr_node->data==first or curr_node->data==second) return curr_node;
        
        Node* left=lowest_ancestor(curr_node->left,first,second);
        Node* right=lowest_ancestor(curr_node->right,first,second);
        
        if(not left and not right) return left;
        else if(not left) return right;
        else if(not right) return left;
        else return curr_node;
    }
    
    
    int NumberOFTurns(struct Node* root, int first, int second) {
        Node* lca=lowest_ancestor(root,first,second);
        int ans=0;
        dfs(lca,first,0,0,ans);
        dfs(lca,second,0,0,ans);
        return ans-1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends