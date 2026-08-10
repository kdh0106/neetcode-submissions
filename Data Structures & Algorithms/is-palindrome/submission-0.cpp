class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() == 1)
            return true;
        string str1 = "";
        for(int i = 0; i < s.length(); i++){
            if('A' <= s[i] && s[i] <= 'Z' || 'a' <= s[i] && s[i] <= 'z' || '0' <= s[i] && s[i] <= '9')
                str1 += tolower(s[i]);
        }

        int len = str1.length();
        for(int i = 0; i < len / 2; i++){
            if(str1[i] != str1[len - 1 - i])
                return false;
        }
        return true;
    }
};
