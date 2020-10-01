//Breadth first search
/*
The graph is as follows in adjacency list format
0 -> |1|->|2|/
1 -> |2|/
2 -> |1|/
3 -> |5|->|4|/
4 -> |4|->|5|/
5 -> /

*/
#include<iostream>
#include<list>                      // include list to use list and it's methods
using namespace std;
// class for the graph data structure
class Graph
{
    int N;                          // No. of nodes

    list<int> *node;                //Vector of nodes 
public:
    Graph(int N);                   //constructor 
    void addEdge(int p,int q);      //func to add edge b/w unidirectional node p to q
    void BFS(int x);                //func to traverse through the graph starting from node x

};
Graph::Graph(int N)
{
    this->N = N;                    
    node = new list<int>[N];        //initalizing a list names node of size N

}
void Graph::addEdge(int p, int q)
{
    node[p].push_back(q);           //enqueuing q to p th node
}
void Graph::BFS(int x)
{
    bool *visited = new bool[N];    // to keep a count the nodes which are visited a bool array 'visited' is made
    for(int i=0;i<N;i++)
        visited[i] =  false;        // all the elements are initialized to false and will be made true as the traversal begins
    list<int> queue;                // queue list is made to keep the node in check and it's adj nodes on the queue
    visited[x] = true;              // the node to traversed form is marked visited
    queue.push_back(x);             // and put on the queue

    list<int>::iterator i;          // iterating variable is defined to iterate through the linked list of the node in check

    while(!queue.empty())           // while queue is not empty 
    {
        x = queue.front();          // the front of queue is assigned to x, then 
        cout << x <<" ";            // printed and then
        queue.pop_front();          // 1st node is popped out of the queue
        for(i = node[x].begin(); i!=node[x].end();++i)
        {                           // the nodes linked to the node in check are iterated
            if(!visited[*i])        // checked if they are visited earlier or not
            {
                visited[*i] = true; // if not it is marked as visited and put at end of queue
                queue.push_back(*i);    
            }
        }
    }
}
int main()
{
   int a;
   cout <<"Enter the node to traverse from\n";
   cin >> a;                        // Traverse starts from user defined node
    
    cout << "Traversing from node "<<a<<endl;
    Graph g(6);                     // the class is initialized with 6 nodes
    g.addEdge(0,1);                 // the edges are defined 0 to 1, 0 to 2, 2 to 1 and so on
    g.addEdge(0,2);                 //  Note: this is unidirection to make it bidirection,
    g.addEdge(1,3);                 // g.addEdge(1,2);
    g.addEdge(1,4);                 // g.addEdge(3,1); and so on
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(3,7);
    g.addEdge(3,8);
    g.BFS(a);                       // Traversal starts
    return 0;
}