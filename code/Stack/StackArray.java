public class Stack {
  int[] arr;
  int topOfStack;

  public Stack(int size) {
    this.arr = new int[size];
    this.topOfStack = -1;
    System.out.println("The Stack is created with size of: " + size);
  }

  // isEmpty
  public boolean isEmpty() {
    if (topOfStack == -1) {
      return true;
    } else {
      return false;
    }
  }

  // isFull

  public boolean isFull() {
    if (topOfStack == arr.length-1) {
      // System.out.println("The Stack is full!");
      return true;
    } else {
      return false;
    }
  }

  // Push
  public void push(int value) {
    if (isFull()) {
      System.out.println("The Stack is full!");
    } else {
      arr[topOfStack+1] = value;
      topOfStack++;
      System.out.println("The value is successfully inserted");
    }
  }

  // pop

 public int pop() {
    if (isEmpty()) {
      System.out.println("The stack is empty");
      return -1;
    } else {
      int topStack = arr[topOfStack];
      topOfStack--;
      return topStack;
    }
  }

// Peek method
public int peek() {
  if (isEmpty()) {
    System.out.println("The stack is empty!");
    return -1;
  } else {
    return arr[topOfStack];
  }
}

//  Delete method
public void deleteStack() {
  arr = null;
  System.out.println("The Stack is successfully deleted");
}



}
