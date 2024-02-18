#include <bits/stdc++.h>
using namespace std;

class BigInt{
private:

    string digits;

public:
 
    // Constructors
    BigInt(unsigned long long n = 0);
    BigInt(string& );
    BigInt(const char* );
    BigInt(BigInt& );
 
    //Helper Functions
    friend bool Null(const BigInt& );
    friend int Length(const BigInt& );
    int operator [] (const int ) const;
 
               /* * * * Operator Overloading * * * */
 
    // Assignment
    BigInt &operator = (const BigInt& );
 
    // Addition and Subtraction
    friend BigInt &operator += (BigInt& , const BigInt& );
    friend BigInt operator + (const BigInt& , const BigInt& );
    friend BigInt operator - (const BigInt& , const BigInt& );
    friend BigInt &operator -= (BigInt& , const BigInt& );
 
    // Multiplication and Division
    friend BigInt &operator *= (BigInt& , const BigInt& );
    friend BigInt operator * (const BigInt& , const BigInt& );
 
    // Comparison operators
    friend bool operator == (const BigInt& , const BigInt& );
    friend bool operator != (const BigInt& , const BigInt& );
 
    friend bool operator > (const BigInt& , const BigInt& );
    friend bool operator >= (const BigInt& , const BigInt& );
    friend bool operator < (const BigInt& , const BigInt& );
    friend bool operator <= (const BigInt& , const BigInt& );
 
    // cin / cout
    friend ostream &operator << (ostream& ,const BigInt& );
    friend istream &operator >> (istream& , BigInt &);
 
  
};
 
BigInt::BigInt(string & s){
    digits = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(unsigned long long nr){
    do {
        digits.push_back(nr % 10);
        nr /= 10;
    } while (nr);
}
BigInt::BigInt(const char *s){
    digits = "";
    for (int i = strlen(s) - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        digits.push_back(s[i] - '0');
    }
}
BigInt::BigInt(BigInt & a){
    digits = a.digits;
}
 
bool Null(const BigInt& a){
    if(a.digits.size() == 1 && a.digits[0] == 0)
        return true;
    return false;
}
int Length(const BigInt&  a){
    return a.digits.size();
}
int BigInt::operator[](const int index)const{
    if(digits.size() <= index || index < 0)
        throw("ERROR");
    return digits[index];
}
bool operator==(const BigInt& a, const BigInt& b){
    return a.digits == b.digits;
}
bool operator!=(const BigInt&  a,const BigInt& b){
    return !(a == b);
}
bool operator<(const BigInt&a,const BigInt&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.digits[n] != b.digits[n])
            return a.digits[n] < b.digits[n];
    return false;
}
bool operator>(const BigInt&a,const BigInt&b){
    return b < a;
}
bool operator>=(const BigInt&a,const BigInt&b){
    return !(a < b);
}
bool operator<=(const BigInt&a,const BigInt&b){
    return !(a > b);
}
BigInt &BigInt::operator=(const BigInt& a){
    digits = a.digits;
    return *this;
}

BigInt &operator+=(BigInt &a,const BigInt& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.digits.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.digits[i] + b.digits[i]) + t;
        else
            s = a.digits[i] + t;
        t = s / 10;
        a.digits[i] = (s % 10);
    }
    if(t)
        a.digits.push_back(t);
    return a;
}
BigInt operator+(const BigInt& a, const BigInt& b){
    BigInt temp;
    temp = a;
    temp += b;
    return temp;
} 
BigInt &operator-=(BigInt&a,const BigInt& b){
    if(a < b)
        throw("UNDERFLOW");
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.digits[i] - b.digits[i]+ t;
        else
            s = a.digits[i]+ t;
        if(s < 0){
            s += 10;
            t = -1;
        }
        else
            t = 0;
        a.digits[i] = s;
    }
    while(n > 1 && a.digits[n - 1] == 0){
        a.digits.pop_back();
        n--;
    }
    return a;
}
BigInt operator-(const BigInt& a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp -= b;
    return temp;
}
BigInt &operator*=(BigInt &a, const BigInt& b){
    if(Null(a) || Null(b)){
        a = BigInt();
        return a;
    }
    int n = a.digits.size(), m = b.digits.size();
    vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++){
        for (int j = 0; j < m;j++){
            v[i + j] += (a.digits[i] ) * (b.digits[j]);
        }
    }
    n += m;
    a.digits.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++){
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        a.digits[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--){
        a.digits.pop_back();
    }
    return a;
}
BigInt operator*(const BigInt&a,const BigInt&b){
    BigInt temp;
    temp = a;
    temp *= b;
    return temp;
}

istream &operator>>(istream &in,BigInt&a){
    string s;
    in >> s;
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("INVALID NUMBER");
        a.digits[n - i - 1] = s[i];
    }
    return in;
}
 
ostream &operator<<(ostream& out,const BigInt& a){
    for (int i = a.digits.size() - 1; i >= 0;i--){
        cout << (short)a.digits[i];
    }
    return cout;
}
 
int main(){

    const int MAXN = 105;
    BigInt dp[MAXN][MAXN];
    for (int i = 0; i <= 100; i++){
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for (int i = 1; i <= 100; i++){
        for (int j = 1; j <= 100; j++){
            if (i <= j){
                dp[i][j] = dp[i - 1][j] * 2;
            }
            else if (i == j + 1){
                dp[i][j] = dp[i - 1][j] * 2 - 1;
            }
            else {
                dp[i][j] = dp[i - 1][j] * 2 - dp[i - j - 2][j];
            }
        }
    }
    int n, k;
    while (cin >> n >> k){
        cout << dp[n][n] - dp[n][k - 1] << endl;
    }
    return 0;
}
