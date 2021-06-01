struct CoordinateCompression {

	vector<int> a;

	CoordinateCompression(const vector<int> &v){
		a = v;
		sort(a.begin(),a.end());
		a.resize(unique(a.begin(),a.end()) - a.begin());
	}

	int getL(int x){
		return lower_bound(a.begin(),a.end(),x) - a.begin();
	}

	int getR(int x){
		return upper_bound(a.begin(),a.end(),x) - a.begin();
	}

	int size() const {
		return (int) a.size();
	}

};