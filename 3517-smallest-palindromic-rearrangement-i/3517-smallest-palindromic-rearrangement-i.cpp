class Solution {
public:
    string smallestPalindrome(string s) {
        int cnt[26] = {0};

        for (char ch : s) {
            cnt[ch - 'a']++;
        }

        string firstHalf;
        firstHalf.reserve(s.size() / 2);

        char center = 0;

        for (int i = 0; i < 26; i++) {
            int pairs = cnt[i] / 2;
            while (pairs--) {
                firstHalf.push_back('a' + i);
            }

            if (cnt[i] & 1) {
                center = 'a' + i;
            }
        }

        string result;
        result.reserve(s.size());

        result += firstHalf;

        if (center) {
            result.push_back(center);
        }

        for (int i = static_cast<int>(firstHalf.size()) - 1; i >= 0; i--) {
            result.push_back(firstHalf[i]);
        }

        return result;
    }
};