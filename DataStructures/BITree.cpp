class BITree{

    private:

        vector<int> bit;
        int N;

    public:

        BITree(const vector<int> &v){
            N = (int) v.size();
            bit.assign(N+1,0);
            for(int i=1;i<=N;++i){
                bit[i]+=v[i-1];
                if(i+(i&(-i)) <= N){
                    bit[i+(i&(-i))]+=bit[i];
                }
            }
        }

        BITree(int n){
            N = n;
            bit.assign(N+1,0);
        }

        void update(int x,int v){
            for(;x<=N;x+=(x&(-x))){
                bit[x]+=v;
            }
        }

        int query(int x){
            int ret=0;
            for(;x>0;x-=(x&(-x))){
                ret+=bit[x];
            }
            return ret;
        }

};