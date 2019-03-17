
const int N = 1003 , M = 1003;
int n , W , w[N] , c[N] , memo[N][M];

int Knapsack(int indx , int remW){ // indx is current index of the elements , remW is space remainder in your bag
    if(indx == n)
        return 0;

    int &ret = memo[indx][remW];
    if(~ret)                       // equivalent to (ret != -1)
        return ret;

    ret = Knapsack(indx + 1 , remW); // try to leave this item
    if(w[indx] <= remW)ret = max(ret , c[indx] + Knapsack(indx + 1 , remW - w[indx]));  // try to take this item if it is possible

    return ret;
}

// need to fill memo table -1 values (marked as not calculates yet) and the answer will be Knapsack(0 , W)
