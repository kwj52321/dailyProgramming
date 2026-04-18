class Solution {
public:
    int climbStairs(int n) {
    int arr[46];
    for (int i=0; i<46; i++) arr[i] = -1;
        if (n < 0) return -1;
        if (arr[n] != -1) {
            return arr[n];
        } else {
            if (n < 3) {
                arr[n] = n;
            } else {
               arr[n] = climbHelper(arr, n);
            }
        return arr[n];
        }
    }

    int climbHelper(int* arr, int n){
        if (n < 3) {
            arr[n] = n;
            return arr[n];
        } else {
            if (arr[n] != -1) { return arr[n]; }
            else {
                arr[n] = climbHelper(arr, n-1) + climbHelper(arr, n-2);
                return arr[n];
            }
        }
    }
};