/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
click to show more hints.

Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.

*/
/*
参考： http://blog.csdn.net/dm_vincent/article/details/7714519
拓扑排序：将有向图中的顶点以线性方式进行排序。即对于任何连接自顶点u到顶点v的有向边uv，在最后的排序结果中，顶点u总是在顶点v的前面
Kahn算法：
摘一段维基百科上关于Kahn算法的伪码描述：
L← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    insert n into L
    foreach node m with an edge e from nto m do
        remove edge e from thegraph
        ifm has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least onecycle)
else 
    return L (a topologically sortedorder)
 
不难看出该算法的实现十分直观，关键在于需要维护一个入度为0的顶点的集合：
每次从该集合中取出(没有特殊的取出规则，随机取出也行，使用队列/栈也行，下同)一个顶点，将该顶点放入保存结果的List中。
紧接着循环遍历由该顶点引出的所有边，从图中移除这条边，同时获取该边的另外一个顶点，如果该顶点的入度在减去本条边之后为0，
那么也将这个顶点放到入度为0的集合中。然后继续从集合中取出一个顶点…………
当集合为空之后，检查图中是否还存在任何边，如果存在的话，说明图中至少存在一条环路。不存在的话则返回结果List，此List中的顺序就是对图进行拓扑排序的结果。
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph=make_graph(numCourses,prerequisites);
        vector<int> indegree=get_indegree(graph);
        for(int i=0;i<numCourses;i++){
        	int j=0;
        	for(;j<numCourses;j++)//寻找入度为0的顶点
        		if(indegree[j]==0) break;
        	if(j == numCourses) return false; //有向图存在环
        	indegree[j]=-1;//清除该顶点
        	for(int neighbors : graph[j])//把顶点j的所有邻接边都去除掉，相应的邻接顶点的入度减一
        		indegree[neighbors]--;
        }
        return true;
    }
    vector<unordered_set<int>> make_graph(int numCourses,vector<pair<int,int>>& prerequisites){
    	vector<unordered_set<int>> graph(numCourses);
    	for(auto p : prerequisites)
    		graph[p.second].insert(p.first);
    	return graph;//构造有向图
    }
    vector<int> get_indegree(vector<unordered_set<int>>& graph){
    	vector<int> indegree(graph.size(),0);
    	for(auto neighbors : graph)
    		for(int n : neighbors)
    			indegree[n]++;
    	return indegree;   //计算入度
    }


};
