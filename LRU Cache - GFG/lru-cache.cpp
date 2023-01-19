//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:
       struct Node 
       {
           int key;
           int value;
           Node* prev;
           Node* next;
           Node(int key1, int value1)
           {
               key = key1;
               value = value1;
           }
       };
       
   Node* head = new Node(0,0);
   Node* tail = new Node(0,0);  
   unordered_map<int,Node*> mp;
   int capacity;
   
    public:
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        // code here
       capacity = cap;
       head->next = tail;
       tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        // your code here
        if(mp.find(key)!=mp.end())
        {
            Node* existingnode=mp[key];
            int val=existingnode->value;
            dNode(existingnode);
            add(key,val);
            mp.erase(key);
            mp[key]=head->next;
            return val;
        }
        return -1;
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        // your code here   
        if(mp.find(key) != mp.end())
       {
           Node* existingNode = mp[key];
           mp.erase(key);
           dNode(existingNode);
       }
       
       if(mp.size() == capacity)
       {
           mp.erase(tail->prev->key);
           dNode(tail->prev);
       }
       
       add(key,value);
       mp[key]=head->next;
    }
    
   void add(int key,int value)
   {
       Node* createNode = new Node(key,value);
       createNode->next = head->next;
       head->next->prev = createNode;
       head->next = createNode;
       createNode->prev=head;
   }
   
   void dNode(Node* deletedNode)
   {
       deletedNode->prev->next = deletedNode->next;
       deletedNode->next->prev = deletedNode->prev;
       delete deletedNode;
   }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends