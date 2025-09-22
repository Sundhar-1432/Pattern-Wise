class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum=0,cnt=0,i=0;
        int r=0;
        while(r<k){
            sum+=arr[r];
            r++;
        }
        if((sum/k)>=threshold)cnt++;
        while(r<arr.size()){
            sum-=arr[i];
            sum+=arr[r];
            i++;
            r++;
            if((sum/k)>=threshold)cnt++;
        }
        return cnt;
    }
};