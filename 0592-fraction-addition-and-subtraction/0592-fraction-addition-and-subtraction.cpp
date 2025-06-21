class Solution {
public:
    string fractionAddition(string expression) {

        vector<string> num, den;
        int pos = 0, i =0;

        while(i<expression.length()){
            if(expression[i]=='+'){
                i++;
            }

            num.push_back("");
            while(expression[i]!='/'){
                num[pos] += expression[i++];
            }
            i++;
            den.push_back("");
            while((expression[i]!='+'&&expression[i]!='-')&& i<expression.length()){
                den[pos] += expression[i++];
            }
            pos++;
        }
        vector<int> denint;
        for (string val : den){
            denint.push_back(stoi(val));
        }
        long denominator = 1;
        for (int val:denint){
            denominator *= val;
        }
        vector<int> numint;
        for (int i = 0; i<pos; i++){
            numint.push_back(stoi(num[i])* denominator/denint[i]);
        }
        
        long numerator = 0;
        for (int val:numint){
            numerator += val;
        }

        int g = __gcd(abs(numerator), abs(denominator));
        return to_string(numerator/g)+"/"+to_string(denominator/g);
    }
};