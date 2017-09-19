/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /*
 解决思路：
      先对数组进行升序排序
	  然后对数组进行遍历 让第一个数等于第二个数和第三个数的负数，由于数组已经有序，第一个数是遍历的次序为n,
	  第二个数为n+1，第三个数为数组的最后一个数组即最大的数，根据三个数和与0进行比较，然后通过向后调整第二个数与向前调整第三个数
	  查看是否有满足条件的数值，如果有则进行保存，并跳过相同的数值重复循环。
	  
调试过程：Runtime Error Message: realloc(): invalid next size: 0x0000000000bff750 ***
     在重复条用realloc()函数，出现堆损坏，地址越界
 
 */
 
 
#include <stdio.h>
#include <stdlib.h>
 
void quick_sort(int *arr,int l,int r) 
{
	if(l>=r) return;
	int temp=arr[l];
	int i=l,j=r;
	while(i<j)
	{
		while(i<j && arr[j]>=temp)
			j--;
		if(i<j)
			arr[i++]=arr[j];
		while(i<j && arr[i]<temp)
			i++;
		if(i<j)
			arr[j--]=arr[i];
	}
	arr[i]=temp;
	quick_sort(arr,l,i-1);
	quick_sort(arr,i+1,r);
}
 
int** threeSum(int* nums, int numsSize, int* returnSize)
{
    quick_sort(nums,0,numsSize-1);//先排序
	//int j=0;
	// for(;j<numsSize;j++)
		// printf("%d  ",nums[j]);
	int **re=(int **)malloc(sizeof(int*)*100);
	int *nums_r=nums;
	int i=0;
	int targe,*front,*back;
	int sum=0;
	int mem_sum=100;//用来标记指针数组的大小
	for(;nums_r<nums+numsSize;nums_r++)
	{
		targe=*nums_r;
		front=nums_r+1;
		back=nums+numsSize-1;
		while(front<back)
		{
			sum=*front + *back;
			if(sum+targe<0)
				front++;
			else if(sum+targe>0)
				back--;
			else
			{
				int my_len=sizeof(*re)/sizeof(int*);//错误 sizeof(re)并不能返回指针指向内存的大小 而是返回保存该指针的大小
				printf("my_len:%d\n",my_len);
				if(i>mem_sum)
				{
					printf("ok\n");
					re=(int **)realloc(re,sizeof(int*)*(10+mem_sum));
					mem_sum+=10;
					printf("ok\n");
				}
					
				if(re==NULL)
				{
					printf("mem not \n");
					return NULL;
				}
				int*p= (int*)malloc(3*sizeof(int));
				*(re+i)=p;
				p[0]=*nums_r;
				p[1]=*front;
				p[2]=*back;
				i++;
				printf("p:%d %d %d i:%d\n",p[0],p[1],p[2],i);
				while(front<back && p[1]==*front) front++;//跳过重复的
				while(front<back && p[2]==*back) back--;//跳过重复的
			}
		}
		while(nums_r<nums+numsSize-1 && *nums_r==*(nums_r+1)) nums_r++;//跳过重复的组
	}
	*returnSize=i;
	printf("%d\n",i);
	return (int **)re;
}
int main(int argc, char **argv)
{
	int arr[]={1,0,-4,3,-3,2,4,-2,2,2,3,-4,-3,-1,-5,-1,1};
	int *b=NULL;
	int returnSize;
	int len=sizeof(arr)/sizeof(int);
	printf("len:%d\n",len);
	int **p=threeSum(arr,len,&returnSize);
	int i=0;
	for(;i<returnSize;i++)
		printf("%d %d %d\n",p[i][0],p[i][1],p[i][2]);
	return 0;
}


























