class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans=0;
        int maxi=0;
        
        for(auto [num,cnt]:mp){
            maxi=max(cnt,maxi);
        }
        for(auto [num,cnt]:mp){
            if(maxi==cnt)ans+=cnt;
        }
        return ans;
    }
};