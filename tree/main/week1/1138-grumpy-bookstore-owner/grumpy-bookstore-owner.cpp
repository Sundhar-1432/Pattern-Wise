class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int ans=0;
        for(int i=0;i<customers.size();i++){
            if(grumpy[i]==0)ans+=customers[i];
        }

        int left=0,right=0,max_val=0,sum=0;
        while(right<minutes){
            if(grumpy[right]==1)sum+=customers[right];
            right++;
        }
        max_val=sum;
        while(right<customers.size()){
            if(grumpy[left]==1)sum-=customers[left];
            if(grumpy[right]==1)sum+=customers[right];
            left++;
            right++;

            max_val=max(max_val,sum);
        }
        return ans+max_val;
    }
};