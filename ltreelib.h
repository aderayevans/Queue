#include <iostream>

const int Maxlength = 256;
typedef int DataType;
const int null = -1;
struct Node {
    DataType val;
    Tail* tail;
};
struct Tree {
    Node Elements[Maxlength];
    int MaxNode;
};
struct Tail {
    int index;
    Tail* Next;
};

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
void makeNull_Tree (Tree &T) {
    T.MaxNode = 0;
}
bool emptyTree(Tree T) {
    return T.MaxNode == 0;
}
Node parent(Node n, Tree T);
DataType label(Node n,Tree T) {
    return n.val;
}
Node Root(Tree T) {
    return T.Elements[0];
}
Node leftMostChild(Node n, Tree T) {
    return T.Elements[n.tail->index];
}
Node rightSibling(Node n,Tree T) {
    for (int i = 0; i < T.MaxNode; i++) {
        Tail* tail = T.Elements[i].tail;
        while(tail != NULL) {
            if (T.Elements[tail->index].val == n.val) {
                if (tail->Next == NULL) std::cout << "there is no right sibling\n";
                return T.Elements[tail->Next->index];
            }
            tail = tail->Next;
        }
    }
}
void preOrder(Node n,Tree T);
void inOrder(Node n, Tree T);
void postOrder(Node n,Tree T);