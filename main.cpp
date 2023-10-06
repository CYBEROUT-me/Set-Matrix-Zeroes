#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(std::vector <int> const &a) {
    for(int x=0; x < a.size(); x++){
        cout << a.at(x) << ' ';
    }
}

template<typename T>
vector<int> findItems(std::vector<T> const &v, int target) {
    vector<int> indices;
    auto it = v.begin();
    while ((it = find_if(it, v.end(), [&] (T const &e) { return e == target; }))
           != v.end())
    {
        indices.push_back(std::distance(v.begin(), it));
        it++;
    }
    return indices;
}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> ans = matrix;
        int columns = matrix.size() - 1;
        int rows = matrix[0].size() - 1;
        for(int i = 0; i <= columns; i++){
            vector<int>::iterator itr = find(ans[i].begin(), ans[i].end(), 0);
            if (itr != ans[i].cend()) {
                cout << "\nElement present in vector of vectors at index " << distance(ans[i].begin(), itr) << endl;
                vector<int> v = ans[i];
                vector<int> indices = findItems(v, 0);
                for(int x = 0; x < indices.size(); x++){
                    ans[i][indices[x]];
                    matrix[i].clear();
                    for(int l = 0; l <= rows; l++){
                        cout << "\nI: " << i;
                        matrix[i].push_back(0);
                    }
                    for(int b = 0; b <= columns; b++){
                        matrix[b][indices[x]] = 0;
                        cout << "\nB: " << b << "\nindices[x]: " << indices[x];
                    }
                }
            }
            else continue;
        }
    }
};


int main() {
    Solution a;
    vector<vector<int>> m = {{1,1,1},{1,0,1},{1,1,1}};
    cout << "INPUT: \n";
    for(int i = 0; i < m.size(); i++){
        print(m[i]);
        cout << endl;
    }
    a.setZeroes(m);
    cout << endl;
    cout << "OUTPUT: \n";
    for(int i = 0; i < m.size(); i++){
        print(m[i]);
        cout << endl;
    }
}
