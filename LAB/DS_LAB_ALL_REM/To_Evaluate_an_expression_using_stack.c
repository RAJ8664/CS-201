#include <stdio.h>
#include <stdlib.h>

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int evaluate(char tokens[]) {
    int i;
    
    int values[100];
    int values_top = -1;

    char ops[100];
    int ops_top = -1;

    for (i = 0; tokens[i] != '\0'; i++) {
        
        if (tokens[i] == ' ')
            continue;

        else if (tokens[i] == '(') {
            ops[++ops_top] = tokens[i];
        }

        else if (isdigit(tokens[i])) {
            int val = 0;

            while (isdigit(tokens[i])) {
                val = (val * 10) + (tokens[i] - '0');
                i++;
            }

            values[++values_top] = val;
            i--;
        }

        else if (tokens[i] == ')') {
            while (ops_top != -1 && ops[ops_top] != '(') {
                int val2 = values[values_top--];
                int val1 = values[values_top--];
                char op = ops[ops_top--];
                values[++values_top] = applyOp(val1, val2, op);
            }

            if (ops_top != -1)
                ops_top--;
        }

        else {
        
            while (ops_top != -1 && precedence(ops[ops_top]) >= precedence(tokens[i])) {
                int val2 = values[values_top--];
                int val1 = values[values_top--];
                char op = ops[ops_top--];
                values[++values_top] = applyOp(val1, val2, op);
            }

            ops[++ops_top] = tokens[i];
        }
    }

    while (ops_top != -1) {
        int val2 = values[values_top--];
        int val1 = values[values_top--];
        char op = ops[ops_top--];
        values[++values_top] = applyOp(val1, val2, op);
    }

    return values[values_top];
}

int main() {
    printf("%d\n", evaluate("10 + 2 * 6"));
    printf("%d\n", evaluate("100 * 2 + 12"));
    printf("%d\n", evaluate("100 * ( 2 + 12 )"));
    printf("%d\n", evaluate("100 * ( 2 + 12 ) / 14"));
    return 0;
}
