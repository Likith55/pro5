/*Evaluation of postfix expression*/
#include<stdio.h>
#include<math.h>
#include<ctype.h>
float stack[50];
int top=-1;
void push(float n)
{
stack[++top]=n;
}
/*pop()*/
float pop()
{
return(stack[top--]);
}

/*evaluate()*/
float eval(char postfix[])
{

float op1,op2,res;
char ch;
int i=0;
while((ch=postfix[i])!='\0')
{
if(isdigit(ch))
push(ch-'0');

else
{

op2=pop();
op1=pop();
switch(ch)
{

case '$':
case '^': res=pow(op1,op2);

break;
case '*': res=op1*op2;
break;
case '/': res=op1/op2;
break;
case '+': res=op1+op2;
break;
case '-': res=op1-op2;
break;
}
push(res);
}
i++;
}
return(pop());

}
int main()
{

char postfix[50];
float res;
printf("Enter postfix expression\n");
scanf("%s",postfix);
res=eval(postfix);
printf("Result=%g\n",res);

}


Output:
1.	Enter postfix expression
               23+43-*
              Result=5
2.	Enter postfix expression
              623+-382/+*2$3+
             Result=52
