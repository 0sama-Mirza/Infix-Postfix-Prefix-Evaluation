//Write code to evaluate infix, prefix and postfix expression.
#include<math.h>
bool IsOperator(char x){
    if(x=='*'||x=='/'||x=='+'||x=='-'||x=='('||x=='^')
        return 1;
    else
        return 0;
}
int calculate(int a, int b,char oper){
    switch (oper)
    {
    case '+':
        return a+b;    
        break;
    case '-':
        return a-b;
        break;
    case '*':
        return a*b;
        break;
    case '/':
        return a/b;
    case '^':
        return pow(a,b);
        break;
    default:
        break;
    }
    return 0;
}

int prefix_evaluation(string u){
    stack<int>st;
    for(int i=u.length()-1;i>=0;i--){
        if(!IsOperator(u[i])){
            st.insert(u[i]-'0');//When we subtract 0 from a character it is converted into an integer
        }
        else{
            int op1=st.gettop();
            st.del();
            int op2=st.gettop();
            st.del();
            st.insert(calculate(op1,op2,u[i]));
        }
    }
    return st.gettop();
}
int postfix_evaluation(string k){
    stack<int>st;
        for(int i=0;i<k.length();i++){
        if(!IsOperator(k[i])){
            st.insert(k[i]-'0');//When we subtract 0 from a character it is converted into an integer
        }
        else{
            int op2=st.gettop();
            st.del();
            int op1=st.gettop();
            st.del();
            st.insert(calculate(op1,op2,k[i]));
        }
    }
    return st.gettop();
}
// int precedence(char c){
//     if (c == '^')
//         return 3;
//     else if (c == '/' || c == '*')
//         return 2;
//     else if (c == '-' || c == '+')
//         return 1;
//     else
//         return -1; //for paranthesis
// }
int infix_evaluation(string a){
    stack<char>oper;
    stack<int>Number;
    for(int i=0;i<a.length();i++){
        if(!IsOperator(a[i])&&a[i]!=')'){
            Number.insert(a[i]-'0');//When we subtract 0 from a character it is converted into an integer
            // cout<<i<<"-------"<<endl;
            // Number.print();
            // cout<<"---------"<<endl;
            // oper.print();
            // cout<<"---------"<<endl;
            // cout<<"a[i]: "<<a[i]<<endl;
        }
        else if(oper.IsEmpty()){
            // cout<<"Hello +: "<<a[i]<<endl;
            oper.insert(a[i]);
        }
        else if(a[i]=='('){
            oper.insert(a[i]);
            // cout<<"Hello (: "<<a[i]<<endl;
        }
        else if(a[i]==')'){
            // cout<<"Hello ) :"<<a[i]<<endl;
            while(oper.gettop()!='('){
                int num2=Number.gettop();
                Number.del();
                // cout<<"\nNum2: "<<num2<<endl;
                int num1=Number.gettop();
                Number.del();
                // cout<<"\nNum1: "<<num1<<endl;
                char op=oper.gettop();
                oper.del();
                Number.insert(calculate(num1,num2,op));
                // cout<<"\nWhile Loop:\n";
                // cout<<i<<"-------"<<endl;
                // Number.print();
                // cout<<"---------"<<endl;
                // oper.print();
                // cout<<"---------"<<endl;
            }
            oper.del();
        }
        else if(precedence(a[i])>=precedence(oper.gettop())){
            // cout<<"Hello Up: "<<a[i]<<endl;
            oper.insert(a[i]);
            }
        else if(precedence(a[i])<precedence(oper.gettop())){
            // cout<<"Hello Down: "<<a[i]<<endl;
            int num2=Number.gettop();
            Number.del();
            int num1=Number.gettop();
            Number.del();
            char op=oper.gettop();
            oper.del();
            Number.insert(calculate(num1,num2,op));
            oper.insert(a[i]);
        } 
    }
    for(int i=0;i<=oper.size();i++){
        int num2=Number.gettop();
        Number.del();
        int num1=Number.gettop();
        Number.del();
        char op=oper.gettop();
        oper.del();
        Number.insert(calculate(num1,num2,op));
    }
    return Number.gettop();
}

