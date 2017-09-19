

/*
*zigzag covnert
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*n=numRows
Δ=2n-2    1                           2n-1                         4n-3
Δ=        2                     2n-2  2n                    4n-4   4n-2
Δ=        3               2n-3        2n+1              4n-5       .
Δ=        .           .               .               .            .
Δ=        .       n+2                 .           3n               .
Δ=        n-1 n+1                     3n-3    3n-1                 5n-5
Δ=2n-2    n                           3n-2                         5n-4
That is the zigzag pattern the question asked.
注意每一行两个数据间的步进,setp1 setp2.
*/
char* convert(char *s, int numRows)
{
	if(numRows==1)
		return s;
	int s_len=strlen(s);
	char *s_convert=(char*)malloc((s_len+1)*sizeof(char));
	char *s_r=s_convert;
	int i=0;
	int step1,step2;
	int pos;
	for(;i<numRows;++i)
	{
		step1=(numRows-i-1)<<1;
		step2=i<<1;
		pos=i;
		if(pos<s_len) 
			*s_convert++=s[pos];
		while(1)
		{
			pos+=step1;
			if(pos>=s_len)
				break;
			if(step1)
				*s_convert++=s[pos];
			pos+=step2;
			if(pos>=s_len)
				break;
			if(step2)
				*s_convert++=s[pos];			
		}
	}
	*s_convert='\0';
	return s_r;
}
int main(int argc,char **argv)
{
	char s[]="123456789";
	printf("%s\n",convert(s,2));
	return 0;
}













