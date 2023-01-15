class Solution {
	public:
		int find(vector<int>& parent,int a) 
		{
			if(a==parent[a])
				return a;
			return parent[a]=find(parent,parent[a]);

		}
		int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
			int n = vals.size();
			vector<int> parent(n);
			map<int,int> max_element;
			map<int,int> count;

			for(int i=0;i<n;i++)
            {
				parent[i]=i;
				max_element[i]=vals[i];
				count[i]=1;
			}

			 sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	     return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		    });

			int ans=n;

			for(auto& edge: edges)
			{
				int a=find(parent,edge[0]);
				int b=find(parent,edge[1]);
				if(max_element[a]!=max_element[b])
				{
					if(max_element[a]>max_element[b])
						parent[b]=a;
					else
						parent[a]=b;
				
				}
				else
				{
					parent[a]=b;
					ans+=count[a]*count[b];
					count[b]+=count[a];
				}
			}
			return ans;
		}
	};