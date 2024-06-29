/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

// @lc code=start

#include <string>
using namespace std;
class Trie {
public:
    Trie* child[26];
    bool end;
    Trie() {
        for (int i = 0; i < 26; ++i){
            child[i] = nullptr;
        }
        end = false;
    }
    
    void insert(string word) {


        if (word.length() == 0){
            return;
        }
        char x = word[0];

            if (child[x - 'a'] == nullptr ){

                child[x -'a'] = new Trie();
            }

            if (word.length() == 1){
                child[x - 'a'] -> end = true;
            }
            child[x- 'a'] -> insert(word.substr(1));
    }
    
    bool search(string word) {

        if (word.length() == 0){
            return true;
        }

        int n = 0;

        Trie* root = child[word[n] - 'a'];
        
        while (n < word.length()){
            if (n  > 0){
                root = root -> child[word[n]-'a'];
            }
            if (root == nullptr){
                return false;
            }
            ++n;
        }

        if (root -> end == false){
            return false;
        }

        return true;
        
    }
    
    bool startsWith(string prefix) {
        if (prefix.length() == 0){
            return true;
        }
        int n = 0;

        Trie* root = child[prefix[n] - 'a'];
        
        while (n < prefix.length()){
            if (n  > 0){
                root = root -> child[prefix[n]-'a'];
            }
            if (root == nullptr){
                return false;
            }
            ++n;
        }

        return true;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

