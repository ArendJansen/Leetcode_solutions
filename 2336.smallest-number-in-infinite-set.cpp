/*
 * @lc app=leetcode id=2336 lang=cpp
 *
 * [2336] Smallest Number in Infinite Set
 */

// @lc code=start
class SmallestInfiniteSet {
public:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    std::unordered_set<int> set;
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; ++i){
            pq.push(i);
            set.insert(i);
        }
    }
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        set.erase(x);
        return x;
    }
    
    void addBack(int num) {
        if (set.count(num) == 0){
            pq.push(num);
            set.insert(num);

        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end

