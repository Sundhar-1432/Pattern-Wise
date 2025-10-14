class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k)return 0;

        int prev=0,curr=1;

        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr++;
                cout<<curr<<" ";
            }

            else{
                if(curr>=2*k||min(prev,curr)>=k)return true;

                prev=curr;
                curr=1;
            }
        }
        if(curr>=2*k||min(prev,curr)>=k)return true;

        return 0;
    }
};