class DisjointSet{

	vector<int>rank, parent, size;

public:
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int>mpp;
        // which email is associated with which account index
        int n = accounts.size();
        DisjointSet dsu(n);
        for(int i=0; i<n; i++){
            for(int j =1; j<accounts[i].size(); j++){
                if(mpp.count(accounts[i][j])>0){
                    int par = mpp[accounts[i][j]];
                    int child = i;
                    dsu.unionBySize(par, child);
                }
                else{
                    mpp[accounts[i][j]]=i;
                }
            }
        }
        vector<string>mergedMail[n];
        for(auto it: mpp){
            string mail = it.first;
            int node = dsu.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size()==0){
                continue;
            
            }
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);

            }
            ans.push_back(temp);
        }
        return ans;
    }
};