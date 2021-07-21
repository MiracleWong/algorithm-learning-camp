class Solution {
    public int splitArray(int[] nums, int m) {
        int left = 0; // 下界：
        int right = 0;  // 上届：
        for (int i=0; i< nums.length; i++) {
            left = Math.max(left, nums[i]);
            right += nums[i];
        }
        // 打印调试
        // System.out.printf("left: %d, right: %d", left, right);
        // System.out.println();
        while(left < right) {
            int mid = (left + right) / 2;
            // 第一个使得判定问题isValid得到true的位置
            if (isValid(nums, m, mid)) right = mid;
            else left = mid + 1;
            // 打印调试
            // System.out.printf("left: %d, right: %d", left, right); 
            // System.out.println();
        }
        return right;        
    }

    // 判定问题(true/false)： 将nums分成<=m个子数组，各组的 和<=T
    private boolean isValid(int[] nums, int m, int T) {
        int groupSum = 0;
        int groupCount = 1; // 默认，至少有1组
        for (int i=0; i< nums.length; i++) {
            if (groupSum + nums[i] <= T) {
                groupSum += nums[i];  // 没有超，即<=T, 加入当前组
            } else {
                groupCount++; // 超了，即>T, 新开一组
                groupSum = nums[i];
            }
        }
        return groupCount <= m;
    }
}


/*
origin: [7,2,5,10,8]  sum: 32

[7], [2,5,10,8]
7      25          max=25

[7,2], [5,10,8]
9      23          max=23


[7,2,5], [10,8]
14      18          max=18

[7,2,5,10], [8]
24      8          max=24


*/