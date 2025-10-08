class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=potions.size();
        sort(potions.begin(),potions.end());
        map<int,int>mp;

        for(double num:spells){
            long find_num=ceil((double)success/num);
            int i=0,j=n-1,ans=-1;
            while(i<=j){
                int mid=i+(j-i)/2;
                if(potions[mid]>=find_num){ 
                    ans=mid;
                    j=mid-1;
                }else i=mid+1;
            }
            if(ans!=-1)mp[num]=n-ans;

        }
        vector<int>res;
        for(int num:spells){
            if(mp.find(num)!=mp.end()){
                res.push_back(mp[num]);
            }else res.push_back(0);
        }
        return res;
    }
};