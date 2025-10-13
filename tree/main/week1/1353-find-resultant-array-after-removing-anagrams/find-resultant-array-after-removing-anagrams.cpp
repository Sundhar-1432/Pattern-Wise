class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++) {
            if (i > 0 && isAnagram(words[i], words[i - 1]))
                continue;
            else
                ans.push_back(words[i]);
        }
        return ans;
    }
    bool isAnagram(string s1,string s2){
        vector<int>w1(26,0);
        vector<int>w2(26,0);

        for(char c:s1){
            w1[c-'a']++;
        }
        for(char c:s2){
            w2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(w1[i]!=w2[i])return false;
        }
        cout<<"hello"<<" ";
        return true;
    }
};