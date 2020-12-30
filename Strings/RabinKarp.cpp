int rabin_karp(const string &pattern, const string &text){

	int occurences = 0;

	int P = pattern.size();
	int T = text.size();

	int p = 31; // all lower cases english letter, for lower and upper use p = 53
	int mod = 1e9+7;

	vector<long long> p_pow(max(P,T));

	p_pow[0] = 1;

	for(int i=1;i<max(P,T);++i){
		p_pow[i] = (p * p_pow[i-1]) % mod;
	}

	vector<long long> hash_text(T + 1, 0);

	for(int i=0;i<T;++i){
		hash_text[i+1] = (hash_text[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;
	}

	long long hash_pattern = 0;

	for(int i=0;i<P;++i){
		hash_pattern = (hash_pattern + (pattern[i] - 'a' + 1) * p_pow[i]) % mod;
	}

	for(int i=0;i+P-1<T;++i){
		long long cur_hash = (hash_text[i+P] - hash_text[i] + mod) % mod;
		if(cur_hash == hash_pattern * p_pow[i] % mod){
			occurences++;
		}
	}

	return occurences;

}