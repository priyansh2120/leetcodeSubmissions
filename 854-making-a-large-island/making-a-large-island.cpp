class DisjointSet{

	

public:
    vector<int>rank, parent, size;
	DisjointSet(int n){
		rank.resize(n+1, 0);
		parent.resize(n+1);
		size.resize(n+1, 1);
		for(int i=0; i<=n; i++){
			parent[i]=i;
		}
	}

	int findUPar(int node){
		 if(parent[node]==node){
		 	return node;
		 }

		 return parent[node]= findUPar(parent[node]);
	}


	void unionByRank(int u, int v){
		int ulpU = findUPar(u);
		int ulpV = findUPar(v);

		if(ulpV==ulpU){
			return;
		}
		if(rank[ulpV]>rank[ulpU]){
			parent[ulpU]= ulpV;
		}
		else if(rank[ulpU]>rank[ulpV]){
			parent[ulpV]= ulpU;
		}
		else if(rank[ulpU]==rank[ulpV]){
			parent[ulpV]= ulpU;
			rank[ulpU]++;
		}
	}

	void unionBySize(int u, int v){
		int ulpU = findUPar(u);
		int ulpV = findUPar(v);

		if(ulpV==ulpU){
			return;
		}
		if(size[ulpV]>size[ulpU]){
			parent[ulpU]= ulpV;
			size[ulpV]+=size[ulpU];
		}
		else{
			parent[ulpV]= ulpU;
			size[ulpU]+=size[ulpV];
		}
	}
};


class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
         int n = grid.size();
        DisjointSet ds(n*n);
        int rm[] = {0,0,-1,1};
        int cm[] = {1,-1,0,0};
        for(int i=0; i<n; i++ ){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    for(int k=0; k<4; k++){
                        int newr = i+rm[k];
                        int newc = j+cm[k];
                        
                        if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1){
                            ds.unionBySize(i*n+j, newr*n+newc);
                        }
                    }
                }
                
            }
        }
        int ans =INT_MIN;
        for(int i=0; i<n; i++ ){
            for(int j=0; j<n; j++){
                set<int>components;
                if(grid[i][j]==0){
                    for(int k=0; k<4; k++){
                        int newr = i+rm[k];
                        int newc = j+cm[k];
                        
                        if(newr>=0 and newr<n and newc>=0 and newc<n and grid[newr][newc]==1){
                            int par = ds.findUPar(newr*n+newc);
                            components.insert(par);
                        }
                    }
                }
                int lans= 0;
                for(auto it: components){
                    lans+= ds.size[it];
                }
                lans+=1;
                ans= max(ans,lans);
            }
        }
        
        for(int i=0; i<n*n; i++){
            ans = max(ans, ds.size[ds.findUPar(i)]);
        }
        return ans;
    }
};