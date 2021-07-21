class Solution {
    /* 解题思路：
    和 1482 制作m束花所需的天数，相似
    由于速度K是一个有范围的整数，因此可以使用「二分答案」找到这个有范围的整数。分析这个问题的具有的 单调性 是解题的关键。
    由题意可知：
    1. 单调性：总量不变的前提下，珂珂吃香蕉的速度越小，耗时越多。反之，速度越大，耗时越少；
    2. 珂珂一小时内将会选择一堆香蕉，所以其速度最大值（上界）为数量最多的那一堆香蕉的根数（Max），速度最小值为1（下界）
    3. 向上取整：因为珂珂一小时内将会选择一堆香蕉（不会再吃更多的香蕉），因此：该堆吃完耗时 = 该堆香蕉的数量 / 吃香蕉的速度K。不能整除的时候，需要向上取整。
    */
    public int minEatingSpeed(int[] piles, int h) {
        int maxVal = 1;
        for (int pile : piles) {
            maxVal = Math.max(maxVal, pile);
        }
        int left = 1, right = maxVal;  // 上下限
        while(left < right) {
            int mid = (left + right) / 2;
            // 第一个使得判定问题isValidWithSpeed得到true的位置
            if (isValidWithSpeed(piles, h, mid)) right = mid;
            else left = mid + 1;
            // 打印调试
            // System.out.printf("left: %d, right: %d", left, right); 
            // System.out.println();
        }
        return right; 
    }
    // 判定问题(true/false)： 吃香蕉的速度h（单位：根/小时）情况下，能否在h小时内吃掉所有香蕉piles
    private boolean isValidWithSpeed(int[] piles, int h, int k) {
        int time = 0; 
        for (int i=0; i< piles.length; i++) {
            if (piles[i] <= k) {
                time++;         // 小于等于k时，时间 +1
            } else {
                time += (piles[i] - 1)/k + 1; // 大于k时，耗时 = 该堆香蕉数量 / 吃香蕉的速度k +1，向上取整
            }
        }
        return time <= h;
    }
}