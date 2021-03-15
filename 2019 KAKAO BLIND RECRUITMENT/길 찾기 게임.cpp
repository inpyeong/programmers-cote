#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int id;
 	int x, y;   
    Node* leftChild;
    Node* rightChild;
};

bool cmp(Node* a, Node* b) {
    if(a->y == b->y) return a->x < b->x;
    return a->y > b->y;
}

void addNode(Node* root, Node* n) {
    if(n->x > root->x) {
        if(root->rightChild == NULL) root->rightChild = n;
        else addNode(root->rightChild, n);
    }
    if(n->x < root->x) {
        if(root->leftChild == NULL) root->leftChild = n;
        else addNode(root->leftChild, n);
    }
}

void preorder(Node* root, vector<int>& v) {
    if(root == NULL) return;
    v.push_back(root->id);
    preorder(root->leftChild, v);
    preorder(root->rightChild, v);
}

void postorder(Node* root, vector<int>& v) {
    if(root == NULL) return;
    postorder(root->leftChild, v);
    postorder(root->rightChild, v);
    v.push_back(root->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node*> nodes;
    for(int i = 0; i < nodeinfo.size(); ++i) {
        Node* node = new Node();
        node->id = i+1;
        node->x = nodeinfo[i][0];
        node->y = nodeinfo[i][1];
        nodes.push_back(node);
    }
    sort(nodes.begin(), nodes.end(), cmp);
    Node* root = nodes[0];
   	for(int i = 1; i < nodes.size(); ++i)
        addNode(root, nodes[i]);
    vector<int> pre, post;
    preorder(root, pre);
    postorder(root, post);
    vector<vector<int>> answer = { pre, post };
    return answer;
}
