//Write code to evaluate infix, prefix and postfix expression.
#include"Stack.cpp"
#include"infix-to-postfix.cpp"
#include"evaluation.cpp"

int main(){
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"InFix to PostFix (a+b/c)*(a-b/e) = ";
    cout<<InfixTopostfix("(a+b/c)*(a-b/e)")<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"Prefix Calculation -+7*45+20 = ";
    cout<<prefix_evaluation("-+7*45+20")<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"PostFix Calculation  46+2/5*7+ = ";
    cout<<postfix_evaluation("46+2/5*7+")<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"InFix Calculation    2+(5*3-6/2)+3 = ";
    cout<<infix_evaluation("2+(5*3-6/2)+3")<<endl;
    cout<<endl<<endl;
    cout<<infix_evaluation("4*(2+3)/5")<<endl;
    return 0;
}
