class Solution {
public:
    double myPow(double x, int n) {
        double X = x;
        long long N = n;

        if (n < 0){
            N = -N;
            X = 1/X;
        }

        return helperPow(X, N);
    }

    double helperPow(double x, long long n){
        if (n == 0) {
            return 1;
        }
        if (n%2 == 0){
            double half =  helperPow(x, n/2);
            return half * half;
        } else {
            double half = helperPow(x, n/2);
            return x * half * half;
        }
    }
};