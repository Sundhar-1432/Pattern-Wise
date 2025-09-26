class Solution {
public:
    bool isPerfectSquare(int n) {
        int i=1,j=n;
        while(i<=j){
            long mid=i+(j-i)/2;
            if(mid*mid==n)return 1;
            else if(mid*mid>n)j=mid-1;
            else i=mid+1;
        }
        return 0;
    }
};