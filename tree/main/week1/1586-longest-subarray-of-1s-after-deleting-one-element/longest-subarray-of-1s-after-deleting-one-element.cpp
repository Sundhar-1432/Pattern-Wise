class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int r=0,l=0,max_len=0,cnt0=0;
        while(r<nums.size()){
            if(nums[r]==0)cnt0++;
            r++;
            if(cnt0>1){
                if(nums[l]==0)cnt0--;
                l++;
            }
            max_len=max(max_len,r-l-1);
        }
        return max_len;
    }
};