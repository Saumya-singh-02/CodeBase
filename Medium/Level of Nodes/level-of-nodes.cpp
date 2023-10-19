//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int, int>>q;

        q. push({0, 0});

        vector<pair<int, int>>ans;

        ans. push_back(q.front());

        vector<int>vis(V, 0);

        

           vis[0]=1;

        while(q.size())

          {

            pair<int, int>p=q.front();

 

                 q. pop();

                for(auto it:adj[p.first])

                  {

                      if(vis[it]==0)

                        {

                            vis[it]=1;

             ans. push_back({it,p.second+1});

                     q. push({it,p.second+1});

                        }

                  }

          }

          for(auto it:ans)

            {

          if(it.first==X)return it.second;

            }

            return -1;// code here
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends