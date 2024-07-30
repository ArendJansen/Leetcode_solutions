/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    Node* dfs(Node * node, map<int,Node*> & lmap){

        Node * res = new Node(node -> val);

        lmap[node -> val] = res;

        for (auto x: node -> neighbors){

            if (x == nullptr){
                continue;
            }
            if (lmap.count(x -> val) > 0){
                res -> neighbors.push_back(lmap[x -> val]);
            }
            else{
                res -> neighbors.push_back(dfs(x,lmap));
            }
        }
        return res;



    }
    Node* cloneGraph(Node* node) {

        map<int,Node*> lmap;

        if (node == nullptr){
            return nullptr;
        }
        
        return dfs(node,lmap);
    }
};
// @lc code=end

