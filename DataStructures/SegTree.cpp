class SegTree{

    private:

        vector<int> seg;
        vector<int> a;
        int N;
        int null_val = 0;

    public:

        SegTree(const vector<int> &v){
            N = (int) v.size();
            seg.resize(4*N,null_val);
            a.resize(N,null_val);
            a = v;
            build(1, 0, N-1);
        }

        int calc(int x,int y){
            return x+y;
        }

        void build(int node, int left, int right){
            if(left > right){
                return;
            }
            if(left == right){
                seg[node] = a[left];
                return;
            }
            int mid = left + (right - left) / 2;
            build(2 * node, left, mid);
            build(2 * node + 1, mid + 1, right);
            seg[node] = calc(seg[2*node], seg[2*node+1]);
        }

        void update(int node, int left, int right, int pos, int x){
            if(left == right){
                seg[node] = x;
                return;
            }
            int mid = left + (right - left) / 2;
            if(pos <= mid){
                update(2*node,left,mid,pos,x);
            }
            else{
                update(2*node+1,mid+1,right,pos,x);
            }
            seg[node] = calc(seg[2*node], seg[2*node+1]);
        }

        int query(int node,int l,int r,int ql,int qr){
            if(ql>r || qr<l){
                return null_val;
            }
            if(ql <= l && r <= qr){
                return seg[node];
            }
            int mid = l + (r-l)/2;
            return calc(query(2*node,l,mid,ql,qr),
                query(2*node+1,mid+1,r,ql,qr));
        }

};