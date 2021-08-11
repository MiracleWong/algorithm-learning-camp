class Solution {
public:
    string toLowerCase(string str) {
        int n = str.size();
        for (int i = 0; i < n; ++i)
        {
            if (str[i] >= 65 && str[i] <= 90)
            {
                str[i] += 32;
            }
        }
        return str;
    }
};