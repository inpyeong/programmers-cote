import java.util.*;

class Solution {
    class Node {
        Node(int id, int x, int y) {
            this.id = id;
            this.x = x;
            this.y = y;
        }
        int id;
        int x, y;
        Node left;
        Node right;
    };
    int Idx;
    List<Node> Nodes = new ArrayList<Node>();
    
    Comparator<Node> Comp = new Comparator<Node>() {
        public int compare(Node a, Node b) {
            if (a.y == b.y)
                return a.x - b.x;
            
            return b.y - a.y;
        }
    };
    
    void addNode(Node parent, Node child) {
        if (child.x < parent.x) {
            if(parent.left == null)
                parent.left = child;
            else
                addNode(parent.left, child);
        } else {
            if(parent.right == null)
                parent.right = child;
            else
                addNode(parent.right, child);
        }
    }
    
    void preorder(int[][] answer, Node node) {
        if (node == null) return;
        
        answer[0][Idx++] = node.id;
        preorder(answer, node.left);
        preorder(answer, node.right);
    }
    
    void postorder(int[][] answer, Node node) {
        if (node == null) return;
        
        postorder(answer, node.left);
        postorder(answer, node.right);
        answer[1][Idx++] = node.id;
    }
    
    public int[][] solution(int[][] nodeinfo) {
        int size = nodeinfo.length;
        for (int i = 0; i < size; ++i) {
            Nodes.add(new Node(i+1, nodeinfo[i][0], nodeinfo[i][1]));
        }
        Nodes.sort(Comp); 
        
        Node root = Nodes.get(0);
        for (int i = 1; i < size; ++i)
            addNode(root, Nodes.get(i));
        
        int[][] answer = new int[2][size];
        preorder(answer, root);
        Idx = 0;
        postorder(answer, root);
        return answer;
    }
}
