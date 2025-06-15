class Solution {
public:
    int maxDiff(int num) {
        string n = to_string(num);
        string a = "", b = "";
        char xa = 'a', xb = 'b';
        for (int i = 0; i< n.size(); i++){
            if (xa == 'a'){
                if (n[i] != '9'){
                    xa = n[i];
                }
                a+= "9";
            }
            else{
                if (n[i] == xa){
                    a+= "9";
                }
                else a+= n[i];
            }
            if (xb == 'b'){
                if (i == 0){
                    if (n[i] != '1'){
                        xb = n[i];
                    }
                    b+= "1";
                }
                else{
                    if (n[i] != '0' && n[i] != n[0]){
                        xb = n[i];
                        b+= "0";
                    }
                    else b+= n[i];
                }
            }
            else{
                if (n[i] == xb && xb == n[0]){
                    b+= "1";  
                }
                else if (n[i] == xb){
                    b+= "0";
                }
                else b+= n[i];
            }
        }
        cout<<a<<" "<<b;
        int a1 = stoi(a);
        int b1 = stoi(b);
        return a1-b1;
    }
};