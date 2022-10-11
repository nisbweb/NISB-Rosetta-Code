import java.util.LinkedList;
import java.util.Queue;
public class BinaryTreeLL{
    
    BinaryNode root;
    public BinaryTreeLL(){
        this.root = null;
    }
    /*
     * Time complexity of line 17 & 18 is O(n/2)
     * Total time complexity of preOrder Traversal is O(n)
     * Space complexity is also O(n)
     */
    public void preOrder(BinaryNode node){
        if(node == null){
            return;
        }
        System.out.print(node.data + " --> ");
        preOrder(node.left);
        preOrder(node.right);
    }
    /*
     * Time complexity of line 29 & 31 is O(n/2)
     * Total time complexity of inOrder Traversal is O(n)
     * Space complexity is also O(n)
     */
    public void inOrder(BinaryNode node){
        if(node == null){
            return;
        }
        inOrder(node.left);
        System.out.print(node.data + " --> ");
        inOrder(node.right);
    }
    /*
     * Time complexity of line 44 & 45 is O(n/2)
     * Total time complexity of postOrder Traversal is O(n)
     * Space complexity is also O(n)
     */
    public void postOrder(BinaryNode node){
        if(node == null){
            return;
        }
        postOrder(node.left);
        postOrder(node.right);
        System.out.print(node.data + " --> ");
    }
    /*
     * Time complexity of line 54 is O(n)
     * Rest all the other lines have time complexity O(1)
     * Hence, the total time complexity is O(n)
     */
    public void levelOrder(){
        Queue<BinaryNode> q = new LinkedList<BinaryNode>();
        q.add(root);
        while(!q.isEmpty()){
            BinaryNode presentNode = q.remove();
            System.out.print(presentNode.data + " --> ");
            if(presentNode.left != null){
                q.add(presentNode.left);
            }
            if(presentNode.right != null){
                q.add(presentNode.right);
            }
        }
    }
    /*
     * Space & time complexity for these operations is O(n)
     * Space complexity is O(n) because we are creating a queue
     */
    public void search(String val){
        Queue<BinaryNode> q = new LinkedList<BinaryNode>();
        q.add(root);
        int count = 1;
        while(!q.isEmpty()){
            BinaryNode node = q.remove();
            if(node.data == val){
                System.out.println(val+" found in the tree at node "+count);
                return;
            }
            else{
                if(node.left != null){
                    q.add(node.left);
                }
                if(node.right != null){
                    q.add(node.right);
                }
            }
            count++;
        }
        System.out.println(val+" not found in the tree");
        return;
    }
    /*
     * Space & time complexity is O(n)
     * because we are creating a queue & finding an empty node
     * Note that the method used here is a little different from what is shown in the tutorial
     * This is my own method. In the tutorial, they have just taken a string as an argument and then
     * created a node inside the insert method and then inserted the node. I have taken a node as the input.
     */
    public void insert(BinaryNode node){
        if(root == null){
            root = node;
            System.out.println("Tree created");
            return;
        }
        Queue<BinaryNode> q = new LinkedList<BinaryNode>();
        q.add(root);
        int count = 2;
        while(!q.isEmpty()){
            BinaryNode presentNode = q.remove();
            if(presentNode.left == null){
                presentNode.left = node;
                break;
            }
            else if(presentNode.right == null){
                count++;
                presentNode.right = node;
                break;
            }
            else{
                q.add(presentNode.left);
                q.add(presentNode.right);
                count+= 2;
            }
        }
        System.out.println("Node successfully inserted at location no. "+count);
    }

    /*
     * The delete methods used here are not my own. I tried to do it all in one function only but the error
     * was that I wasn't able to get the last node. 
     * Regardless, the time complexity here is O(n) because the getDeepestNode() & deleteDeepestNode() functions
     * are called only once(yeah it's a bit confusing).
     * Space complexity is also O(n)
     */

    // Get Deepest node
    private BinaryNode getDeepestNode() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode presentNode = null;
        while (!queue.isEmpty()) {
            presentNode = queue.remove();
            if (presentNode.left != null) {
                queue.add(presentNode.left);
            }
            if (presentNode.right != null) {
                queue.add(presentNode.right);
            }
        }
        return presentNode;
    }

    // Delete Deepest node
    private void deleteDeepestNode() {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        BinaryNode previousNode, presentNode = null;
        while (!queue.isEmpty()) {
            previousNode = presentNode;
            presentNode = queue.remove();
            if (presentNode.left == null) {
                previousNode.right = null;
                return;
            } else if (presentNode.right == null) {
                presentNode.left = null;
                return;
            }
            queue.add(presentNode.left);
            queue.add(presentNode.right);
        }
    }

    // Delete Given node
    void deleteNode(String value) {
        Queue<BinaryNode> queue = new LinkedList<BinaryNode>();
        queue.add(root);
        while (!queue.isEmpty()) {
            BinaryNode presentNode = queue.remove();
            if (presentNode.data == value) {
                presentNode.data = getDeepestNode().data;
                deleteDeepestNode();
                System.out.println("The node is deleted!");
                return;
            } else {
                if (presentNode.left != null) queue.add(presentNode.left);
                if (presentNode.right != null) queue.add(presentNode.right);
            }
        }
        System.out.println("The node does not exist in this BT");
    }
    /*
     * Space & time complexity is O(1)
     */
    void deleteBT() {
        root = null;
        System.out.println("BT has been successfully deleted!");
      }
}