class SegmentTree {
public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        a = vector<Node>(4 * n);
        build(1, 0, n-1, nums);
    }

    void Change(int index, int val) {
        change(1, index, val);
    }

    int Query(int left, int right) {
        return query(1, left, right);
    }

private:
    struct Node {
        int l,r;
        int sum;
    };
    int n;
    vector<Node> a; // 长4N的数组，存线段树
    void build(int curr, int l, int r, vector<int>& nums) {
        a[curr].l = l;
        a[curr].r = r;
        // 递归的边界：叶子
        if (l == r) {
            a[curr].sum = nums[l];
            return;
        }
        int mid = (l + r) /2;
        // 分两半，递归
        build(curr * 2, l, mid, nums);
        build(curr * 2 + 1, mid + 1, r, nums);
        // 回溯时，自底向上统计信息
        a[curr].sum = a[curr * 2].sum + a[curr * 2 + 1].sum;
    }
    // 单点修改：先递归找到，自底向上统计信息
    void change(int curr, int index, int val){
        if (a[curr].l == a[curr].r) {
            a[curr].sum = val;
            return;
        }
        int mid = (a[curr].l + a[curr].r) /2;
        if (index <= mid) change(curr * 2, index, val);
        else change(curr * 2+1, index, val);
        // 回溯时，自底向上统计信息
        a[curr].sum = a[curr * 2].sum + a[curr * 2 + 1].sum;  
    }

    // 查询
    int query(int curr, int l, int r) {
        if (l <= a[curr].l && r<= a[curr].r) {
            return a[curr].sum;
        }
        int mid = (a[curr].l + a[curr].r) /2;
        int ans = 0;
        if (l <= mid) ans += query(curr * 2, l, r);
        if (r > mid) ans += query(curr * 2 + 1, l, r);
        return ans;
    }
};


class NumArray {

public:
    NumArray(vector<int>& nums): tree(SegmentTree(nums)){
    }
    
    void update(int index, int val) {
        tree.Change(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.Query(left, right);
    }

    SegmentTree tree;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */