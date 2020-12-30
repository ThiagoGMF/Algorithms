vector<int> pre_calc(const string &s) {

	int n = (int) s.size();
	vector<int> pi(n,0);
	
	for(int i=1, j=0; i<n; ++i) {
		while(j > 0 && s[j] != s[i]) j = pi[j-1];
		if(s[i] == s[j]) ++j;
		pi[i] = j;
	}
	
	return pi;

}

vector<int> matching(string &text, string &pattern) {
	
	vector<int> pi = pre_calc(pattern+'$'), match;
	int n = (int) text.size();
	
	for(int i=0, j=0; i<n; ++i){
		while(j > 0 && pattern[j] != text[i]) j = pi[j-1];
		if(pattern[j] == text[i]) ++j;
		if(j == pattern.size()) match.push_back(j-i+1);
	}
	
	return match;

}