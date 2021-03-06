class segTree {
public:
        segTree *lchild, *rchild;
        int leftindex, rightindex;
        ll val = 0; 
        ll lazy = 0;

        ll combine() {
                if(leftindex == rightindex) return this->val;
                return (lchild->val + rchild->val); // change
        }

        void updateLazy() {
                val += (rightindex - leftindex + 1) * lazy;
                if(leftindex != rightindex) {
                        lchild->lazy += lazy;
                        rchild->lazy += lazy;
                }
                lazy = 0;
        }
        
        segTree(){}
        segTree(int leftindex, int rightindex, std::vector<ll> &v) {
                this->leftindex = leftindex;
                this->rightindex = rightindex;
                if(leftindex == rightindex) {
                        val = v[leftindex]; // change
                        return;
                }
                int mid = (leftindex + rightindex) >> 1;
                lchild = new segTree(leftindex, mid, v);
                rchild = new segTree(mid + 1, rightindex, v);
                this->val = combine();
        }
 
        void pUpdate(int pos, ll val) { 
                updateLazy();
                if(pos < leftindex or pos > rightindex) {
                        return;
                }
                if(leftindex == rightindex) {
                        this->val = val; // change 
                        return;
                }
                if(pos <= lchild->rightindex)
                        lchild->pUpdate(pos, val);
                else 
                        rchild->pUpdate(pos, val);
                this->val = combine();
        }
        
        ll pQuery(int pos) {
                updateLazy();
                if(pos < leftindex || pos > rightindex) {
                        return 0;
                }
                if(leftindex == rightindex) {
                        return val;
                }
                if(pos <= lchild->rightindex) {
                        return lchild->pQuery(pos);
                }
                else {
                        return rchild->pQuery(pos);
                }
        }

        ll rQuery(int l, int r) { 
                updateLazy();
                if(r < leftindex || l > rightindex) {
                        return 0; // change
                }
                if(l <= leftindex && r >= rightindex) {
                        return val;  // change
                }
                return lchild->rQuery(l, r) + rchild->rQuery(l, r);
        }

        void rUpdate(int l, int r, ll val) { //  add val to each element from l to r 
                updateLazy();
                if(r < leftindex || l > rightindex) {
                        return;
                }
                if(l <= leftindex && r >= rightindex) {
                        lazy += val;
                        updateLazy();
                        return;
                }
                lchild->rUpdate(l, r, val);
                rchild->rUpdate(l, r, val);
                this->val = combine();
        }

};