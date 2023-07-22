#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    string str;
    getline(cin,str);
    stack <char> operators;
    stack <int> operands;
    int digit = 0;
    for(int i = str.length(); i >= 0; i--){
        (i==str.length()) ? --i : i;
        char c = str[i];
        if(isdigit(c)){
            int operand = 0;
            if(digit == 0){
                operand = c - '0';
                ++digit;
            }else{
                operand = operands.top() + (c - '0')*(pow(10,digit)); 
                operands.pop();
                ++digit;
            }
            operands.push(operand);
        }else{
            digit = 0;
            if(c == '+' || c == '-' || c == '*' || c=='/') operators.push(c);
            else if(c == ')') operators.push(c);
            else if(c == '('){
                while(operators.top() != ')'){
                    char cp = operators.top();
                    operators.pop();
                    int op1 = operands.top();
                    operands.pop();
                    int op2 = operands.top();
                    operands.pop();
                    switch(cp){
                        case '+':
                            if(!operators.empty() &&(operators.top() == '*' || operators.top() == '/')){
                                char cp2 = operators.top();
                                operators.pop();
                                operators.push(cp);
                                operators.push(cp2);
                                int op3 = operands.top();
                                operands.pop();
                                operands.push(op1);
                                operands.push(op3);
                                operands.push(op2);
                            }
                            else operands.push(op1 + op2);
                            break;
                        case '-':
                            if(!operators.empty() &&(operators.top() == '*' || operators.top() == '/')){
                                char cp2 = operators.top();
                                operators.pop();
                                operators.push(cp);
                                operators.push(cp2);
                                int op3 = operands.top();
                                operands.pop();
                                operands.push(op1);
                                operands.push(op3);
                                operands.push(op2);
                            }
                            else operands.push(op1 - op2);
                            break;
                        case '*':
                            operands.push(op1 * op2);
                            break;
                        case '/':
                            operands.push(op1 / op2);
                            break;
                        default:
                            break;
                    }
                }
                operators.pop();
        }  
        }}
        while(!operators.empty()){
            char cp = operators.top();
            operators.pop();
            int op1 = operands.top();
            operands.pop();
            int op2 = operands.top();
            operands.pop();
            switch(cp){
                case '+':
                    if(!operators.empty() &&(operators.top() == '*' || operators.top() == '/')){
                        char cp2 = operators.top();
                        operators.pop();
                        operators.push(cp);
                        operators.push(cp2);
                        int op3 = operands.top();
                        operands.pop();
                        operands.push(op1);
                        operands.push(op3);
                        operands.push(op2);
                    }
                    else operands.push(op1 + op2);
                    break;
                case '-':
                    if(!operators.empty() &&(operators.top() == '*' || operators.top() == '/')){
                        char cp2 = operators.top();
                        operators.pop();
                        operators.push(cp);
                        operators.push(cp2);
                        int op3 = operands.top();
                        operands.pop();
                        operands.push(op1);
                        operands.push(op3);
                        operands.push(op2);
                    }
                    else operands.push(op1 - op2);
                    break;
                case '*':
                    operands.push(op1 * op2);
                    break;
                case '/':
                    operands.push(op1 / op2);
                    break;
                default:
                    break;
            }
        }
    cout << operands.top() << '\n';
}