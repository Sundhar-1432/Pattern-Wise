class TaskManager {
public:
    // taskId -> {userId, priority}
    map<int, pair<int,int>> mp;

    // ordering by (-priority, -taskId) to simulate max-heap
    set<pair<int,int>> st; 

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &it : tasks) {
            int userId = it[0], taskId = it[1], priority = it[2];
            mp[taskId] = {userId, priority};
            st.insert({-priority, -taskId});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        st.insert({-priority, -taskId});
    }
    
    void edit(int taskId, int newPriority) {
        auto [userId, oldPriority] = mp[taskId];
        st.erase({-oldPriority, -taskId});
        st.insert({-newPriority, -taskId});
        mp[taskId] = {userId, newPriority};
    }
    
    void rmv(int taskId) {
        auto [userId, priority] = mp[taskId];
        st.erase({-priority, -taskId});
        mp.erase(taskId);
    }
    
    int execTop() {
        if (st.empty()) return -1;
        auto [negPriority, negTaskId] = *st.begin();
        int taskId = -negTaskId;
        int userId = mp[taskId].first;
        st.erase(st.begin());
        mp.erase(taskId);
        return userId;
    }
};
