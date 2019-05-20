long long a = 1e18 , b = 1e9 , tmp;
bool flag = __builtin_add_overflow(a , b , &tmp);
bool flag2 = __builtin_mul_overflow(a , b , &tmp);
bool flag3 = __builtin_sub_overflow(a , b , &tmp);
if(flag)
    cout << "overFlow" << endl;
else cout << tmp << endl;
