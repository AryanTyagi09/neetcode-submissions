class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord not present
        if (st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int steps = 1;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string word = q.front();
                q.pop();

                // If reached end
                if (word == endWord)
                    return steps;

                // Try all transformations
                for (int j = 0; j < word.length(); j++) {
                    char original = word[j];

                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        word[j] = ch;

                        if (st.find(word) != st.end()) {
                            q.push(word);
                            st.erase(word); // mark visited
                        }
                    }

                    word[j] = original; // restore
                }
            }

            steps++;
        }

        return 0;
    }
};