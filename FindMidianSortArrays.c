/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
两个递增数组，长度分别为nums1、nums2，找到其中的中位数。
分析：
    total=nums1+nums2 ,如果total为奇数，则中位数为两个数组排序后第total/2+1值;
	如果total为偶数，则中位数为两个数组排序后第total/2+1值与第total/2个值的均值。
若采用归并排序，其时间复杂度为O(total log(total))，不能解决问题。
采用寻找第k个值的问题(两个序列均为升序),即寻找total/2的值(奇数)或均值。
    设两个数组分别为a,b;数组长度分别为m,n.把数组a,b都分为两部分，数组a左边的元素数
为pm,pm为k/2与m中的较小的一个值，a[pm-1]左边有pm-1个元素比它小；数组b左边的元素数为pn，
pn=k-pm,b[pn-1]左边有pn-1个值比它小。通过比较a[pm-1]与b[pn-1]的值，小的那个值其左边的所有元素
必定都比第k个元素小，故可舍去这部分小的元素并调整k的值(k的值减去舍弃的元素个数)，然后重复
以上步骤；如果a[pm-1]与b[pn-1]相等，则这两个值即使第k个元素值
边界：
	如果a或者b为空，则直接返回a[k-1]或者b[k-1]；
	如果k为1，我们只需要返回a[0]和b[0]中的较小值；
	如果a[k/2-1]=b[k/2-1]，返回其中一个；

*/

#include <stdio.h>
double findKth(int *a,int m,int *b,int n,int k)
{
	if(m>n)
		return findKth(b,n,a,m,k);  //选择长度短的在前面，方便后面部分选取
	if(m==0)
		return b[k];//数组a为空，之间返回数组b的第k个值
	if(k==1)
		return a[0]>b[0] ? b[0] : a[0];
	int pm= m > k/2 ? k/2 : m;   //选择pm部分的值
	int pn= k - pm; //pm 部分与pn 部分数量和为k
	if(a[pm-1] > b[pn-1])  //数组a的第pm个值与数组b的第pn个值进行比较 然后把小的部分丢掉
	    return findKth(a,m,b+pn,n-pn,k-pn);
	else if(a[pm-1] < b[pn-1])
		return findKth(a+pm,m-pm,b,n,k-pm);
	else
		return a[pm-1];  //两者相等，即找到第k个值
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total=nums1Size+nums2Size;
    if(total%2 == 1)
        return findKth(nums1,nums1Size,nums2,nums2Size,total/2+1);
    else
        return ( findKth(nums1,nums1Size,nums2,nums2Size,total/2+1)+ findKth(nums1,nums1Size,nums2,nums2Size,total/2))/2;
}
int main(int argc,char **argv)
{
	int a[]={255,586,877};
	int b[]={1,2,5,6,9,10,23,66,77};
	int i=sizeof(a)/sizeof(int);
	int j=sizeof(b)/sizeof(int);
	int total=i+j;
	printf("%f\n",findMedianSortedArrays(a,i,b,j));
	return 0;
}


