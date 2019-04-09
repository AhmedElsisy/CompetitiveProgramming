stack<pair<int , int> > st;
void add(int x){
    int new_mn = (st.empty() ? x : min(x , st.top().second));
    st.push({x , new_mn});
}

int removeLast(){
    if(st.empty())return -1;
    int removed_element = st.top().first;
    st.pop();
    return removed_element;
}

int getMinimum(){
    if(st.empty())return -1;
    return st.top().second;
}
