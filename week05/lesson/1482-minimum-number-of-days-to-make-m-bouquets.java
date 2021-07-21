class Solution {
    public int minDays(int[] bloomDay, int m, int k) {
        int Max = 1000000001;
        int left = 0, right = 1000000001;  // 上下限
        while(left < right) {
            int mid = (left + right) / 2;
            // 第一个使得判定问题isValidOnDay得到true的位置
            if (isValidOnDay(bloomDay, m, k, mid)) right = mid;
            else left = mid + 1;
            // 打印调试
            // System.out.printf("left: %d, right: %d", left, right); 
            // System.out.println();
        }
        if (right == Max) return -1;
        return right; 
    }
    // 判定问题(true/false)： 在第T天的开花情况下，能否制作m束花，每束花是连续的k朵
    private boolean isValidOnDay(int[] bloomDay, int m, int k, int T) {
        int consecutive  = 0;   // 已经连续开了N朵
        int bouquet = 0;    // 花束的数量，默认为0
        for (int i=0; i< bloomDay.length; i++) {
            if (bloomDay[i] <= T) {     // 已经开了
                consecutive++;
                if (consecutive == k) {
                    bouquet++;   // k多花成为1束，bouquet加1
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquet >= m;
    }
}

// 花开的越多，T天如果可以（能制作），则T+1、T+2... 天都可行（能制作），这是一个单调分段的，找T天数即可
// 判定问题(true/false)： 在第T天的开花情况下，能否制作m束花，每束花是连续的k朵