class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();
        
        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;
            
            // Find how many words can fit in the current line
            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();  // 1 for the space
                j++;
            }
            
            int spaceSlots = j - i - 1;
            string line = words[i];
            
            // If it's the last line or only one word in the line
            if (j == n || spaceSlots == 0) {
                for (int k = i + 1; k < j; ++k) {
                    line += " " + words[k];
                }
                // Pad with spaces at the end
                line += string(maxWidth - line.size(), ' ');
            } else {
                int totalSpaces = maxWidth;
                for (int k = i; k < j; ++k) totalSpaces -= words[k].size();
                
                int space = totalSpaces / spaceSlots;
                int extra = totalSpaces % spaceSlots;
                
                for (int k = i + 1; k < j; ++k) {
                    int spacesToInsert = space + (extra-- > 0 ? 1 : 0);
                    line += string(spacesToInsert, ' ') + words[k];
                }
            }
            
            result.push_back(line);
            i = j;
        }
        
        return result;
    }
};

