/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {


        std::pair<int,int> entr(entrance[0],entrance[1]); 


        std::queue<std::pair<int,int>> que;
        std::set<std::pair<int,int>> visited;
        visited.insert(entr);

        int count = 0;
        
        if (entr.first > 0 && maze[entr.first -1 ][entr.second] != '+'){
            que.push(std::make_pair(entr.first -1, entr.second));
        }
        if (entr.first < maze.size() - 1 && maze[entr.first + 1 ][entr.second] != '+'){
            que.push(std::make_pair(entr.first + 1, entr.second));
        }
        if (entr.second > 0 && maze[entr.first][entr.second - 1] != '+'){
            que.push(std::make_pair(entr.first, entr.second -1 ));
        }
        if (entr.second < maze[0].size() - 1 && maze[entr.first][entr.second + 1] != '+'){
            que.push(std::make_pair(entr.first, entr.second + 1));
        }

        while(!que.empty()){
            ++count;
            int n = que.size();

            for (int i = 0; i < n; ++i){
                if (visited.count(que.front()) > 0 ){
                    que.pop();
                    continue;
                }
                if (que.front().first == 0 || que.front().first == maze.size() - 1){
                    return count;
                }
                if (que.front().second == 0 || que.front().second == maze[0].size() - 1){
                    return count;
                }
                if (que.front().first > 0 && maze[que.front().first -1 ][que.front().second] != '+'){
                    que.push(std::make_pair(que.front().first -1, que.front().second));
                }
                if (que.front().first < maze.size() - 1 && maze[que.front().first + 1 ][que.front().second] != '+'){
                    que.push(std::make_pair(que.front().first + 1, que.front().second));
                }
                if (que.front().second > 0 && maze[que.front().first][que.front().second - 1] != '+'){
                    que.push(std::make_pair(que.front().first, que.front().second -1 ));
                }
                if (que.front().second < maze[0].size() - 1 && maze[que.front().first][que.front().second + 1] != '+'){
                    que.push(std::make_pair(que.front().first, que.front().second + 1));
                }  
                visited.insert(que.front());
                que.pop();              
            }
        }
        return -1;

        
    }
};
// @lc code=end

