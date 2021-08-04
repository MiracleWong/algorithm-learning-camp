class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        // 前缀和
        vector<int>  sum(n + 1, 0);
        for (int i=1; i <=n; i++) sum[i] = sum[i-1] + nums[i];

        // 最大字段和
        int ans = -1000000;
        int temp = sum[0];
        for (int i=1; i <n ; i++) {
            temp = min(temp, sum[i-1]);
            ans = max(ans, sum[i] - temp);
            // cout << ans << endl;
        }

        // 最小字段和
        int ansMin = 1000000;
        temp = sum[0];
        for (int i=1; i <n; i++) {
            temp = max(temp, sum[i-1]);
            ansMin = min(ansMin, sum[i] - temp);
            // cout << ans << endl;
        }

        temp = sum[1];
        for (int j=2; j < n; j++) temp = max(temp, sum[j]);
        if (n > 1) ansMin = min(ansMin, sum[n] - temp);
        ans = max(ans, sum[n] - ansMin);
        return ans;
    }
};