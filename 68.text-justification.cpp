/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start

#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        vector<string> res;
        string tmp;
        vector<string> currwords;
        int firstword = 0;
        int len = 0;
        int ldif = 0;
        for (int i = 0; i < words.size(); ++i){
            if (len + words[i].length() + firstword <= maxWidth){
                currwords.push_back(words[i]);
                len += words[i].length() + firstword;
                firstword = 1;
            }
            else{
                if (currwords.size() == 1){
                    ldif = maxWidth - currwords[0].length();
                    while (ldif > 0){
                        currwords[0].push_back(' ');
                        --ldif;
                    }
                    res.push_back(currwords[0]);
                }
                else if (currwords.size() > 1){
                    len = 0;
                    for (string x: currwords){
                        len += x.length();
                    }
                    ldif = maxWidth - len;
                    int nspaces = currwords.size() - 1;
                    int count = 0;
                    while (ldif > 0){
                        currwords[count % nspaces].push_back(' ');
                        ++count;
                        --ldif;
                    }
                    for (string x : currwords ){
                        tmp += x;
                    }
                    res.push_back(tmp);
                    tmp.clear();

                }
                currwords.clear();
                currwords.push_back(words[i]);
                len = words[i].length();
            }
        }

        if (currwords.size() > 0){
            if (currwords.size() == 1){
                ldif = maxWidth - currwords[0].length();
                while (ldif > 0){
                    currwords[0].push_back(' ');
                    --ldif;
                }
                res.push_back(currwords[0]);
            }
            else if (currwords.size() > 1){
                int nspaces = currwords.size() - 1;

                for (int i = 0; i < nspaces; ++i){
                    currwords[i].push_back(' ');
                }
                len = 0;
                for (string x: currwords){
                    len += x.length();
                }
                ldif = maxWidth - len;

                while (ldif > 0){
                    currwords.back().push_back(' ');
                    --ldif;
                }
                for (string x : currwords ){
                    tmp += x;
                }
                res.push_back(tmp);
                tmp.clear();

            }            
        }
        return res;

    }
};
// @lc code=end

