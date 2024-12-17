#include <stdio.h>

char infix[32];
int infixpos = 0;
char postfix[32];
int postfixpos = 0;
char stack[16];
int top = -1;

void push(char symb){
    top++;
    stack[top] = symb;
}
char pop(){
    int temp = stack[top];
    top--;
    return temp;
}

int precedence(char symb){
    switch(symb){
        case '%':
        case '*':
        case '/':
        return 2;
        break;
        case '+':
        case '-':
        return 1;
        break;
        default:
        return 0;
    }
}

void evaluate(){
    for(int i=0; infix[i]!='\0'; i++){
        switch(infix[i]){
            case '(':
            push('(');
            break;
            case ')':
            while(stack[top]!='('){
                postfix[postfixpos]=pop();
                postfixpos++;
            }
            pop();
            break;
            case '*':
            case '/':
            case '%':
            case '+':
            case '-':
            if (precedence(stack[top])>=precedence(infix[i])){
                while(precedence(stack[top]>=precedence(infix[i]))){
                    postfix[postfixpos]=infix[i];
                    postfixpos++;
                }
            }
            else{
                push(infix[i]);
            }
            break;
            default:
            postfix[postfixpos]=infix[i];
            postfixpos++;
            break;
        }
    }
    while(top>=0){
        postfix[postfixpos]=pop();
        postfixpos++;
    }
}

int main(){
    scanf("%s", infix);
    evaluate();
    printf("%s", postfix);
    return 0;
}