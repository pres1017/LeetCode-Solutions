class Solution {
public:
    string charSort(string str){
        priority_queue<char> pq;
        for(int x = 0; x < str.size(); x++){
            pq.push(str[x]);
        }
        str.clear();
        while(pq.size() > 0){
            str.push_back(pq.top());
            pq.pop();
        }
        return str;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> keys;
        vector<vector<string>> toReturn;
        unordered_map<string, vector<string>> table; // contains string for keys
        for(auto str : strs){
            string newStr = charSort(str);
            if(table.count(newStr) == 0){
                table[newStr] = vector<string>(1, str);
                keys.push_back(newStr);
            }else{
                table[newStr].push_back(str);
            }
        }
        for(auto key : keys){
            vector<string> toAppend;
            for(auto str : table[key]){
                toAppend.push_back(str);
            }
            toReturn.push_back(toAppend);
        }
        return toReturn;
    }
};