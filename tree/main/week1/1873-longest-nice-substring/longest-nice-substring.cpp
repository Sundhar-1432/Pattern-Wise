class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans="";

        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                string sub=s.substr(i,j-i+1);
                if(isNice(sub)&&ans.size()<sub.size()){
                    ans=sub;
                }
            }
        }
        return ans;
    }

    bool isNice(string sub){
        unordered_set<char>st(sub.begin(),sub.end());

        for(char c:sub){
            if(st.count(tolower(c))==0||st.count(toupper(c))==0)return false;
        }
        return true;
    }
};