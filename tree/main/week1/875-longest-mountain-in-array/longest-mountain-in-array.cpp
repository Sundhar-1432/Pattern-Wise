class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        vector<int>lf(n,0);
        vector<int>rm(n,0);
        int cnt=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                cnt++;
                lf[i]=cnt;
            }else cnt=0;
        }
        cnt=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                cnt++;
                rm[i]=cnt;
            }else cnt=0;
        }
        int tot=0;

        for(int i=0;i<n;i++){
            if(lf[i]&&rm[i])tot=max(tot,rm[i]+lf[i]+1);
        }
        return tot;
    }
};