#include "atreelib.h"
#include <fstream>
#include <sstream>

using std::cout;
using std::endl;
using std::string;

void readTree(Tree *T){
    MakeNull_Tree(T);
    std::ifstream myfile("tree.txt");
    char ch;
    int i = 0;

    if (myfile.is_open()) {
        //read each character
        while(myfile.peek() != '\n')
        {
            myfile.get(ch);
            if (ch != ' ')
            {
                *(T->Data + i) = ch;
                i++;
            }
        }
        myfile.get(ch);
        i = 0;
        //read each integer
        while(myfile.peek() != '\n')
        {
            myfile >> *(T->Parent + i);
            i++;
        }
        T->MaxNode = i;
        myfile.close();
    }
    else std::cout << "Unable to open file";
/*
    int node;
    printf("Nhap so node: "); scanf("%d", &node);
    T->MaxNode = node;
    for (int i = 0; i < node; i++) {
        fflush(stdin);
        printf("Node: "); scanf("%c", &T->Data[i]);
        printf("Parent of the Node: "); scanf("%d", &T->Parent[i]);
    }*/
}

int main(int argc, char *argv[]){
	Tree T;
	readTree(&T);
	PreOrder(0,T);
    cout << endl;
	InOrder(0,T);
    cout << endl;
	PostOrder(0,T);
}