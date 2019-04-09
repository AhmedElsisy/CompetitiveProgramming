template <typename T>
class MonotonicQueue{
    private:
        stack<pair<T , T> > st[2];
    public:
        int getsz(){
            return st[0].size() + st[1].size();
        }
        void add(T x){
            T pre = (st[0].empty() ? x : max(x , st[0].top().second));
            st[0].push({x , pre});
        }

        T pop(){
            if(st[0].empty() && st[1].empty())return -1; // No elements in monotonic queue TAKE Care of negative numbers
            if(st[1].empty()){
                T pre = st[0].top().first;
                while(!st[0].empty()){
                    auto top = st[0].top();
                    st[0].pop();
                    pre = max(pre , top.first);
                    st[1].push({top.first , pre});
                }
            }
            T removed_element = st[1].top().first;
            st[1].pop();
            return removed_element;
        }

        T get(){
            if(st[0].empty() && st[1].empty())return -1; // No elements in monotonic queue TAKE Care of negative numbers
            if(st[0].empty() || st[1].empty())
                return (st[0].empty() ? st[1].top().second : st[0].top().second);
            else return max(st[0].top().second , st[1].top().second);
        }
};
