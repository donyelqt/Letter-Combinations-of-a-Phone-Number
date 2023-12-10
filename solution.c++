#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> result;
        if (digits.empty()) {
            return result;
        }

        std::vector<std::string> mapping = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, "", result, mapping);

        return result;
    }

private:
    void backtrack(const std::string& digits, int index, std::string current,
                   std::vector<std::string>& result, const std::vector<std::string>& mapping) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';
        const std::string& letters = mapping[digit];

        for (char letter : letters) {
            backtrack(digits, index + 1, current + letter, result, mapping);
        }
    }
};
