#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define max 100
int stack[max];
int top=-1;
void push(int a){
    if(top==max-1){
        printf("Stack is full");
        return;
    }
    else{
        top++;
        stack[top]=a;
    }
}
int pop(){
    int ch;
    if (top == -1) {
        printf("\n Stack Underflow\n ");
    }
    else{
        ch=stack[top];
        top--;
        return ch;
    }
}
int main(){
    char exp[max],ele;
    int ans;
    printf ("Enter the expression : ");
    gets(exp);
    printf("Entered expression is : %s\n",exp);
    for(int i=0;i<strlen(exp);i++){
        ele=exp[i];
        if(isdigit(ele)){
            push(ele-'0');
        }
        else{
            int num1=pop();
            int num2=pop();
            switch(ele){
                case '^' : ans=pow(num2,num1);
                break;
                case '/': ans=num2/num1;
                break;
                case '+': ans=num2+num1;
                break;
                case '-': ans=num2-num1;
                break;
                case '*': ans=num2*num1;
                break;
            }
            push(ans);
        }
    }
    printf("Answer of the expression is  %d ",ans);
    return 0;
}