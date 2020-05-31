#include <iostream>
#include "atreelib.h"
#include <queue>
#include <stack>
#include "HandleTestcase.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void LevelOrder(TNode n, Tree T)
{
    std::queue<TNode> Q;
    Q.push(n);
    while (!Q.empty()) 
    {
        std::cout << Label_Node(Q.front(), T) << ' ';
        if (LeftMostChild(Q.front(), T) != NIL)
        {
            TNode child = LeftMostChild(Q.front(), T);
            Q.push(child);
            while (RightSibling(child, T) != NIL) 
            {
                child = RightSibling(child, T);
                Q.push(child);
            }
        }
        Q.pop();
    }
}

int solve(char arithmetic_op, int first, int second)
{
    if (arithmetic_op == '+')
    {
        return first + second;
    }
    else if (arithmetic_op == '-')
    {
        return first - second;
    }
    else if (arithmetic_op == '*')
    {
        return first * second;
    }
    else
    {
        return first / second;
    }
}
int presolve(string str)
{
    std::stack<char> numbers_and_arithmetic_operations;
    std::stack<int> counts_buffer;
    int count = 0;
    int second_num = 0;
    int first_num = 0;
    char arithmetic_op;
    int index = 0;
    char char_val;
    while (true) 
    {
        if ((count >= 3))
        {
            second_num = numbers_and_arithmetic_operations.top()  - '0';
            numbers_and_arithmetic_operations.pop();
            first_num = numbers_and_arithmetic_operations.top()  - '0';
            numbers_and_arithmetic_operations.pop();
            arithmetic_op = numbers_and_arithmetic_operations.top();
            numbers_and_arithmetic_operations.pop();
            numbers_and_arithmetic_operations.push(solve(arithmetic_op, first_num, second_num) + '0');
            if (!counts_buffer.empty())
            {
                count = counts_buffer.top() + 1;
                counts_buffer.pop();
            }
            else count = 0;
        }
        else if (index >= str.length())
        {
            break;
        }
        else
        {
            char_val = str[index];
            index++;
            if ((char_val >= '0') && (char_val <= '9'))
            { 
                numbers_and_arithmetic_operations.push(char_val);
                count++;
            }
            else if ((char_val == '*') || (char_val == '+') || (char_val == '-') || (char_val == '/'))
            {
                numbers_and_arithmetic_operations.push(char_val);
                if (count != 0)
                    counts_buffer.push(count);
                count = 1;
            }
            else cout << "Value Error";
        }
    }
    return numbers_and_arithmetic_operations.top() - '0';
}

int postsolve(string str)
{
    std::stack<int> number;
    std::stack<char> arithmetic_operations;
    int count = 0;
    int second_num = 0;
    int result = 0;
    int index = 0;
    char char_val;
    while (true) 
    {
        if ((count >= 2) && !arithmetic_operations.empty())
        {
            second_num = number.top();
            number.pop();
            result = solve(arithmetic_operations.top(), number.top(), second_num);
            number.pop();
            arithmetic_operations.pop();
            number.push(result);
            count -= 1;
        }
        else if (index >= str.length())
        {
            break;
        }
        else
        {
            char_val = str[index];
            index++;
            if ((char_val >= '0') && (char_val <= '9'))
            { 
                number.push(char_val - '0');
                count++;
            }
            else if ((char_val == '*') || (char_val == '+') || (char_val == '-') || (char_val == '/'))
            {
                arithmetic_operations.push(char_val);
            }
            else cout << "Value Error";
        }
    }
    return number.top();
}

int main() {
    char ch;
    std::vector<std::string> vt;
    while(true) {
        std::cout << "Press any key to continue (except '0' meaning quit): ";
        std::cin >> ch;
        if (ch == '0') break;

        Testcase pretc = Testcase("presolve.txt");
        Testcase posttc = Testcase("postsolve.txt");
        //pretc.create();
        //posttc.create();
        pretc.read();
        posttc.read();
        for (std::string str : pretc.get()) {
            cout << presolve(str) << endl;
        }
        for (std::string str : posttc.get()) {
            cout << postsolve(str) << endl;
        }
    }
}