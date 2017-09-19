
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
You may assume k is always valid, 1 �� k �� n2.

˼·1��
     �������ȶ��д󶥶ѣ�������󳤶�ΪK,������Ϊk��������ֵ��Ѷ����бȽ�
���������Ԫ��С����ɾ���Ѷ�Ԫ�ز�������Ԫ�أ����������������Ѷ�Ԫ�ؼ�Ϊkth smallest.
˼·2��
     �ö��ֲ��ң���������С�����������ԣ����Ǽ�������е��м�Ԫ��Ϊmid�����Ҳ�����
	 mid��Ԫ�ظ���cnt��Ȼ����k���бȽϣ�ͨ���Ƚϵ�����Ӧ�����ұ߽�(���ұ߽����Ϊ��������Ͻ���
	 ���½�).

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		if(matrix.empty()) return -1;
        priority_queue<int> pq;//�󶥶�
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







