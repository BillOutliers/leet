
/*
You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.
Note:
The length of the given array is positive and will not exceed 20.
The sum of elements in the given array will not exceed 1000.
Your output answer is guaranteed to be fitted in a 32-bit integer.
思路1：
     使用dfs遍历，找到符合的序列
思路2：
	由于元素都是非负数，把这些元素分为两类，一种是带正号的放在集合P，
	一种带负号的放在集合N中，如果其中的组合能够满足要求，即：
	sum(P) - sum(N) = S
	sum(P) + sum(N) = SUM   SUM为所有元素的和
	===> sum(p) = { SUM + S}/2
	把问题转化为在集合中寻找sum(P)的值即可
	SUM 必须大于等于S才有可能存在排列
	sum(p)必须为偶数才有可能存在排列
	寻找P的集合，转化为背包问题：
	dp[0]=1
	dp[i]+=dp[i-n]  n为一个元素值 dp[i]表示为目标值为i时的组合次数

*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int acc=0;
        dfs(nums,S,0,acc);
        return acc;
    }
    void dfs(vector<int>& nums,int target,int start,int& acc){
    	if(start>=nums.size()){
    		acc = target==0 ? acc+1 : acc;
    		return;
    	}
    	dfs(nums,target-nums[start],start+1,acc);
    	dfs(nums,target+nums[start],start+1,acc);
    }
/*
转化为背包问题

*/  

     int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        		sum+=nums[i];
        if(sum < S || (sum+S)&1 ) return 0;
        return subsetSum(nums,(S+sum)>>1);
    }
    int subsetSum(vector<int>& nums,int target){
    	vector<int> dp(target+1,0);
    	dp[0]=1;
    	for(int n : nums)
    		for(int i=target;i>=n;i--)
    			dp[i] += dp[i-n];
    	return dp[target];
    }
};
