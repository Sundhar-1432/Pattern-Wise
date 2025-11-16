class Solution {
public:
    int numSub(string s) {
        long long count=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                count++;
            }else{
                cout<<count<<endl;
                ans+=(count*(count+1)/2)%1000000007;
                count=0;
            }
        }
        ans+=(count*(count+1)/2);
        return ans;
    }
};