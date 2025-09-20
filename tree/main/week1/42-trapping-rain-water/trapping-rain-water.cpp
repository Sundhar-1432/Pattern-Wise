class Solution {
public:
    int trap(vector<int>& arr) {
        int lmx=0,tot=0,i=0,j=arr.size()-1,rmx=0;

        while(i<j){
            if(arr[i]<=arr[j]){
                if(lmx>arr[i]){
                    tot+=lmx-arr[i];
                }else lmx=arr[i];
                i++;
            }else{
                if(rmx>arr[j]){
                    tot+=rmx-arr[j];
                }else rmx=arr[j];
                j--;
            }
        }
        return tot;
    }
};