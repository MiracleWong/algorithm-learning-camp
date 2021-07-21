class Solution {
    /*
    解题思路：二分答案的本质是建立一个单调分段的0/1行数，定义域值为解空间（答案），值域为0或1，在这个函数上二分查找分界点
    举例：如果运载能力为weithts[i]的和，则1天可以运完。让运载能力逐步的减小即可。
    此时，转换为判定问题(true/false)： 将weights[i]分成<=days个子数组，各组的和<=C（运载能力Capacity）
    和第410题类似，最低运载能力 即 可以看为是，m个分组各自和的最大值最小。

    */
    public int shipWithinDays(int[] weights, int days) {
        int left = 0; // 下界
        int right = 0;  // 上界：weights[i]的和
        for (int i=0; i< weights.length; i++) {
            left = Math.max(left, weights[i]);
            right += weights[i];
            // 打印调试
            // System.out.printf("left: %d, right: %d", left, right);
            // System.out.println();            
        }
        while(left < right) {
            int mid = (left + right) / 2;
            // 第一个使得判定问题isValidWithCapacity得到true的位置
            if (isValidWithCapacity(weights, days, mid)) right = mid;
            else left = mid + 1;
            // 打印调试
            // System.out.printf("left: %d, right: %d", left, right); 
            // System.out.println();
        }
        return right; 
    }
    // 判定问题(true/false)： 将weights分成<=days个子数组，各组的和<=C（运载能力Capacity）
    private boolean isValidWithCapacity(int[] weights, int days, int C) {
        int weightSum = 0;
        int dayCount = 1; // 默认，至少有1天
        for (int i=0; i< weights.length; i++) {
            if (weightSum + weights[i] <= C) {
                weightSum += weights[i];  // 没有超，即<=C, 加入当前组
            } else {
                dayCount++; // 超了，即>C, 新开一组
                weightSum = weights[i];
            }
        }
        return dayCount <= days;
    }
}