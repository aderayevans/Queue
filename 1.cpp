#include <iostream>
#include "atreelib.h"
#include <fstream>
#include <queue>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void set_Root(DataType data, Tree &T)
{
    T.Data[0] = data;
    T.Parent[0] = NIL;
}
void set_Node(Node index, DataType data, Node parent, Tree &T)
{
    T.Data[index] = data;
    T.Parent[index] = parent;
}
Node input_parent(int index, Tree T)
{
    DataType dataOfParent;
    cout << "\tParent's Data: "; cin >> dataOfParent;
    for (int i = 0; i < T.MaxNode; i++)
    {
        if (T.Data[i] == dataOfParent)
        {
            return i;
        }
    }
    return NIL;
}
void input(Tree &T)
{
    DataType data;
    Node parent;
    makeNull_Tree(T);
    while (true)
    {
        cout << "How much leaves and nodes in the tree? "; 
        cin >> T.MaxNode;
        if (T.MaxNode <= MAXLENGTH) break;
        else
        {
            cout << "Error: Out of nodes number!!!";
        }
    }
    cout << "First, input root information: " << endl;
    cout << "Root's Data: "; cin >> data;
    set_Root(data, T);
    for (int i = 1; i < T.MaxNode; i++)
    {
        cout << "Node <" << i << ">:" << endl;
        cout << "\tData: "; cin >> data;
        while (true)
        {
            parent = input_parent(i, T);
            if (parent != NIL) break;
            else
            {
                {
                    cout << "Error: Parent not found!!!";
                }
            }
            
        }
        set_Node(i, data, parent, T);
    }
}
void readTree(string link_file, Tree &T){
    makeNull_Tree(T);
    std::ifstream myfile(link_file);
    char ch;
    int i = 0;

    if (myfile.is_open()) {
        //read each character
        myfile >> T.MaxNode;
        myfile.get(ch);
        while(myfile.peek() != '\n')
        {
            myfile.get(ch);
            if (ch != ' ')
            {
                T.Data[i] = ch;
                i++;
            }
        }
        myfile.get(ch);
        i = 0;
        //read each integer
        while(myfile.peek() != '\n' and !myfile.eof())
        {
            myfile >> T.Parent[i];
            i++;
        }
        //T->MaxNode = i;
        myfile.close();
    }
    else std::cout << "Unable to open file";
}

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
    Tree the_tree;
    //input(the_tree);
    readTree("tree2.txt", the_tree);
    preOrder(root(the_tree), the_tree); cout << endl;
    inOrder(root(the_tree), the_tree); cout << endl;
    postOrder(root(the_tree), the_tree); cout << endl;
    levelOrder(root(the_tree), the_tree); cout << endl;
    cout << "The number of leaves: " << theNumberOfLeaf(the_tree) << endl;
    cout << "Path to Node 6: "; showPathTo(6, root(the_tree), the_tree); cout << endl;
    cout << "Height of Node 2: " << heightOfNode(2, the_tree) << endl;
    cout << "Most children of Node E: " << sonsOfNode(3, the_tree) << endl;
    cout << "Degree of A Tree: " << degreeOfATree(the_tree) << endl;
    cout << "Height: " << height(the_tree) << endl;
    cout << "The parent got one child only: " << oneChildParent(the_tree) << endl;
    checkSibling(6, 5, the_tree);
    checkSibling(4, 6, the_tree);
    checkAncestor(2, 9, the_tree);
    checkAncestor(3, 5, the_tree);
}