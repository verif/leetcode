/*
Clone an undirected graph. Each node in the graph contains a label and a list
of its neighbors.
OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and
each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as
separated by #.
First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a
self-cycle.
Visually, the graph looks like the following:
        1
       / \
      /   \
     0 --- 2
          / \
          \_/
*/

/**
   * Definition for undirected graph.
   * struct UndirectedGraphNode {
   *     int label;
   *     vector<UndirectedGraphNode *> neighbors;
   *     UndirectedGraphNode(int x) : label(x) {};
   * };
*/

#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

typedef struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
} UndirectedGraphNode;

class Solution {
public:
     UndirectedGraphNode *cloneGraphRecursive(UndirectedGraphNode *node, 
         unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodeMap) {
         if (!node) return NULL;
         unordered_map<UndirectedGraphNode*,
                 UndirectedGraphNode*>::const_iterator it = nodeMap.find(node);
         if (it != nodeMap.end()) return it->second;

         UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
         nodeMap[node] = copy;

         vector<UndirectedGraphNode *>::const_iterator it2;
         for (it2 = node->neighbors.begin(); it2 != node->neighbors.end();
              it2++) {
             UndirectedGraphNode* childCopy = cloneGraphRecursive(*it2,nodeMap);
             copy->neighbors.push_back(childCopy);
         }

         return copy;
     }
     UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
         unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodeMap;
         return cloneGraphRecursive(node, nodeMap);
     }
};

static void printGraph(UndirectedGraphNode*  node, set<UndirectedGraphNode*>
                       &nodes)
{
    if (!node) return;
    cout << "Node: " << node->label;
    if (nodes.find(node) != nodes.end()) {
        return;
    }
    nodes.insert(node);
    cout << "   Neighbors: " << endl;
    for (vector<UndirectedGraphNode*>::const_iterator it =
         node->neighbors.begin(); it != node->neighbors.end(); it++) {
        printGraph(*it, nodes);
    }
    cout << endl;

}

int main()
{
    Solution s;
    UndirectedGraphNode* ret;

    UndirectedGraphNode n1(1);
    UndirectedGraphNode n2(0);
    UndirectedGraphNode n3(2);

    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);

    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);

    n3.neighbors.push_back(&n1);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n3);

    set<UndirectedGraphNode*> nodes;
    printGraph(&n1, nodes);
    ret = s.cloneGraph(NULL);
    n1.label = 0;
    n2.label = 0;
    n3.label = 0;

    nodes.clear();
    printGraph(ret, nodes);
}
