#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    stack <char> operators;
    stack <int> operands;
    int digit = 0;
    for(char c : str){
        cout << c << '\n';
        if(isdigit(c)){
            int operand = 0;
            if(digit == 0){
                operand = c - '0';
                digit++;
            }else{
                operand = operands.top() * 10 + c - '0';
                operands.pop();
            }
            operands.push(operand);
        }else{
            digit = 0;
            if(c == '+' || c == '-'){
                while(!operators.empty() && operators.top() != '('){
                    int op1 = operands.top();
                    operands.pop();
                    int op2 = operands.top();
                    operands.pop();
                    if(c == '+') operands.push(op1 + op2);
                    else operands.push(op1 - op2);
                }
            }
            else if(c == '(') operators.push(c);
            else if(c == ')'){
                while(operators.top() != '('){
                    char cp = operators.top();
                    operators.pop();
                    int op1 = operands.top();
                    operands.pop();
                    int op2 = operands.top();
                    operands.pop();
                    if(cp == '+') operands.push(op1 + op2);
                    else operands.push(op1 - op2);
                }
        }  
        }}
    cout << operands.top() << '\n';
}