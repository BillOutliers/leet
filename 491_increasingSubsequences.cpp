/*
Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.
找出递增序列
*/

/*
使用DFS遍历，对于重复项
使用set去重

*/

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.empty()) return res;
        // sort(nums.begin(),nums.end());
        vector<int> tmp;
        set<vector<int>> s;
        dfs(s,nums,tmp,0);
        return vector<vector<int>> (s.begin(),s.end());
    }
    void dfs(set<vector<int>> &s,vector<int>& nums,vector<int>& tmp,int start){
    	if(tmp.size()>1)
    		s.insert(tmp);
    	if(start>=nums.size()) return;
    	for(int i=start;i<nums.size();i++){
    		if(i!=start && (i-1>=0) && nums[i]==nums[i-1]) continue;
            if(tmp.empty() || nums[i]>=tmp.back()){
                tmp.push_back(nums[i]);
    		    dfs(s,nums,tmp,i+1);
    		    tmp.pop_back();
            }
    	}
    }

};

