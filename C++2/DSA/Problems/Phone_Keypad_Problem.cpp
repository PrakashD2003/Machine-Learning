// The expression num[0] - '0' is a common technique in C++ (and C) to convert a character that represents a digit (e.g., '0', '1', '2', ...) into its corresponding integer value.
/* Concatenating characters into a string:
 You are adding characters directly using mapping[first][i] + mapping[second][j]. This results in an integer (ASCII addition) rather than a string.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> letterCombinations(string num) {
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> combinations;

    // Edge case: empty input
    if (num.empty()) {
        return combinations;
    }

    // Initialize combinations with an empty string to start building
    combinations.push_back("");

    // Loop through each digit in the input
    for (size_t i = 0; i < num.length(); i++) {
        char digit_char = num[i];
        int digit = digit_char - '0'; // Convert char to int

        // Skip invalid digits (0 and 1)
        if (digit < 2 || digit > 9) {
            continue;
        }

        // Get the letters for the current digit
        string letters = mapping[digit];

        // Create new combinations by appending each letter to the existing combinations
        vector<string> new_combinations;
        for (size_t j = 0; j < combinations.size(); j++) {
            for (size_t k = 0; k < letters.length(); k++) {
                new_combinations.push_back(combinations[j] + letters[k]);
            }
        }

        // Update combinations with the new ones
        combinations = new_combinations;
    }

    return combinations;
}

int main() {
    string input;
    cout << "Enter the digit string: ";
    cin >> input;

    vector<string> result = letterCombinations(input);

    // Print the results
    cout << '{';
    for (int j = 0; j < result.size(); j++)
    {
        cout << result[j];
        if (j < result.size() - 1)
        {
            cout << ',';
        }
    }
    cout << '}';

    return 0;
}
