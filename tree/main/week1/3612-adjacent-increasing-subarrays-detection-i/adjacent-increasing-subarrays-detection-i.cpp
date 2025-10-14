class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        if(n<2*k)return false;
        for(int i=0;i+2*k<=n;i++){
            bool firstSub=false,secSub=false;
            for(int j=i;j<i+k-1;j++){
                if(nums[j]>=nums[j+1]){
                    firstSub=true;
                    break;
                }

            }
            for(int j=i+k;j<i+2*k-1;j++){
                if(nums[j]>=nums[j+1]){
                    secSub=true;
                    break;
                }
           
            }
             if(!firstSub&&!secSub)return true;
        }
        return false;
    }
};