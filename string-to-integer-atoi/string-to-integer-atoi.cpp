class Solution {
public:
    int myAtoi(string s) {
        if(s == "2147483648") return 2147483647;
        if(s == "-2147483649") return -2147483648;
        int ptr1 = 0;
        long toReturn = 0;
        int negMult = 1; // changes to -1 if a negative symbol is detected
        while(s[ptr1] == ' ') ptr1++;
        if(s[ptr1] == '-') {negMult = -1; ptr1++;}
        else if(s[ptr1] == '+') ptr1++;
        else if(static_cast<int>(s[ptr1]) < 48 || static_cast<int>(s[ptr1]) > 57) return toReturn;
        while(s[ptr1] == '0') ptr1++;
        
        // toReturn += static_cast<int>(s[ptr1]) - 48;
        while(static_cast<int>(s[ptr1]) >= 48 && static_cast<int>(s[ptr1]) <= 57){
            toReturn *= 10;
            if(toReturn >= static_cast<long>(INT32_MAX)){
                if(negMult == -1) return INT32_MIN;
                else return INT32_MAX;
            }
            toReturn += static_cast<int>(s[ptr1]) - 48;
            ptr1++;
        }
        return static_cast<int>(negMult * toReturn);
    }
};