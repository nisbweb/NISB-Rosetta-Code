#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    char *s;
    int top;
};
void initstack(struct stack *p){
    p->top=-1;
    p->s=(char *)malloc(128*sizeof(char *));
}
void push(struct stack *p,char item){
       p->s[++p->top]=item;
}
char pop(struct stack *p){
    char k=p->s[p->top--];
    return k;
    
}
void balancedornot(struct stack p,char *par){
    int i;
    initstack(&p);
    for(i=0;par[i]!='\0';i++){
        if((par[i]==')' && p.top==-1)||(par[i]==']' && p.top==-1)||(par[i]=='}' && p.top==-1)){
            printf("No\n");
            return;
        }
        else if(par[i]=='(' || par[i]=='[' || par[i]=='{')
        push(&p,par[i]);
        else if(par[i]==')' || par[i]==']' || par[i]=='}'){
            if((par[i]==')'&& p.s[p.top]=='(')||(par[i]==']'&&p.s[p.top]=='[')||(par[i]=='}'&&p.s[p.top]=='{'))
            pop(&p);
            else
            push(&p,par[i]);
        }
    }
    if(p.top==-1)
    printf("Yes\n");
    else
    printf("No\n");
}
int main(){
    int n;
    scanf("%d\n",&n);
    char par[50];
    struct stack p;
    while(n--){
        scanf("%s\n",par);
        balancedornot(p,par);
    }
    return 0;
    
}