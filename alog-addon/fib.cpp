
using namespace std;

int main()
{
    int fib(int N)
    {
        if (N < 1)
            return 0;
        vector<int> memo(N + 1, 0);
        memo[1] = memo[2] = 1;
        return helper(memo, N);
    };
}

int helper(vector<int> &memo, int n)
{
    if (n > 0 && memo[n] == 0)
    {
        memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    }
    return memo[n];
}