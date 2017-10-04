/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/
克隆图的一个难点就是一个结点的邻居可能在已经出现过，这样你只要把他的指针加到邻居集合中即可，
也有可能这个结点还没出现过，因此你需要新建一个这个结点，因此我们需要一个hash表来对结点做一一映射
每次搜索的时候看这个结点是不是已经被创建，是的话就返回其copy，否则就创建，然后再依次深度遍历
其邻居结点并将其加入邻居集合中去．

*/



/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
        return clone(node,mp);
    }
    UndirectedGraphNode *clone(UndirectedGraphNode *node,unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>&mp){
    	if(!node) return NULL;
    	if(mp.find(node)!=mp.end())//查看节点是否已经生成
    		return mp[node];
    	mp[node]=new UndirectedGraphNode(node->label);
    	for(auto n : node->neighbors)
    		mp[node]->neighbors.push_back(clone(n,mp));
    	return mp[node];
    }
};
