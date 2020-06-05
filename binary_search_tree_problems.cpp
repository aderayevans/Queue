#include <iostream>
#include "bstlib.h"
#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using std::cout;
using std::endl;
using std::cin;
using std::string;

void readFile(Tree &T)
{
	MakeNullTree(&T);
	std::ifstream ifs("bsttext.txt");
	char ch;
	int temp;
    if (ifs.is_open()) {
        while(ifs.peek() != '\n')
		{
            ifs >> temp;
            InsertNode(temp, &T);
        }
        ifs.close();
        }
    else 
	{
        std::cout << "Unable to read file";
    }
}
KeyType getKey(Tree n)
{
	if (n != NULL) return n->Key;
	else return -1;
}
void levelOrder(Tree T)
{
    std::queue<Tree> Q;
    Q.push(T);
    while (!Q.empty()) 
    {
        std::cout << getKey(Q.front()) << ' ';
        if (LeftChild(Q.front()) != NULL)
        {
            TNode *child = LeftChild(Q.front());
            Q.push(child);
        }
        if (RightChild(Q.front()) != NULL)
        {
        	TNode *child = RightChild(Q.front());
            Q.push(child);
        }
        Q.pop();
    }
}
int theNumberOfLeaf(Tree T)
{
    std::queue<TNode*> Q;
    int count = 0;
    int check;
    Q.push(T);
    while (!Q.empty()) 
    {
        check = 0;
        if (LeftChild(Q.front()) != NULL)
        {
            TNode *child = LeftChild(Q.front());
            Q.push(child);
        }
        else check++;
        if (RightChild(Q.front()) != NULL)
        {
        	TNode *child = RightChild(Q.front());
            Q.push(child);
        }
        else check++;
        if (check == 2) {
            cout << "Leaf's key: " << getKey(Q.front()) << endl;
            count++;
        }
        Q.pop();
    }
    return count;
}
TNode* getTNode(KeyType key, Tree T)
{
	std::queue<Tree> Q;
    Q.push(T);
    while (!Q.empty()) 
    {
        if (getKey(Q.front()) == key) return Q.front();
        if (LeftChild(Q.front()) != NULL)
        {
            TNode *child = LeftChild(Q.front());
            Q.push(child);
        }
        if (RightChild(Q.front()) != NULL)
        {
        	TNode *child = RightChild(Q.front());
            Q.push(child);
        }
        Q.pop();
    }
    return NULL;
}
TNode* parent(TNode *n, Tree T)
{
	std::queue<Tree> Q;
    Q.push(T);
    while (!Q.empty()) 
    {
        if (LeftChild(Q.front()) != NULL)
        {
            TNode *child = LeftChild(Q.front());
            if (n == child) return Q.front();
            Q.push(child);
        }
        if (RightChild(Q.front()) != NULL)
        {
        	TNode *child = RightChild(Q.front());
            if (n == child) return Q.front();
            Q.push(child);
        }
        Q.pop();
    }
    return NULL;
}
int levelOfNode(TNode *n, TNode *m, Tree T)
{
	int count = 0;
    std::stack<TNode*> S;
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
    TNode* lastone;
    std::queue<TNode*> Q;
    Q.push(T);
    while (!Q.empty()) 
    {
        if (LeftChild(Q.front()) != NULL)
        {
            TNode *child = LeftChild(Q.front());
            Q.push(child);
        }
        if (RightChild(Q.front()) != NULL)
        {
        	TNode *child = RightChild(Q.front());
            Q.push(child);
        }
        lastone = Q.front();
        Q.pop();
    }
    return levelOfNode(lastone, T, T);
}
void showPathTo(TNode* n, TNode* m, Tree T)
{
    std::stack<TNode*> S;
    S.push(n);
    while(parent(S.top(), T) != parent(m, T)) 
    {
        S.push(parent(S.top(), T));
    }
    while(!S.empty())
    {
        std::cout << getKey(S.top()) << ' ';
        S.pop();
    }
}
bool isCompleted(Tree T)
{
	if (T != NULL)
	{
		std::queue<Tree> Q;
        Q.push(T);
        int check;
        int currentLevel;
        while (!Q.empty()) 
        {
            check = 0;
            if (LeftChild(Q.front()) != NULL)
            {
	            TNode *child = LeftChild(Q.front());
                Q.push(child);
            }
            else{
                check++;
            }
            if (RightChild(Q.front()) != NULL)
            {
	        	TNode *child = RightChild(Q.front());
                Q.push(child);
            }
            else
            {
                check++;
            }
            if (check == 1) return false;
            else if (check == 2) {
                currentLevel = levelOfNode(Q.front(), T, T);
                if (currentLevel != height(T)) return false;
            }
            Q.pop();
        }
        return true;
	}
	else return false;
}
int main()
{
	Tree T;
	readFile(T);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;
	PosOrder(T); 
	cout << endl;
	levelOrder(T);
	cout << endl;
	cout << "Number of leaves: " << theNumberOfLeaf(T) << endl;
	KeyType key = 42;
	cout << "Level of node " << key << ": " << levelOfNode(getTNode(key, T), T, T) << endl;
	cout << "Height: " << height(T) << endl;
	key = 42;
	cout << "Path to " << key << ": ";
	showPathTo(getTNode(key, T), T, T); cout << endl;
	cout << "The " << key << " node is " << levelOfNode(getTNode(key, T), T, T) << " away from the root" << endl;
	cout << "Is this Tree completed? ";
	if (isCompleted(T)) cout << "Yes" << endl;
	else cout << "No";
}

