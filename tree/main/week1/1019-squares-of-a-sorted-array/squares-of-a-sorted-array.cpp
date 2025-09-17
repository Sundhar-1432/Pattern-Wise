class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        vector<int>res(j+1,0);
        int k=j;
        while(i<=j){
            if(abs(nums[i])>abs(nums[j])){
                res[k]=nums[i]*nums[i];
                i++;
            }else{
                res[k]=nums[j]*nums[j];
                j--;
            }
            k--;
           
        }
        
        return res;
    }
};