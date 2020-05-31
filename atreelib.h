#include <iostream>
#include <stack>
#include <queue>

using std::cout;
using std::cin;
using std::end;
using DataType = char;
using Node = int;

const int MAXLENGTH = 500;
const int NIL = -1;

struct Tree
{
    DataType Data[MAXLENGTH];  
    Node Parent[MAXLENGTH];
    int MaxNode; 
}; 

void makeNull_Tree (Tree &T) 
{
    T.MaxNode = 0; 
}

int emptyTree(Tree T) 
{
    return T.MaxNode == 0;
}

Node parent(Node n, Tree T) 
{
	if(emptyTree(T) || (n > T.MaxNode - 1)) return NIL;
	else return T.Parent[n];
} 

DataType label(Node n, Tree T) 
{ 
	if(!emptyTree(T) && (n <= T.MaxNode - 1)) return T.Data[n];
    else return -1;
}

Node root(Tree T)
{
    if (!emptyTree(T)) return 0;
    else return NIL;
}

Node leftMostChild(Node n, Tree T) {
    if (n < 0) return NIL;
    Node i = n + 1;
    while (i <= T.MaxNode - 1)
    {
        if (T.Parent[i] == n) return i; 
        else i = i + 1;
    }
    return NIL;
}

Node rightSibling(Node n, Tree T) {
	if (n < 0) return NIL;
    Node i, parent;
    int found = 0;
	parent = T.Parent[n];
	i = n + 1;
    while (i <= T.MaxNode - 1)
    {
        if (T.Parent[i] == parent) return i;
        else i = i + 1;
    }
    return NIL;
}

void preOrder(Node n,Tree T) 
{
    if (n != NIL) 
    {
        std::stack<Node> S; //buffer, parents
        Node buf = n;
        while (true)
        {
            std::cout << label(buf, T) << ' ';
            if (leftMostChild(buf, T) != NIL) 
            {
                S.push(buf);
                buf = leftMostChild(S.top(), T);
            }
            else if (rightSibling(buf, T) != NIL)
            {
                buf = rightSibling(buf, T);
            }
            else
            {   
                while(true)
                {
                    if (S.empty()) break;
                    else if (rightSibling(S.top(), T) != NIL)
                    {
                        buf = rightSibling(S.top(), T);
                        S.pop();
                        break;
                    }
                    else
                        S.pop();
                }
                if (S.empty())
                    break;
            }
        }
    }
}

/*void preOrder(Node n, Tree T) 
{
    if (n != NIL) {
        cout << label(n ,T) << " ";
        Node i = leftMostChild(n, T);
        while (i != NIL)
        {
            preOrder(i, T);
            i = rightSibling(i, T);
        }
    }
}*/

void inOrder(Node n, Tree T) {
    if (n != NIL) 
    {
        Node i = leftMostChild(n, T);
        if (i != NIL)
        {
            inOrder(i, T);
        }
        cout << label(n, T) << " ";
        if (i != NIL)
        {
            i = rightSibling(i, T);
        }
        while (i != NIL) 
        {
            inOrder(i, T);
            i = rightSibling(i, T);
        }
    }
}  

void postOrder(Node n,Tree T) {
    if (n != NIL) 
    {
        Node i = leftMostChild(n,T);
        while (i != NIL) {
            postOrder(i, T);
            i = rightSibling(i,T);
        }
        std::cout << label(n, T) << ' ';
    }
}

void levelOrder(Node n, Tree T)
{
    std::queue<Node> Q;
    Q.push(n);
    while (!Q.empty()) 
    {
        std::cout << label(Q.front(), T) << ' ';
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
}

// Number of Node in a tree
int numberOfNodes(Tree T){
	return T.MaxNode;
}

void showPathTo(Node n, Node m, Tree T)
{
    std::stack<Node> S;
    S.push(n);
    while(parent(S.top(), T) != parent(m, T)) 
    {
        S.push(parent(S.top(), T));
    }
    while(!S.empty())
    {
        std::cout << label(S.top(), T) << ' ';
        S.pop();
    }
}
int countPathTo(Node n, Node m, Tree T)
{
    int count = 0;
    std::stack<Node> S;
    S.push(n);
    while(S.top() != m) 
    {
        S.push(parent(S.top(), T));
        count++;
    }
    return count;
}
int height(Tree T)
{
    Node lastone;
    std::queue<Node> Q;
    Q.push(root(T));
    while (!Q.empty()) 
    {
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        lastone = Q.front();
        Q.pop();
    }
    return countPathTo(lastone, root(T), T);
}
int theNumberOfLeaf(Tree T)
{
    std::queue<Node> Q;
    int count = 0;
    Q.push(root(T));
    while (!Q.empty()) 
    {
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        else {
            count++;
        }
        Q.pop();
    }
    return count;
}
int heightOfNode(Node n, Tree T)
{
    Node lastone;
    std::queue<Node> Q;
    Q.push(n);
    while (!Q.empty()) 
    {
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        lastone = Q.front();
        Q.pop();
    }
    return countPathTo(lastone, n, T);
}
bool isSibling(Node n, Node m, Tree T)
{
    if (parent(n, T) == parent(m, T)) return true;
    return false;
}
bool isAncestor(Node n, Node m, Tree T)
{
    Node i = m;
    while (parent(i, T) != NIL)
    {
        if (parent(i, T) == n) return true;
        i = parent(i, T);
    }
    return false;
}
int sonsOfNode(Node n, Tree T)
{
    int count = 0;
    if (leftMostChild(n, T) != NIL)
    {
        count++;
        Node i = leftMostChild(n, T);
        while(rightSibling(i, T) != NIL)
        {
            i = rightSibling(i, T);
            count++;
        }
    }
    return count;
}
int degreeOfATree(Tree T)
{
    int max = 0;
    std::queue<Node> Q;
    Q.push(root(T));
    while (!Q.empty()) 
    {
        if (sonsOfNode(Q.front(), T) > max) max = sonsOfNode(Q.front(), T);
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
    return max;
}
int oneChildParent(Tree T)
{
    int count = 0;
    std::queue<Node> Q;
    Q.push(root(T));
    while (!Q.empty()) 
    {
        if (sonsOfNode(Q.front(), T) == 1) count++;
        if (leftMostChild(Q.front(), T) != NIL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NIL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
    return count;
}