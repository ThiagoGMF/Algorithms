struct SegTreeLazy{

    vector<int> seg;
    vector<int> lazy;
    vector<int> a;
    int N;
    int null_val = 0;

    SegTreeLazy(const vector<int> &v){
        N = (int) v.size();
        seg.resize(4*N,null_val);
        lazy.resize(4*N,null_val);
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

    void push(int node,int l,int r){
        if(lazy[node]){
            seg[node] = calc(seg[node],lazy[node] * (r-l+1));
            if(l != r){
                lazy[2*node] = calc(lazy[2*node], lazy[node]);
                lazy[2*node+1] = calc(lazy[2*node+1], lazy[node]);
            }
            lazy[node] = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr, int x){
        push(node, l, r);
        if(ql>r || qr<l){
            return;
        }
        if(ql <= l && r <= qr){
            lazy[node] = calc(lazy[node],x);
            push(node,l,r);
        }
        else{
            int mid = l + (r-l)/2;
            update(2*node,l,mid,ql,qr,x);
            update(2*node+1,mid+1,r,ql,qr,x);
            seg[node] = calc(seg[2*node],seg[2*node+1]);
        }
    }

    int query(int node,int l,int r,int ql,int qr){
        push(node,l,r);
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