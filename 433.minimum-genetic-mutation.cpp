/*
 * @lc app=leetcode id=433 lang=cpp
 *
 * [433] Minimum Genetic Mutation
 */

// @lc code=start
#include <queue>
#include <vector>
#include <string> 

using namespace std;


class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {

        std::queue<string> lq;

        lq.push(startGene);

        vector<char> letters = {'A','C','T', 'G'};

        int count = 0;

        while(!lq.empty()){
            if (count == endGene.length() +1){
                return -1;
            }
            int qsize = lq.size();

            for (int j = 0; j < qsize; ++j){
                string tmp = lq.front();
                lq.pop();
                if (tmp == endGene){
                    return count;
                }

                for (int i = 0; i < tmp.length();++i){
                    for (char y: letters){
                        if (tmp[i] != y){
                            string tmp2 = tmp;
                            tmp2[i] = y;
                            for (string x : bank){
                                if (tmp2 == x){
                                    lq.push(tmp2);
                                }
                            }
                        }   
                    }
                }
            }
            ++count;
        }

        return -1;


    }
};


// @lc code=end

