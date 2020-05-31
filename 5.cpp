#include "dtreelib.h"

using std::cout;
using std::endl;

void checkSibling(Node n, Node m, Tree T)
{
    cout << "Check: Is " << label(n, T) << " sibling of " << label(m, T) << "? ";
    if (isSibling(n, m, T)) cout << "YES" << endl;
    else cout << "NO" << endl;
}
void checkAncestor(Node n, Node m, Tree T)
{
    cout << "Check: Is " << label(n, T) << " ancestor of " << label(m, T) << "? ";
    if (isAncestor(n, m, T)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    Tree A, B, C, D, E, F, G, H, I, J, K, L, M, N;
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
    create(B, 'B', A, E, C);
    create(C,'C', A, G, D);
    create(D,'D', A, I, NULL);
    create(E,'E', B, NULL, F);
    create(F,'F', B, K, NULL);
    create(G,'G', C, NULL, H);
    create(H,'H', C, NULL, J);
    create(I,'I', D, L, NULL);
    create(J,'J', C, NULL, NULL);
    create(K, 'K', F, NULL, NULL);
    create(L, 'L', I, NULL, M);
    create(M, 'M', I, NULL, NULL);
    preOrder(A, A); cout << endl;
    inOrder(A, A); cout << endl;
    postOrder(A, A); cout << endl;
    levelOrder(A, A); cout << endl;
    cout << "The number of leaves: " << theNumberOfLeaf(A) << endl;
    cout << "Path to Node J: "; showPathTo(J, root(A), A); cout << endl;
    cout << "Height of Node E: " << heightOfNode(C, A) << endl;
    cout << "Most children of Node E: " << sonsOfNode(C, A) << endl;
    cout << "Degree of A Tree: " << degreeOfATree(A) << endl;
    cout << "Height: " << height(A) << endl;
    cout << "The parent got one child only: " << oneChildParent(A) << endl;
    checkSibling(M, L, A);
    checkSibling(M, F, A);
    checkAncestor(A, K, A);
    checkAncestor(D, K, A);
}