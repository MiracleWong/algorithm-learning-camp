class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // j < i
        // for i = 0 ~ n-1
        // search if (target - nums[i]) exists in nums[0..i-1]
        unordered_map<int, int> value_to_index;
        for (int i = 0; i < nums.size(); i++) {
            // 不等于尾部，就是找到了，存在
            if (value_to_index.find(target - nums[i]) != value_to_index.end()) {
                return {value_to_index[target - nums[i]], i};
            }
            // 边循环i，边插入，维护的是对于nums[0..i]的映射。
            // 本质上是在i之前查找，防止查找i本身
            value_to_index[nums[i]] = i;
        }
        return {};
    }
};