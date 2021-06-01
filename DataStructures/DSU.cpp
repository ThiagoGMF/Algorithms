struct DSU{
	vector<int> p,sz;
	int N;
	
	DSU (int n){
		N=n;
		p.resize(N+1);
		sz.resize(N+1);
		for(int i=0;i<=N;++i){
			p[i]=i;
			sz[i]=1;
		}
	}
	
	int find_set(int x){
		return p[x] = (p[x] == x ? x : find_set(p[x]));
	}
		
	void union_set(int a,int b){
		a=find_set(a);
		b=find_set(b);
		if(a==b)
			return;
		if(sz[a]>sz[b])swap(a,b);
		p[a]=b;
		sz[b]+=sz[a];
	}
};
