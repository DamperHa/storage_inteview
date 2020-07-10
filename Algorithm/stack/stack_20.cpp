#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sk;
        for(int i =0; i< s.size(); i++){
            char c = s[i];
            if( c == '(' || c == '[' || c == '{')
                sk.push(c);
        
            else{
                if( sk.empty()) return false;
                char match = sk.top();
				cout << c <<  " " << match <<  endl;
                if( (c== ')' && match == '(') || (c == ']' && match == '[') || (c == '}' && match == '{') )
                    sk.pop();
                else
                    return false;
            }
        }
        return sk.empty();
    }
};

int main(){
	string s = "()";
	bool result = Solution().isValid(s);
	cout << result << endl;
}
