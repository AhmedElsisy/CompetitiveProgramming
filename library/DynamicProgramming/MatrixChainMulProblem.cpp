const int N = 104;

struct mat{
    int x , y; // two dimensions of the matrix
} a[N];

int memo[N][N];

int MatrixChainMul(int i , int j){
    if(i == j)
        return 0;

    int &ret = memo[i][j];
    if(~ret)
        return ret;

    ret = 1e9;
    for(int k = i ; k < j ; ++k){               // try all possible dividing point
        int current_cost = a[i].x * a[k].y * a[j].y;
        ret = min(ret , current_cost + MatrixChainMul(i , k) + MatrixChainMul(k + 1 , j));
    }
    return ret;
}

// fill the memo table -1 and the answer will be MatrixChainMul(0 , n - 1) , s.t. n is number of matrices
// total complexity : O(n^3)
