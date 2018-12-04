static const auto speedup = []() {std::ios::sync_with_stdio(false); std::cin.tie(NULL); return 0;}();
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int l;
        multiset<int>nums3(nums1.begin(),nums1.end());
        nums3.insert(nums2.begin(),nums2.end());
        auto iter = nums3.begin();
        if(nums3.size() % 2 == 1)
        {
            l=(nums3.size()-1)/2;
            while(l--)
                iter++;
            return *iter;
        }
        else
        {
            l=(nums3.size())/2;
            while(l--)
                iter++;
            return (*(iter--)+*iter)/2.0;
        }
    }
};
