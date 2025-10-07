class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n=rains.size();
        vector<int>res(n,-1);
        set<int>st;
        map<int,int>mp;

        for(int i=0;i<n;i++){
            if(rains[i]==0){
                st.insert(i);
                res[i]=1;
            }
            else{
                int lakh=rains[i];
                if(mp.find(lakh)!=mp.end()){
                    auto day=st.lower_bound(mp[lakh]);
                    if(day==st.end())return {};
               
                    res[*day]=rains[i];
                    st.erase(*day);
                }
                
                mp[rains[i]]=i;
            }
        }
        return res;
    }
};