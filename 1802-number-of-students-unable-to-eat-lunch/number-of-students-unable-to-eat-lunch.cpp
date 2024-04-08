class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {0}; 
        for (int student : students) {
            count[student]++;
        }

        int i = 0; 
        while (i < sandwiches.size() && count[sandwiches[i]] > 0) {
            count[sandwiches[i]]--; 
            i++; 
        }

        
        return students.size() - i;
    }
};