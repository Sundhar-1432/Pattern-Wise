// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long i=1,j=n;
        while(i<=j){
            int mid=(i+j)/2;
            if(isBadVersion(mid)==false)i=mid+1;
            else j=mid-1;
        }
        return i;
    }
};