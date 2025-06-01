class Solution {
public:
    string convert(string s, int numRows) {
        // If only one row or string is too short, return original string
        if (numRows == 1 || s.size() <= numRows)
            return s;

        // Create a vector to hold strings for each row
        vector<string> rows(numRows);

        int row = 0;           // Current row index
        bool goingDown = true; // Direction flag: true means moving down

        // Loop through each character in the input string
        for (int i = 0; i < s.size(); i++) {
            rows[row] += s[i]; // Add character to the current row

            // Change direction if we reach the top or bottom row
            if (row == 0)
                goingDown = true;
            else if (row == numRows - 1)
                goingDown = false;

            // Move row index up or down depending on direction
            if (goingDown)
                row++;
            else
                row--;
        }

        string result = ""; // This will hold the final zigzag string

        // Combine all rows into the result string
        for (int i = 0; i < numRows; i++) {
            result += rows[i];
        }

        return result; // Return the final converted string
    }
};
