#include <iostream>

using std::string;
using std::cout;
using std::endl;
class Pointer
{
    private: 
        Pointer* son;
        string str;
    public:
        Pointer() 
        {
            son = nullptr;
            str = "Null";
        }
        void setString(string str)
        {
            this->str = str;
        }
        string getString()
        {
            return str;
        }
        void setSon(Pointer* son)
        {
            this->son = son;
        }
        Pointer* getSon()
        {
            return son;
        }
};
void create(Pointer* dad, Pointer* son, string str)
{
    dad->setSon(son);
    dad->setString(str);
}
int main()
{
    Pointer *A = new Pointer();
    Pointer *B = new Pointer();
    Pointer *C = new Pointer();
    cout << B->getString() << endl;
    create(A, B, "A");
    create(B, C, "B");
    create(C, nullptr, "C");
    cout << A->getSon()->getString() << endl;
    cout << B->getSon()->getString() << endl;
}