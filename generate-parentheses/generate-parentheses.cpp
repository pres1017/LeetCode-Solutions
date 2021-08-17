class Solution {
public:
    bool validParens(string parens){
        std::cout << "Checking valid " << parens << "\n";
        int balance = 0;
        for(auto x : parens){
            if(x == '(') balance++;
            else balance--;
            if(balance < 0) return false;
        }
        if(balance != 0) return false;
        return true;
    }
    
    void makeParens(string paren, vector<string>& toReturn, int ins, int outs){
        if(ins == 0 && outs == 0){
            if(validParens(paren)) toReturn.push_back(paren);
            else return;
        }
        
        if(ins > 0){
            string paren1 = paren;
            paren1.push_back('(');
            makeParens(paren1, toReturn, ins - 1, outs);
        }
        if(outs > 0){
            string paren2 = paren;
            paren2.push_back(')');
            makeParens(paren2, toReturn, ins, outs - 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        int ins = n - 1;
        int outs = n;
        string parens("(");
        vector<string> toReturn;
        makeParens(parens, toReturn, ins, outs);
        return toReturn;
    }
};