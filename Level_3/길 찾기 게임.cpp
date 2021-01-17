#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
 	int label;
    int x, y;
    TreeNode* leftChild;
    TreeNode* rightChild;
};

bool cmp(TreeNode& a, TreeNode& b) {
    // 만약 y좌표가 같다면 x좌표를 오름차순으로 정렬
    if(a.y == b.y) return a.x < b.x;
    // 그렇지 않으면 y좌표를 내림차순으로 정렬
    else return a.y > b.y;
}

void addTreeNode(TreeNode* parent, TreeNode* child) {
    if(child->x < parent->x) {
       	if(parent->leftChild == nullptr) parent->leftChild = child;
        else addTreeNode(parent->leftChild, child);
    }
    else {
       	if(parent->rightChild == nullptr) parent->rightChild = child;
        else addTreeNode(parent->rightChild, child);
    }
}

void preorder(vector<int>& answer, TreeNode* treeNode) {
   	if(treeNode == nullptr) return; 
    answer.push_back(treeNode->label);
    preorder(answer, treeNode->leftChild);
    preorder(answer, treeNode->rightChild);
}

void postorder(vector<int>& answer, TreeNode* treeNode) {
   	if(treeNode == nullptr) return; 
    postorder(answer, treeNode->leftChild);
    postorder(answer, treeNode->rightChild);
    answer.push_back(treeNode->label);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<TreeNode> treeNodes;
    for(int i = 0; i < nodeinfo.size(); ++i)
        treeNodes.push_back({ i+1, nodeinfo[i][0], nodeinfo[i][1] });
	sort(treeNodes.begin(), treeNodes.end(), cmp);    
    
    TreeNode* root = &treeNodes[0];
    for(int i = 1; i < treeNodes.size(); ++i)
        addTreeNode(root, &treeNodes[i]);
    
    vector<vector<int> > answer(2);
    preorder(answer[0], root);
    postorder(answer[1], root);
    
    return answer;
}
