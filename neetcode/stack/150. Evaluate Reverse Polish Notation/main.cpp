class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> ar;

        for(int i = 0; i < tokens.size(); i++) {
            if(isdigit(tokens[i].back())) {
                ar.push_back(stoi(tokens[i]));
            } else {
                int a, b;
    
                a = ar.back();
                ar.pop_back();
                b = ar.back();
                ar.pop_back();

                if(tokens[i] == "+") {
                    ar.push_back(b + a);
                } else if (tokens[i] == "-") {
                    ar.push_back(b - a);
                } else if (tokens[i] == "*") {
                    ar.push_back(b * a);
                } else if (tokens[i] == "/") {
                    ar.push_back(b / a);
                }           
            }
        }
        return ar.back();
    }
};
