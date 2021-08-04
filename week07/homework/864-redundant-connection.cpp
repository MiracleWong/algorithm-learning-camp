class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 答案数组
        vector<int> ans(2,0);
        // 建立并查集
        for (int i = 0; i <= edges.size(); i++)
            fa.push_back(i);
        
        for(auto i:edges){
            // cout << i[0] << i[1] << endl;
            if(find(i[0])!=find(i[1]))  
                unionSet(i[0], i[1]);
            else
                ans=i;  //更新符合条件的边
        }
        return ans;    
    }
    void unionSet(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x != y) fa[x] = y;
    }
    int find(int x) {
        if (x == fa[x]) return x;
        if (x != fa[x])
            fa[x] = find(fa[x]);
        return fa[x];
    }

    vector<int> fa;    
};