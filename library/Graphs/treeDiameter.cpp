pair<int , int> getDiameter(int u , int p , int dep){
    pair<int , int> ret = {dep , u};
    for(int c : adj[u]){
        if(c == p)continue;
        auto child = getDiameter(c , u , dep + 1);
        ret = max(ret , child);
    }
    return ret;
}

int getDiameter(){
    return getDiameter(getDiameter(1 , -1 , 0).second , -1 , 0).first;
}
