
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

1.���O(m+n)�Ŀռ临�Ӷȣ�ֻ������״̬���飨���ȷֱ�Ϊm��n���ֱ�洢���е�״̬���ɣ�
Ȼ�����״̬���鴦����󼴿ɡ�
2.�����O(1)�Ŀռ临�Ӷ�����������Ҫ��¼���е�״̬���������˲��þ������һ�С�һ��
  ����Ϊ״̬���飬��Լ�˿ռ䡣
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty()) return ;
		int row=matrix.size(),column=matrix[0].size();
		//�Ե�һ�����һ����Ϊ״̬����
		bool row_first=false,column_first=false;
		for(int i=0;i<column;i++)//��һ��״̬
			if(matrix[0][i]==0)
			{
				row_first=true;
				break;
			}
		for(int i=0;i<row;i++)//��һ��״̬
			if(matrix[i][0]==0)
			{
				column_first=true;
				break;
			}
		for(int i=1;i<row;i++)//״̬����
			for(int j=1;j<column;j++)
				if(matrix[i][j]==0)
					matrix[0][j]=0,matrix[i][0]=0;
	    for(int i=1;i<row;i++)//���д���
			for(int j=1;matrix[i][0]==0 && j<column;j++)
				matrix[i][j]=0;
		for(int j=1;j<column;j++)//���д���
			for(int i=1;matrix[0][j]==0 && i<row;i++)
				matrix[i][j]=0;
		if(row_first)
			for(int i=0;i<column;i++)
				matrix[0][i]=0;
		if(column_first)
			for(int i=0;i<row;i++)
				matrix[i][0]=0;
    }
};


