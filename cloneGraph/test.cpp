#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
// #include <queue>

using namespace std;

typedef struct Node {
    std::string name;
    std::vector<Node*> neighbors;
} Node;

typedef std::unordered_map<Node*, Node*> NodeMap;

void printGraph(Node* graph, NodeMap& map)
{
    cout << "Node: " << graph->name << endl;
    cout << "   Children:" << endl;
    for (std::vector<Node*>::iterator it = graph->neighbors.begin(); it !=
         graph->neighbors.end(); it++) {
        Node* child = *it;
        cout << "   " << child->name << endl;
        NodeMap::const_iterator got = map.find(child);
        if (got != map.end()) continue;
        printGraph(child, map);
    }
}

Node* cloneGraph(Node* graph, NodeMap& map)
{
    // std::queue<Node*> q;
    // q.push(graph);

    Node ncopy;
    Node* copy = new Node();
    copy->name = graph->name;
    std::pair<Node*, Node*> pair = std::make_pair(graph, copy);
    map.insert(pair);
   
    for (std::vector<Node*>::iterator it = graph->neighbors.begin(); it !=
         graph->neighbors.end(); it++) {
        Node* child = *it;
        NodeMap::const_iterator got = map.find(child);
        if (got != map.end()) continue;
        Node* child_copy = cloneGraph(child, map);
        copy->neighbors.push_back(child);
    }

    return copy;
}

int main(int argc, char** argv)
{
    Node n1;
    Node n2;
    Node n3;
    NodeMap map;

    n1.name = "n1";
    n2.name = "n2";
    n3.name = "n3";

    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);
    Node* out = cloneGraph(&n1, map);

    map.clear();
    cout << "Original Graph" << endl;
    printGraph(&n1, map);
    map.clear();
    cout << endl;
    cout << "Copy Graph" << endl;
    printGraph(out, map);
}

