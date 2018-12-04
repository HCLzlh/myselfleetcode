static const auto io_sync_off = []() {
    std::ios::sync_with_stdio(false);//设置在每次输入/输出操作后标准C++流是否与标准C流同步
    std::cin.tie(nullptr);
    return nullptr;
}();
/*因为C++中的std :: cin和std :: cout为了兼容C，保证在代码中同时出现std :: cin和scanf或
 std :: cout和printf时输出不发生混乱，所以C++用一个流缓冲区来同步C的标准流。通过std :: ios_base :: sync_with_stdio函数可以解除这种同步，
 让std :: cin和std :: cout不再经过缓冲区，自然就节省了许多时间。*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
