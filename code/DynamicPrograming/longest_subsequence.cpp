#include <iostream>
#include <string>
using namespace std;

void longestSubsequence(string s1, string s2)
{
    int matrix[100][100], n = s1.length(), m = s2.length(), mx = 0;

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            matrix[i][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s1[j - 1] == s2[i - 1])
            {
                matrix[i][j] = 1 + matrix[i - 1][j - 1];
            }
            else
                matrix[i][j] = matrix[i][j - 1];
    for (int i = 1; i <= m; i++)
        mx = mx > matrix[i][n] ? mx : matrix[i][n];
    cout << "Max length is " << mx;
}
int main()
{
    string s1, s2;
    cout << "Enter the first string" << endl;
    cin >> s1;
    cout << "Enter the second string" << endl;
    cin >> s2;
    longestSubsequence(s1, s2);
    return 0;
}