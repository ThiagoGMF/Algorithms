class SparseTable{

	private:

		vector<vector<int>> st;
		vector<int> lg;

	public:

		int f(int x,int y){
			return min(x,y);
		}

		SparseTable(const vector<int> &a,int k=26){
			int n = (int)a.size();
			st.assign(n + 1,vector<int>(k));
			lg.assign(n + 1, 0);
			for(int i = 0 ; i < n; ++i){
				st[i][0] = a[i];
			}
			lg[1] = 0;
			for(int i = 2; i <= n; ++i){
				lg[i] = lg[i/2] + 1;
			}
			for(int j = 1; j <= k; ++j){
				for(int i = 0; i + (1 << j) <= n; ++i){
					st[i][j] = f(st[i][j-1], st[i + (1 << (j-1))][j-1]);
				}
			}
		}

		int RMQ(int l,int r){
			int j = lg[r - l + 1];
			return f(st[l][j], st[r - (1 << j) + 1][j]);
		}
};