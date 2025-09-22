class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        multiset<int> st;
        int r = 0, i = 0;
        
        // build first window
        while (r < k) {
            st.insert(nums[r]);
            r++;
        }
        res.push_back(*st.rbegin()); // max element
        
        while (r < nums.size()) {
            st.erase(st.find(nums[i])); // erase only one occurrence
            st.insert(nums[r]);
            res.push_back(*st.rbegin());
            r++;
            i++;
        }
        return res;
    }
};
