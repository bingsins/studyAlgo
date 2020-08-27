class Solution
{
public:
    void fill2(vector<vector<int>> &A, int i, int j)
    {
        if (i < 0 || i >= A.size() || j < 0 || j >= A.size() || A[i][j] == 0 || A[i][j] == 2)
            return;
        A[i][j] = 2;
        fill2(A, i + 1, j);
        fill2(A, i - 1, j);
        fill2(A, i, j + 1);
        fill2(A, i, j - 1);
    }

    bool expand(vector<vector<int>> &A, int i, int j, int count)
    {
        if (i < 0 || j < 0 || i == A.size() || j == A.size())
            return false;
        if (A[i][j] == 0)
            A[i][j] = count + 1;
        return A[i][j] == 1;
    }

    int shortestBridge(vector<vector<int>> &A)
    {
        int i, j = A.size();
        for (i = 0; i < A.size(), j == A.size(); i++)
        {
            for (j = 0; j < A.size(); j++)
            {
                if (A[i][j] == 1)
                {
                    fill2(A, i, j);
                    break;
                }
            }
        }

        int count = 2;

        while (count)
        {
            i = 0;
            j = 0;
            for (i = 0; i < A.size(); i++)
            {
                for (j = 0; j < A.size(); j++)
                {
                    if (A[i][j] == count && ((expand(A, i - 1, j, count) || expand(A, i, j - 1, count) || expand(A, i + 1, j, count) || expand(A, i, j + 1, count))))
                        return count - 2;
                }
            }

            count++;
        }
        return 1;
    }
};