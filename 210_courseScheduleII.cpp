
/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]

4, [[1,0],[2,0],[3,1],[3,2]]
There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.

*/

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses,prerequisites);
        vector<int> indegree = get_degrees(graph);
        vector<int> res;
        for(int i=0;i<numCourses;i++){
        	int j=0;
        	for(;j<numCourses;j++)
        		if(indegree[j]==0) break;
        	if(j==numCourses) return vector<int> (); //有向图有环
        	indegree[j]=-1;    
        	res.push_back(j);  //按照有向图的次序添加节点
        	for(auto n : graph[j])
        		indegree[n]-- ;   //减除相应的边
        }
        return res;
    }
    // build directed graph
    vector<unordered_set<int>> make_graph(int numCourses,vector<pair<int,int>>& prerequisites){
    	vector<unordered_set<int>> graph(numCourses);
    	for(auto p : prerequisites)
    		graph[p.second].insert(p.first);
    	return graph;
    }
    // 计算入度
    vector<int> get_degrees(vector<unordered_set<int>>& graph){
    	vector<int> degrees(graph.size(),0);
    	for(auto neighbors : graph)
    		for(auto n : neighbors)
    			degrees[n]++;
    	return degrees;
    }
};
