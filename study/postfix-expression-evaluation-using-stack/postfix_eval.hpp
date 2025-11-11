#include "../utils/stack.hpp"
#include <string>
#include <cmath>
#include <cctype>

#ifndef POSFIX
#define POSFIX

class PostfixEval{
    private:
        bool isOperator(char c){
            return (
                c == '+' ||
                c == '-' ||
                c == '*' ||
                c == '/' ||
                c == '^'
            );
        }

        float calculate(float op1, float op2, char op){
            if (op == '+') return op1 + op2;
            else if (op == '-') return op1 - op2;
            else if (op == '*') return op1 * op2;
            else if (op == '/') return op1 / op2;
            else if (op == '^') return pow(op1, op2);
            else return 0;
        }

    public:

        float evaluate(string s){
            // complete the logic here
            Stack ss;
            int i=0;
            while (i<s.size()) {
                if (isspace(s[i])) {
                    i++;
                    continue;
                }
                if (isOperator(s[i])) {
                    float op2 = ss.peek(); ss.pop();
                    float op1 = ss.peek(); ss.pop();
                    float res = calculate(op1, op2, s[i]);
                    ss.push(res);
                    i++;
                } else {
                    int j=i;
                    while (j<s.size()&&(isdigit(s[j])||s[j]=='.')) j++;
                    float val = stof(s.substr(i, j-i));
                    ss.push(val);
                    i=j;
                }
            }
            return ss.peek();
        }
};

#endif
