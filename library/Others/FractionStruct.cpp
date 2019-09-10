// for probability & expectation problems
// check negative here
template <typename T>
struct Fraction{
   T up , down;
   Fraction(){up = down = 0;}
   Fraction(T u , T d){
      up = u , down = d;
      simplify();
   }
   void simplify(){
      T gcd = __gcd(up , down);
      if(gcd != 0)
         up /= gcd , down /= gcd;
   }
   Fraction operator *(const Fraction &b) const{
      Fraction c = Fraction(up * b.up , down * b.down);
      c.simplify();
      return c;
   }
   Fraction operator +(const Fraction &b) const{
      if(!up)return b;
      T lcm = down * (b.down / __gcd(down , b.down)); // we avoided overflow here
      return Fraction(up * (lcm / down) + b.up * (lcm / b.down) , lcm);
   }
   void print(){ // depends
      if(!up)
         cout << "0\n";
      else if(up == down)
         cout << "1\n";
      else
         cout << up << "/" << down << "\n";
   }
};