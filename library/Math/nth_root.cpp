// this is written by wolf
int lim[] = {0,0,(int)2e9,(int)2e6,(int)4e4};
long long nth_root(long long x , int n) {
    long long l = 1 , r = lim[n] , theOne = -1;
    while (l <= r) {
        long long mid = (l + r) / 2 , ans = 1;
        for (int i = 0 ;i < n ;i++)
            ans *= mid;

        if (ans == x) {
            theOne = mid;
            break;
        }

        if (ans >= x)
            r = mid - 1;
        else
            l = mid + 1;
    }

    return theOne;
}
