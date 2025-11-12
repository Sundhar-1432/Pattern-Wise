class Solution {
public:
    int gcd(int a,int b){

        while(a>0&&b>0){
            if(a>b)a=a%b;
            else b=b%a;
        }
        return a==0?b:a;
    }
    int minOperations(vector<int>& nums) {
        int cnt=0,n=nums.size();

        for(int it:nums){
            if(it==1)cnt++;
        }
        if(cnt>0)return n-cnt;
        int minlen=INT_MAX;

        for(int i=0;i<nums.size();i++){
            int g=nums[i];
            for(int j=i+1;j<n;j++){
                g=gcd(g,nums[j]);
                if(g==1){
                    minlen=min(minlen,j-i+1);
                    break;
                }
            }
        }
        if(minlen==INT_MAX)return -1;

        return (minlen-1)+(n-1);
    }
};