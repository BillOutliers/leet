
/*
Given a n x n matrix where each of the rows and columns are sorted in ascending order, find 
the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.

思路1：
     利用优先队列大顶堆，设其最大长度为K,当长度为k后新来的值与堆顶进行比较
如果新来的元素小，则删除堆顶元素并加入新元素，遍历整个矩阵，最后堆顶元素即为kth smallest.
思路2：
     用二分查找，充分利用行、列升序的特性，我们假设矩阵中的中间元素为mid，查找不大于
	 mid的元素个数cnt，然后与k进行比较，通过比较调整相应的左右边界(左右边界最初为矩阵的左上角与
	 右下角).

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		if(matrix.empty()) return -1;
        priority_queue<int> pq;//大顶堆
		for(int i=0;i<matrix.size();i++)
			for(int j=0;j<matrix[0].size();j++)
			{
				if(pq.size()<k)
					pq.push(matrix[i][j]);
				else if(matrix[i][j]<pq.top())
				{
					pq.pop();
					pq.push(matrix[i][j]);
				}
			}
		return pq.top();
    }
	
	 int kthSmallest2(vector<vector<int>>& matrix, int k) {
		 int left=matrix[0][0],right=matrix[matrix.size()-1][matrix[0].size()-1];
		 while(left<right)
		 {
			 int mid=(left+right)>>1;
			 int cnt=find_not_great(matrix,mid);
			 if(cnt>=k)
				 right=mid;
			 else
				 left=mid+1;
		 }
		 return left;
	 }
	 int find_not_great(vector<vector<int>>& matrix,int target){
		 int m=matrix.size(),i=m-1,j=0,res=0;
		 while(i>=0 && j<matrix[0].size())
		 {
			 if(matrix[i][j]<=target)
			 {
				 res+=i+1;
				 j++;
			 }
			 else
				 i--;
		 }
		 return res;
	 }
	 
};







