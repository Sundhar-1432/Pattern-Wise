class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1;
        if(people[0]==limit)return people.size();
        int cnt=0;
        while(i<=j){
            if((people[i]+people[j])<=limit){
                cnt+=1;
                i++;
                j--;
            }
            else{
                cnt++;
                j--;
            }
        }
        return cnt;
    }
};