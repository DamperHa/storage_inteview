#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> sk;

        for( int i = 0; i < tokens.size(); i++){
            string s = tokens[i];
            if( s == "+" || s == "-" || s == "*" || s == "/"){
                int tmp1 = sk.top();
                sk.pop();
                int tmp2 = sk.top();
                sk.pop();

                int res;
                if( s == "+")
                    res = tmp1 + tmp2;
                else if( s == "-")
                    res = tmp2 - tmp1;
                else if( s == "*")
                    res = tmp1 * tmp2;
                else 
                    res = tmp2 / tmp1;

                sk.push(res); 
            }else
                sk.push(stoi(s));
            

        }
        return sk.top();
    }
};


int main(){
	vector<string> v = {"4", "13", "5", "/", "+"};
	int result = Solution().evalRPN(v);
	cout << result << endl;
}
