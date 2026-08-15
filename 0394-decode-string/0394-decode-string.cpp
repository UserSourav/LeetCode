class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> strs;

        string curr = "";
        int num = 0;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '[') {
                nums.push(num);
                strs.push(curr);

                num = 0;
                curr = "";
            }

            else if (ch == ']') {
                int repeat = nums.top();
                nums.pop();

                string prev = strs.top();
                strs.pop();

                for (int i = 0; i < repeat; i++) {
                    prev += curr;
                }

                curr = prev;
            }

            else {
                curr += ch;
            }
        }

        return curr;
    }
};