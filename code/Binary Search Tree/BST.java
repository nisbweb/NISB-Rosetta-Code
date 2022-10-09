import java.util.Queue;
import java.util.LinkedList;
public class BST{
    BSTNode root;
    public BST(){
        this.root = null;
        System.out.println("Binary Search Tree created");
    }
    /*
     * Space & time complexity both is O(log n)
     */
    private BSTNode insert(BSTNode node, int val){
        if(node == null){
            BSTNode newNode = new BSTNode();
            newNode.data = val;
            return newNode;
        }
        else if(val <= node.data){
            node.left = insert(node.left,val);
            return node;
        }
        else{
            node.right = insert(node.right,val);
            return node;
        }
    }
    public void insert(int val){
        root = insert(root,val);
        // System.out.println("Value successfully inserted");
    }
    // Space & time complexity is O(n)
    public void preOrder(BSTNode node){
        if(node == null){
            return;
        }
        System.out.print(node.data + " --> ");
        preOrder(node.left);
        preOrder(node.right);
    }
    // Space & time complexity is O(n)
    public void inOrder(BSTNode node){
        if(node == null){
            return;
        }
        inOrder(node.left);
        System.out.print(node.data + " --> ");
        inOrder(node.right);
    }
    // Space & time complexity is O(n)
    public void postOrder(BSTNode node){
        if(node == null){
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data+" --> ");
    }
    // Space & time complexity is O(n)
    public void levelOrder(){
        Queue<BSTNode> q = new LinkedList<BSTNode>();
        q.add(root);
        while(!q.isEmpty()){
            BSTNode node = q.remove();
            System.out.print(node.data + " --> ");
            if(node.left != null){
                q.add(node.left);
            }
            if(node.right != null){
                q.add(node.right);
            }
        }
    }
    // Space & time complexity is O(log n)
    public void search(BSTNode node,int val){
        if(node == null){
            System.out.println("Value not found in the tree");
        }
        else if(node.data == val){
            System.out.println("Value found in the tree");
        }
        else if(val < node.data){
            search(node.left,val);
        }
        else{
            search(node.right,val);
        }
    }
    // Minimum node
    public static BSTNode minimumNode(BSTNode root) {
        if (root.left == null) {
            return root;
        } else {
            return minimumNode(root.left);
        }
    }
    // Space & time complexity is O(log n)
    // Delete node
    public BSTNode deleteNode(BSTNode root, int value) {
        if (root == null) {
            System.out.println("Value not found in BST");
            return null;
        }
        if (value < root.data) {
            root.left = deleteNode(root.left, value);
        } else if (value > root.data) {
            root.right = deleteNode(root.right, value);
        } else {
            if (root.left != null && root.right != null) {
                BSTNode temp = root;
                BSTNode minNodeForRight = minimumNode(temp.right);
                root.data = minNodeForRight.data;
                root.right = deleteNode(root.right, minNodeForRight.data);
            } else if (root.left != null) {
                root = root.left;
            } else if (root.right != null) {
                root = root.right;
            } else {
                root = null;
            }
        }
        return root;
    }
    // Space & time complexity is O(1)
    public void deleteBST() {
        root = null;
        System.out.println("BST has been deleted successfully");
      }
    
}