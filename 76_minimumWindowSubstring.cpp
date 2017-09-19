/*
Given a string S and a string T, find the minimum window in S which will contain all the characters 
in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the empty string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique 
minimum window in S

Ñ°ÕÒ×îÐ¡´°¿Ú
*/


class Solution {
public:
    string minWindow(string s, string t) {
      vector<int> hashmap(129,0);
	  for(int i=0;i<t.size();i++) hashmap[t[i]]++;
	  int begin=0,end=0,d=INT_MAX,head=0;
	  int count=t.size();
	  while(end<s.size())
	  {
		  if(hashmap[s[end]] > 0) 
			  count--;
		  hashmap[s[end]]--;
		  end++;
		  while(count==0)
		  {
			  if(d > end-begin) d=end - begin,head=begin;
			  if(hashmap[s[begin]]==0) count++;
			  hashmap[s[begin]]++;
			  begin++;
		  }
	  }
	  return d==INT_MAX ? "" : s.substr(head,d);
    }
};
