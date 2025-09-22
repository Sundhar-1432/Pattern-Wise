class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_cnt=0,right=0,left=0,max_len=0;
        while(right<nums.size()){
            if(nums[right]==0)zero_cnt++;
            right++;
            while(zero_cnt>k){
                if(nums[left]==0)zero_cnt--;
                left++;
            }
            max_len=max(max_len,right-left);
        }
        //max_len=max(max_len,right-left+1);
        return max_len;
    }
};