class Solution {
public:
vector<vector<int>>ans;
void solve(int i,vector<int>& nums,int target,vector<int>&temp){
    if(target==0){
        ans.push_back(temp);
        return;
    }
    if(i==nums.size()|| target<0)
    return;
    temp.push_back(nums[i]);
    solve(i,nums,target-nums[i],temp);
    temp.pop_back();
    solve(i+1,nums,target ,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(0,candidates,target,temp);
        return ans;
        
    }
};