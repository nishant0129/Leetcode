//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  
  void inorder(Node* root,unordered_map<int,vector<int>>&mp)
  {
      if(!root)
      return;
      inorder(root->left,mp);
      if(root->left)
      {
         mp[root->data].push_back(root->left->data);
         mp[root->left->data].push_back(root->data);
         
      }
      if(root->right)
      {
          mp[root->data].push_back(root->right->data);
          mp[root->right->data].push_back(root->data);
      }
      inorder(root->right,mp);
  }
 void dfs(Node* curr_node,unordered_map<int,vector<int>>&mp) {
        if(not curr_node) return ;
        if(curr_node->left) {
            mp[curr_node->data].push_back(curr_node->left->data);
            mp[curr_node->left->data].push_back(curr_node->data);
            dfs(curr_node->left,mp);
        }
        if(curr_node->right) {
            mp[curr_node->data].push_back(curr_node->right->data);
            mp[curr_node->right->data].push_back(curr_node->data);
            dfs(curr_node->right,mp);
        }
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        unordered_map<int,vector<int>>mp;
        inorder(root,mp);
        // for(auto i:mp)
        // {
        //     vector<int>v=i.second;
        //     cout<<i.first<<" ->";
        //     for(auto I:v)
        //     cout<<I<<" ";
        //     cout<<endl;
        // }
        int level=0;
        queue<int>q;
         //queue<int>q;
        vector<bool>visited(10001,false);
        q.push(target);
        vector<int>ans;
        int lvl=0;
        visited[target]=true;
        while(not q.empty()) {
            int st=q.size();
            for(int i=0;i<st;i++) {
                int temp=q.front();
           
                q.pop();
                for(auto i:mp[temp]) {
                    if(not visited[i]) {
                        visited[i]=true;
                        q.push(i);
                    }
                }
            }
          lvl++;
        }
        return lvl-1;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends