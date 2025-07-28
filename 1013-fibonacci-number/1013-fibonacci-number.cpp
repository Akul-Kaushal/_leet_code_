class Solution {
public:
    int fib(int n) {
        // if (n < 2) return n;
        // return fib(n-1) + fib(n-2);
        if (n<2) return n;

        int left=0;
        int right=1;

        for ( int i=2; i<=n;i++)
        {
            int temp = max(right,left);
            left = right + left;
            right = temp;
        }
        return left;
    }
};