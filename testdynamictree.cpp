#include "dtreelib.h"

using std::cout;
using std::endl;

int main() {
    Tree A, B, C, D, E, F, G, H, I, J, K, L, M;
    makeNull_Tree(A);
    makeNull_Tree(B);
    makeNull_Tree(C);
    makeNull_Tree(D);
    makeNull_Tree(E);
    makeNull_Tree(F);
    makeNull_Tree(G);
    makeNull_Tree(H);
    makeNull_Tree(I);
    makeNull_Tree(J);
    makeNull_Tree(K);
    makeNull_Tree(L);
    makeNull_Tree(M);
    create(A, 'A', NULL, B, NULL);
    create(B, 'B', A, D, C);
    create(C,'C', A, F, NULL);
    create(D,'D', B, H, E);
    create(E,'E', B, J, NULL);
    create(F,'F', C, K, G);
    create(G,'G', C, NULL, NULL);
    create(H,'H', D, NULL, I);
    create(I,'I', D, NULL, NULL);
    create(J,'J', E, NULL, NULL);
    create(K, 'K', F, NULL, L);
    create(L, 'L', F, NULL, NULL);
    create(M, 'M', G, NULL, NULL);
    preOrder(A, A);
    cout << endl;
    inOrder(A, A);
    cout << endl;
    postOrder(A, A);
    cout << endl;
    levelOrder(A, A);
    cout << endl;
    showPathTo(J, A);
    cout << endl;
    cout << height(A) << endl;
    cout << theNumberOfLeaf(A) << endl;
    cout << heightOfNode(B, A) << endl;
}