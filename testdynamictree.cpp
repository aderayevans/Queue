#include "dtreelib.h"

using std::cout;
using std::endl;

int main() {
    Tree H = create('H', NULL, NULL);
    Tree G = create('G', NULL, H);
    Tree F = create('F', NULL, G);
    Tree J = create('J', NULL, NULL);
    Tree I = create('I', NULL, J);
    Tree E = create('E', F, NULL);
    Tree D = create('D', NULL, E);
    Tree C = create('C', I, NULL);
    Tree B = create('B', D, C);
    Tree A = create('A', B, NULL);
    preOrder(A, A);
    cout << endl;
    inOrder(A, A);
    cout << endl;
    postOrder(A, A);
}