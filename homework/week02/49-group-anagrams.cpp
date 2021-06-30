class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // HashMap 可用于分组
        //
        unordered_map<string, vector<string>> group;
        for (string& str : strs) {
            string copy = str;
            // 字符串里面的字符排序
            sort(copy.begin(), copy.end());
            // 分组
            group[copy].push_back(str);
//            cout << "Added " << str << " into group " << copy << endl;
        }
        // 把 HashMap 变成数组是一个基本的操作
        vector<vector<string>> ans;
        for (auto pr: group) {
            ans.push_back(pr.second);
        }
        return ans;
    }
};


// 排序后，再分组

// ["eat", "tea", "tan", "ate", "nat", "bat"]
// ["aet", "aet", "ant", "aet", "ant", "abt"]