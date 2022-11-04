// Write code for the conversion of infix expresultsion into postfix expresultsion.
//Function to check the precedence of operators
int precedence(char c){
    if (c == '^')
        return 3;
    else if (c=='/'||c=='*')
        return 2;
    else if (c=='-'||c=='+')
        return 1;
    else
        return -1; //for () Brackets
}
//Function to convert infix to postfix
string InfixTopostfix(string exp){
    stack<char> s;
    string result;
    for (int i=0;i<exp.size();i++){
        if (exp[i]>='a'&&exp[i]<='z'||exp[i]>='A'&&exp[i]<='Z')
            result = result + exp[i];
        else if (exp[i] == '(')
            s.insert(exp[i]);
        else if (exp[i] == ')'){
            while (s.gettop() != '('&&!s.IsEmpty()){
                result = result + s.gettop();
                s.del();
            }
            s.del();
        }
        else{
            while (!s.IsEmpty() && precedence(s.gettop()) >= precedence(exp[i])){
                result = result + s.gettop();
                s.del();
            }
            s.insert(exp[i]);
        }
    }
    while (!s.IsEmpty()){
        result = result + s.gettop();
        s.del();
    }
    return result;
}
