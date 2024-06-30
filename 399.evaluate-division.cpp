/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
#include <vector>
#include <string>
#include <map> 
#include <set>

using namespace std;

class Solution {
public:
    double dfs(
        vector<vector<string>>& equations,
        vector<double>& values,
        std::string l,
        std::string r,
        set<string> visited){

            if (l == r){
                for (int i = 0;  i < equations.size(); ++i){
                    if (equations[i][0] == l || equations[i][1] == l){
                        return 1;
                    }
                }
                return -1;
            }

            string cache_s = l + '-' + r;

            if (visited.count(l + '-' + r) > 0){
                        return -1;
            }
            visited.insert(cache_s);

            for (int i = 0;  i < equations.size(); ++i){
                if (equations[i][0] == l && equations[i][1] == r){
                    return  values[i];
                }
                else if (equations[i][1] == l && equations[i][0] == r){
                    return  1 / values[i];
                }
                else if (equations[i][0] == l){
        
                    double val =  dfs(equations,values,equations[i][1],r, visited);
                    if (val != -1.0){
                        return val * values[i];
                    }
                }
                else if (equations[i][1] == l){
                    double val = dfs(equations,values,equations[i][0],r, visited);
                    if (val != -1.0){
                        return val * 1 / values[i];
                    }
                }

            }

            return -1;


    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> res;
        map<string,double> cache;
    
        for (int i = 0;  i < queries.size(); ++i){
            set<string> visited;
            res.push_back(dfs(equations,values,queries[i][0],queries[i][1], visited));
        }

        return res;
    }
};
// @lc code=end

