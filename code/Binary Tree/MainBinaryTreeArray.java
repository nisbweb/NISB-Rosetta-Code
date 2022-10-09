public class MainBinaryTreeArray {
    public static void main(String[] args){
        BinaryTreeArray bt = new BinaryTreeArray(10);
        bt.insert("n1");
        bt.insert("n2");
        bt.insert("n3");
        bt.insert("n4");
        bt.insert("n5");
        bt.insert("n6");
        bt.insert("n7");
        bt.insert("n8");
        bt.insert("n9");
        bt.preOrder(1);
        System.out.println();
        bt.inOrder(1);
        System.out.println();
        bt.postOrder(1);
        System.out.println();
        bt.levelOrder();
        System.out.println();
        bt.delete("n3");
        bt.levelOrder();
    }
}
