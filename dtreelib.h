#include <iostream>
#include <stack>

typedef char DataType;
//const int null = -1;
struct Cell {
    DataType data;
    Cell* lmc;
    Cell* rsl;
};
typedef Cell* Node;
typedef Node Tree;
//declarations
Node create(DataType val, Tree lmc, Tree rsl);
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
//definitions
Node create(DataType val, Tree lmc, Tree rsl) {
    Node n = new Cell();
    n->data = val;
    n->lmc = lmc;
    n->rsl = rsl;
    return n;
}
void makeNull_Tree (Tree &T) {
    T = NULL;
}
bool emptyTree(Tree T) {
    return T == NULL;
}
/*Node parent(Node n, Tree T) {

}*/
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
    if (!emptyTree(T)) 
    {
        std::stack<Node> par; //buffer, parents
        Node buf = n;
        while (true)
        {
            std::cout << label(buf, T) << ' ';
            if (buf->lmc != NULL) 
            {
                par.push(buf);
                buf = par.top()->lmc;
            }
            else if (buf->rsl != NULL)
            {
                buf = buf->rsl;
            }
            else
            {   
                while(true)
                {
                    if (par.empty()) break;
                    else if (par.top()->rsl != NULL)
                    {
                        buf = par.top()->rsl;
                        par.pop();
                        break;
                    }
                    else
                        par.pop();
                }
                if (par.empty())
                    break;
            }
        }
    }
}
/*void preOrder(Node n,Tree T) 
{
    if(!emptyTree(T))
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
    Node i = leftMostChild(n, T);
    while (i != NULL) 
    {
        postOrder(i, T);
        i = rightSibling(i, T);
    }
    std::cout << label(n, T) << ' ';
}