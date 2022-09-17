class Solution {
public:
    void findCombinations(int ind,int target,vector<int> &candidates,vector<vector<int>> &ans,vector<int> &ds)
    {
        if(ind==candidates.size())
        {
            if(target==0)
                ans.push_back(ds);
            return;
        }
        // pick the element
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            findCombinations(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }
        findCombinations(ind+1,target,candidates,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,target,candidates,ans,ds);
        return ans;
    }
};