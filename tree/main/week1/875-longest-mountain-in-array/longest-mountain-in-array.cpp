class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int i = 1, n = arr.size();
        int left, right, tot = 0;
        while (i < n-1) {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
                left = i - 1;
                right = i + 1;
                //cout<<arr[i];
                while (left > 0 && arr[left] > arr[left - 1])
                    left--;
                while (right < n-1&& arr[right] > arr[right + 1])
                    right++;
                cout<<left<<" "<<right;
                tot = max(tot, (right - left + 1));
                i = right;
            } else {
                i++;
            }
        }
        return tot;
    }
};