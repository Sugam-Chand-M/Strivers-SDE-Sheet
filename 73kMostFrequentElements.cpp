class Solution {
public:
    typedef pair<int,int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; // max heap
        for(auto ele:nums)
            m[ele]++;
        priority_queue<pi> pq;
        for(auto it:m)
            pq.push({it.second,it.first});
        vector<int> ans;
        while(k--)
        {
            pi cur=pq.top();
            pq.pop();
            ans.push_back(cur.second);
        }
        return ans;
    }
};