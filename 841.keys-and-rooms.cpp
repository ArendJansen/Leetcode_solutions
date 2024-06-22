/*
 * @lc app=leetcode id=841 lang=cpp
 *
 * [841] Keys and Rooms
 */

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        std::set<int> set;
        std::stack<int> stk;
        int x = 0;

        set.insert(0);
        for (int i = 0; i < rooms[0].size(); ++i){
            stk.push(rooms[0][i]);
        }
        while (!stk.empty()){
            if (set.count(stk.top()) > 0 ){
                stk.pop();
            }
            else {
                x = stk.top();
                set.insert(x);
                stk.pop();
                for (int i = 0; i < rooms[x].size(); ++i){
                     stk.push(rooms[x][i]);
                }
            }
        }

        for (int i = 0; i < rooms.size(); ++i){
            if (set.count(i) == 0){
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

