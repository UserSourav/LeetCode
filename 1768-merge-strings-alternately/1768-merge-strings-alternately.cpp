class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string x = "";

        int i = 0;
        int j = 0;

        while (i < word1.length() && j < word2.length()) {
            x += word1[i];
            x += word2[j];

            i++;
            j++;
        }

        // remaining characters
        while (i < word1.length()) {
            x += word1[i];
            i++;
        }

        while (j < word2.length()) {
            x += word2[j];
            j++;
        }

        return x;
    }
};