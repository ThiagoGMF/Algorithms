vector<int> build_suffix(const string &s) {
 
	// Total time = O(n*log²(n)) where 'n' is size of string 's'
 
	int n = (int) s.size();
 
	vector<int> p(n), c(n);
 
	{
		vector<pair<char,int>> a(n);
		
		for(int i=0;i<n;++i){
			a[i] = {s[i],i};
		}
		
		sort(a.begin(),a.end());
 
		for(int i=0;i<n;++i) p[i] = a[i].second;
 
		c[p[0]] = 0;
 
		for(int i=1;i<n;++i){
			if(a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
	}
 
	int k = 0;
 
	while((1<<k) < n) {
		vector<pair<pair<int,int>,int>> a(n);
		for(int i=0;i<n;++i){
			a[i] = {{c[i],c[(i+(1<<k))%n]}, i};
		}
		sort(a.begin(),a.end());
		for(int i=0;i<n;++i) p[i] = a[i].second;
		c[p[0]] = 0;
		for(int i=1;i<n;++i){
			if(a[i].first == a[i-1].first) c[p[i]] = c[p[i-1]];
			else c[p[i]] = c[p[i-1]]+1;
		}
		++k;
	}
 
 	p.erase(p.begin());
 
 	return p;
 
}

vector<int> build_lcp(const vector<int> &sa, const string &s){

	int n = sa.size();
	vector<int> inv(n);

	for(int i = 0; i < n; i++) {
		inv[sa[i]] = i;
	}

	vector<int> lcp(n, 0);

	for(int i = 0, k = 0; i < n; i++){

		int pi = inv[i];

		int j = sa[pi-1];

		while(i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;

		lcp[pi] = k;

		k = max(k - 1, 0);

	}

	lcp.erase(lcp.begin());

	return lcp;

}
