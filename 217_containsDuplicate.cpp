/*

Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       unordered_map<int,int> mp;
	   for(int i=0;i<nums.size();i++)
	   {
		   if(mp[nums[i]]++ ==1)
			   return true;
	   }
	   return false;
    }
};
int main()
{
	Solution mys;
	vector<int> nums={3,3};
	cout<<mys.containsDuplicate(nums)<<endl;
	return 0;
}

