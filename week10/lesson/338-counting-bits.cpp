class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for (int i =0; i <=n; i++) {
            ans.push_back(hammingWeight(i));
        }
        return ans;
    }
private:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            count++;
            n -= n & -n; 
        }
        return count;
    }
};