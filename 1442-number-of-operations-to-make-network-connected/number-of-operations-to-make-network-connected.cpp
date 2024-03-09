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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dsu(n);
        int red =0;
        // find the no of redundant edges
        for(int i=0; i<connections.size(); i++){
            if(dsu.findUPar(connections[i][0])==dsu.findUPar(connections[i][1])){
                red++;
            }
            else{
                dsu.unionBySize(connections[i][0], connections[i][1]);
                
            }
            
        }
        cout<<red<<endl;
        int dis = 0;
        for(int i=0; i<dsu.parent.size()-1; i++){
            if(dsu.parent[i]==i){
                dis++;
            }
        }
        if(red>=dis-1){
            return dis-1;
        }
        return -1;
        
       
        

    }
};