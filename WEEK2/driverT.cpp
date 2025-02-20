#include <iostream>
#include <cctype>
#include <unordered_map>
#include "stackT.h"

using namespace std;
bool isValidExpression(const string& expression) {
    Stack<char> s;
    unordered_map<char, char> matching = { {')', '('}, {'}', '{'}, {']', '['} };

    for (char ch : expression) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.Push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.IsEmpty() || s.Top() != matching[ch]) {
                return false;
            }
            char temp;
            s.Pop(temp);
        }
    }
    return s.IsEmpty();
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& expression) {
    Stack<char> s;
    string output;

    for (char ch : expression) {
        if (isalnum(ch)) {
            output += ch;
        }
        else if (ch == '(') {
            s.Push(ch);
        }
        else if (ch == ')') {
            while (!s.IsEmpty() && s.Top() != '(') {
                char temp;
                s.Pop(temp);
                output += temp;
            }
            char temp;
            s.Pop(temp);
        }
        else {
            while (!s.IsEmpty() && precedence(s.Top()) >= precedence(ch)) {
                char temp;
                s.Pop(temp);
                output += temp;
            }
            s.Push(ch);
        }
    }

    while (!s.IsEmpty()) {
        char temp;
        s.Pop(temp);
        output += temp;
    }

    return output;
}
int evaluatePostfix(const string& expression) {
    Stack<int> s;

    for (char ch : expression) {
        if (isdigit(ch)) {
            s.Push(ch - '0');
        }
        else {
            int b, a;
            s.Pop(b);
            s.Pop(a);
            switch (ch) {
            case '+': s.Push(a + b); break;
            case '-': s.Push(a - b); break;
            case '*': s.Push(a * b); break;
            case '/': s.Push(a / b); break;
            }
        }
    }

    int result;
    s.Pop(result);
    return result;
}

int main() {
    cout << "A) Valid Parenthesis Checking" << endl;
    string testExpressions[] = { "(a+b)", "{[()()]}", "((a+b)*c", "{[(])}" };
    for (const string& expr : testExpressions) {
        cout << expr << " -> " << (isValidExpression(expr) ? "Valid" : "Invalid") << endl;
    }

    cout << "\nB) Infix to Postfix Conversion" << endl;
    string infixExpressions[] = { "A+B*C", "(A+B)*C", "A*B+C*D" };
    for (const string& expr : infixExpressions) {
        cout << expr << " -> " << infixToPostfix(expr) << endl;
    }

    cout << "\nC) Postfix Evaluation" << endl;
    string postfixExpressions[] = { "23*5+", "345+*6-" };
    for (const string& expr : postfixExpressions) {
        cout << expr << " -> " << evaluatePostfix(expr) << endl;
    }

    Stack<int> IntStack;
    Stack<float> FloatStack;
    int data;
    float val;

    IntStack.Push(35);
    FloatStack.Push(3.5);

    IntStack.Pop(data);
    cout << "\nPopped item from IntStack: " << data << endl;

    FloatStack.Pop(val);
    cout << "Popped item from FloatStack: " << val << endl;

    return 0;
}

