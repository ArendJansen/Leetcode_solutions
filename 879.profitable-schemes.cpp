/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start

class Solution {
public:
    int helper(
        int n, 
        int minProfit, 
        vector<int>& group,
        vector<int>& profit, 
        int i, 
        unordered_map<int, unordered_map<int, unordered_map<int,int>>> & cache,
        int cprofit){

        if (cache.count(i) && cache[i].count(n) && cache[i][n].count(cprofit)) {
            return cache[i][n][cprofit];
        }

        int res = 0;
        if (i == profit.size() || n <= 0){
            if (minProfit <= cprofit){
                cache[i][n][cprofit] = 1;
                return 1;

            }
            else{
                cache[i][n][cprofit] = 0;
                return 0;
    
            }
        }
        // int res = 0;
        // if (minProfit < 0){
        //     ++res;
        // }
        int commit = 0;
        if (n - group[i] >= 0){
            commit = helper(n - group[i], minProfit, group, profit,i+1, cache,cprofit + profit[i]);
      
        }
        int not_commit = helper(n,minProfit,group,profit,i+1, cache,cprofit);

        res = (commit + not_commit) % 1000000007;
        cache[i][n][cprofit] = res;
        return res;

    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        unordered_map<int, unordered_map<int, unordered_map<int,int>>>cache;
        return helper(n,minProfit,group,profit,0,cache,0);
    }
};

