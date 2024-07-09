class DisjointSet{
private:
	int n;
	vector<int> rank,parent,size;	

public:

	DisjointSet(int _n){
		n=_n;
		rank.resize(n+1,0);
		parent.resize(n+1);
		size.resize(n+1,1);

		for(int i=0;i<=n;i++)
			parent[i]=i;

	}

	int findParent(int u){
		if(u==parent[u])
			return u;
		return parent[u]=findParent(parent[u]);

	}

	void unionByRank(int u,int v){

		int pu = findParent(u);
		int pv = findParent(v);

		if(pu==pv)
			return;

		if(rank[u]>=rank[v])
			parent[pv]=pu;
		else
			parent[pu]=pv;

		if(rank[pu]==rank[pv])
			rank[pu]++;

	}

	void printRank(){
		cout<<"RANK\n";
		for(auto&it: rank)
			cout<<it<<" ";
		cout<<endl;
	}

	void printParent(){
		cout<<"Parent\n";
		for(auto&it: parent)
			cout<<it<<" ";
		cout<<endl;
	}

	bool areSameComponents(int u,int v){

		int pu = findParent(u);
		int pv = findParent(v);
		return pu==pv; 

	}

	void unionBySize(int u,int v){

		int pu = findParent(u);
		int pv = findParent(v);

		if(pu==pv)
			return;

		if(size[pu]>=size[pv]){
			parent[pv] =pu;
			size[pu]+=size[pv];
		}
		else{
			parent[pu]=parent[pv];
			size[pv]+=size[pu];
		}

	}

	void printSize(){
		cout<<"SIZE\n";
		for(auto&it: size)
			cout<<it<<" ";
		cout<<endl;
	}

	int findSize(int x){
		int px = findParent(x);
		return size[px];
	}

};