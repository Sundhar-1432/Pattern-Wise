class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        
        for (int num : nums) {
            if(num>=0)mp[abs(num) % value]++;
            else{
                int n=num%value;
                cout<<n;
                if(n<0)mp[n+value]++;
                else mp[n]++;
            }
            
        }
        for(auto [key,cnt]:mp){
            cout<<key<<" "<<cnt<<endl;
        }
        int i = 0;
        while (1) {
            int val = i % value;
            if (mp.find(val) != mp.end()) {
                i++;
                mp[val]--;
                if (mp[val] <= 0)
                    mp.erase(val);
            } else
                return i;
        }
        return i;
    }
};