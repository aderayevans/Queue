#include <iostream>
#include <stack>
#include <queue>

typedef char DataType;
//const int null = -1;
struct Cell {
    DataType data;
    Cell* par;
    Cell* lmc;
    Cell* rsl;
};
typedef Cell* Node;
typedef Node Tree;
//declarations
void create(Node &node, DataType val, Node par, Tree lmc, Tree rsl);
void makeNull_Tree (Tree &T);
bool emptyTree(Tree T);
Node parent(Node n, Tree T);
DataType label(Node n,Tree T);
Node Root(Tree T);
Node leftMostChild(Node n, Tree T);
Node rightSibling(Node n,Tree T);
void preOrder(Node n,Tree T);
void inOrder(Node n, Tree T);
void postOrder(Node n,Tree T);
void levelOrder(Node n, Tree T);
void showPathTo(Node n, Node m, Tree T);
int countPathTo(Node n, Node m, Tree T);
int height(Tree T);
int theNumberOfLeaf(Tree T);
int heightOfNode(Node n, Tree T);
bool isSibling(Node n, Node m);
bool isAncestor(Node n, Node m);
int sonsOfNode(Node n, Tree T);
int degreeOfATree(Tree T);
//definitions
void create(Node &node, DataType val, Node par, Node lmc, Node rsl) {
    node->data = val;
    node->par = par;
    node->lmc = lmc;
    node->rsl = rsl;
}
void makeNull_Tree (Tree &T) {
    T = new Cell();
}
bool emptyTree(Tree T) {
    return T == NULL;
}
Node parent(Node n, Tree T) {
    return n->par;
}
DataType label(Node n,Tree T) {
    return n->data;
}
Node root(Tree T) {
    return T;
}
Node leftMostChild(Node n, Tree T) {
    return n->lmc;
}
Node rightSibling(Node n,Tree T) {
    return n->rsl;
}
void preOrder(Node n,Tree T) 
{
    if (n != NULL) 
    {
        std::stack<Node> S; //buffer, parents
        Node buf = n;
        while (true)
        {
            std::cout << label(buf, T) << ' ';
            if (leftMostChild(buf, T) != NULL) 
            {
                S.push(buf);
                buf = leftMostChild(S.top(), T);
            }
            else if (rightSibling(buf, T) != NULL)
            {
                buf = rightSibling(buf, T);
            }
            else
            {   
                while(true)
                {
                    if (S.empty()) break;
                    else if (rightSibling(S.top(), T) != NULL)
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
/*void preOrder(Node n,Tree T) 
{
    if(n != NULL)
    {
        std::cout << label(n, T) << ' ';
        Node i = leftMostChild(n, T);
        while(i != NULL)
        {
            preOrder(i, T);
            i = rightSibling(i, T);
        }
    }
}*/
void inOrder(Node n, Tree T) 
{
    if (n != NULL) 
    {
        Node i = leftMostChild(n, T);
        if (i != NULL) 
        {
            inOrder(i, T);
        }
        std::cout << label(n, T) << ' ';
        if (i != NULL) 
        {
            i = rightSibling(i, T);
        }
        while (i != NULL) 
        {
            inOrder(i, T);
            i = rightSibling(i, T);
        }
    }
}
void postOrder(Node n,Tree T) 
{
    if (n != NULL)
    {
        Node i = leftMostChild(n, T);
        while (i != NULL) 
        {
            postOrder(i, T);
            i = rightSibling(i, T);
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
}
void showPathTo(Node n, Node m, Tree T)
{
    std::stack<Node> S;
    S.push(n);
    while(parent(S.top(), T) != parent(m, T)) {
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
    while(S.top() != m) {
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
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
    while (parent(i, T) != NULL)
    {
        if (parent(i, T) == n) return true;
        i = parent(i, T);
    }
    return false;
}
int sonsOfNode(Node n, Tree T)
{
    int count = 0;
    if (leftMostChild(n, T) != NULL)
    {
        count++;
        Node i = leftMostChild(n, T);
        while(rightSibling(i, T) != NULL)
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
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
        if (leftMostChild(Q.front(), T) != NULL)
        {
            Node child = leftMostChild(Q.front(), T);
            Q.push(child);
            while (rightSibling(child, T) != NULL) 
            {
                child = rightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
    return count;
}