class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
       int ans=INT_MIN;
        int curr=1,prev=0;

        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1])curr++;
            else{
                
                prev=curr;
                curr=1;
            }
            if(curr%2==0)ans=max(ans,curr/2);
            ans=max(ans,min(curr,prev));
            cout<<curr<<" ";
        }
        
        if(curr%2==0)ans=max(ans,curr/2);
        ans=max(ans,min(curr,prev));
           
    
       return ans;
    }
};