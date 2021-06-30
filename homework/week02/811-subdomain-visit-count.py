class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        # cpdomains 为空，返回空
        if not cpdomains:
            return []
        ans = {}
        for case in cpdomains:
            # 获取一组数据：900 google.mail.com
            # time: 900
            # domains: google.mail.com
            time, domains = case.split()
            length = len(domains.split('.')) # 3
            for i in range(length):
                # 三次循环
                # discuss.leetcode.com
                # leetcode.com
                # com
                dm = domains.split('.', i)[-1]
                # print(dm)
                if dm not in ans:
                    ans[dm] = int(time)
                else:
                    ans[dm] += int(time)
        return [str(v)+' '+ k for k, v in ans.items()]