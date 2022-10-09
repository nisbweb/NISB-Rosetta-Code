/*
 * Note :- While using the various traversal methods, always provide the index as 1 from the main function
 */

public class BinaryTreeArray{
    String[] arr;
    int lastUsedIndex;
    /*
     * Time complexity for creating a new blank tree using arrays is O(1)
     * Space complexity is O(n)
     */
    public BinaryTreeArray(int size){
        arr = new String[size+1];
        this.lastUsedIndex = 0;
        System.out.println("Blank tree of size "+size+" has been created");
    }
    
    private boolean isFull(){
        if(arr.length-1 == lastUsedIndex){
            return true;
        }
        return false;
    }
    /*
     * Space & time complexity for insert operation is O(1)
     */
    public void insert(String value){
        if(!isFull()){
            arr[lastUsedIndex+1] = value;
            lastUsedIndex++;
            System.out.println(value+" successfully inserted");
        }
        else{
            System.out.println("Binary Tree is full");
        }
    }
    /*
     * Space Complexity is O(n), since the recursive operations need to be stored in the memory heap
     * Time complexity is O(n)
     * time complexity of lines 43 & 44 is O(n/2)
     */
    public void preOrder(int index){
        if(index>lastUsedIndex){
            return;
        }
        System.out.print(arr[index] + " ");
        preOrder(index*2);
        preOrder(index*2 + 1);
    }
    /*
     * Space Complexity is O(n), since the recursive operations need to be stored in the memory heap
     * Time complexity is O(n)
     * time complexity of lines 55 & 57 is O(n/2)
     */
    public void inOrder(int index){
        if(index>lastUsedIndex){
            return;
        }
        inOrder(index*2);
        System.out.print(arr[index] + " ");
        inOrder(index*2 + 1);
    }
    /*
     * Space Complexity is O(n), since the recursive operations need to be stored in the memory heap
     * Time complexity is O(n)
     * time complexity of lines 68 & 69 is O(n/2)
     */
    public void postOrder(int index){
        if(index>lastUsedIndex){
            return;
        }
        postOrder(index*2);
        postOrder(index*2 + 1);
        System.out.print(arr[index] + " ");
    }
    /*
     * Time complexity is O(n)
     * Space complexity is O(1)
     */
    public void levelOrder(){
        for(int i = 1; i <= lastUsedIndex; i++){
            System.out.print(arr[i] + " ");
        }
    }
    /*
     * Time complexity is O(n)
     * Space complexity is O(1)
     */
    public int search(String val){
        for(int i = 1; i <= lastUsedIndex; i++){
            if(arr[i] == val){
                System.out.println("Value found");
                return i;
            }
        }
        System.out.println("Not found");
        return -1;
    }
    /*
     * Time complexity is O(n)
     * Space complexity is O(1)
     */
    public void delete(String val){
        int location = search(val);
        if(location == -1){
            System.out.println("The value does not exist in the tree");
            return;
        }
        arr[location] = arr[lastUsedIndex];
        lastUsedIndex--;
        System.out.println("Value successfully deleted from the tree");
    }
    /*
     * Space & time complexity is O(1)
     */
    public void deleteTree(){
        try{
            arr = null;
            System.out.println("The tree was successfully deleted");
        }
        catch(Exception e){
            System.out.println("Tree could not be deleted due to an error");
        }
    }
}