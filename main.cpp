#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#define ll long long
using namespace std;

//////многомерная префиксная сумма///////////////////
vector<vector<ll>> findPrefixSums2D(vector<vector<ll>>& a) {
    ll n = a.size();
    ll m = a[0].size();
    vector<vector<ll>> prefixSum(n + 1, vector<ll>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            prefixSum[i + 1][j + 1] = prefixSum[i][j + 1] + prefixSum[i + 1][j] - prefixSum[i][j] + a[i][j];
        }
    }
    return prefixSum;
}

//гайки, шайбы, шестеренки
vector<ll> z_function(const string& s) {
    ll n = (ll) s.size();
    vector<ll> z(n, 0);
    ll l = 0, r = 0;
    for (ll i = 1; i < n; i++) {
        // если мы уже видели этот символ
        if (i <= r)
            // то мы можем попробовать его инициализировать z[i - l],
            // но не дальше правой границы: там мы уже ничего не знаем
            z[i] = min(r - i + 1, z[i - l]);
        // дальше каждое успешное увеличение z[i] сдвинет z-блок на единицу
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        // проверим, правее ли мы текущего z-блока
        if (i + z[i] - 1 > r) {
            r = i + z[i] - 1;
            l = i;
        }
    }
    return z;
}

//подсчет вхождений подстроки в строку
vector<ll> findP_$_T(const string& p, const string& t){
    string str = p + "#" + t;
    vector<ll> vec = z_function(str);

    vector<ll> v;
    for(int i = p.size() + 1; i < (ll)vec.size(); i++){
        if(vec[i] == (ll)p.size()){
            v.push_back(i - p.size() - 1);
        }
    }
    return v;
}

void printInfo(vector<ll>& v){
    for(ll i = 0; i < (ll)v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
//вывод инфы в двумерном массиве
void printInfo(vector<vector<ll>>& v){
    for(ll i = 0; i < (ll)v.size(); i++){
        for(ll j = 0; j < (ll)v[i].size(); j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

//все перестановки в строке
vector<string> search_recombinateS(string s) {
    vector<string> v;

    do{
        v.push_back(s);
    }while(std::next_permutation(s.begin(), s.end()));

    return v;
}

//все перестановки вектора
vector<vector<ll>> search_recombinateV(vector<ll> vec){
    vector<vector<ll>> v;

    do{
        v.push_back((vec));
    }while(std::next_permutation(vec.begin(), vec.end()));

    return v;
}

vector<ll> findPrefixSums(vector<ll>& a) {
    ll n = a.size();
    vector<ll> prefixSums(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefixSums[i + 1] = prefixSums[i] + a[i];
    }
    return prefixSums;
}

void fast(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
}

////////////////////////////////Формулы ГОВНА////////////////////////////////////////

//Наибольший общий делитель
ll gcd (ll a, ll b) {return b ? gcd (b, a % b) : a;}

//деление с округлением вверх
int delUp(int a, int b){return (a + b - 1)/b;}

//наименьшее целое число x > n, делящееся на k
int getK(int n, int k){
    int r = n % k;
    return n + k - r;
}


//NUM == NOD * NOK
ll NOD(ll a, ll b){return gcd(a,b);}

ll NOK(ll a, ll b){return lcm(a,b);}

//Логарифмус
ll LOG2(ll n){return __lg(n);}

//Сумма первых n членов алгебраической прогрессии
ll algebraProgression(ll a0, ll an, ll n){return (n * (a0 + an))/2; }

//Свойство прогрессии: a(n) = (a(n+1) + a(n-1))/2
ll algProgressionELEM(ll an_plus_1, ll an_minus_1){return (an_plus_1 + an_minus_1)/2;}

//Геометрическая прогрессия
ll geomProgression(ll a0, ll an, ll q){return (an * q - a0)/(q - 1);}

//Свойство прогрессии: b(n) = b(n+1) * b(n-1)
ll geomProgressionELEM(ll an_plus_1, ll an_minus_1){return an_plus_1 * an_minus_1;}


///////////////////////////////СТРОЧКИ ГОВНА/////////////////////////////////////////

//tolower - приводит char к нижнему регистру
//toupper - приводит строку к верхнему регистру

//приведение size_t к ll, поскольку size_t[0...n];
#define llsz(x) ll((x).size())
#define subs(start, count) substr(start, count)
#define toString(x) to_string(x)
#define FEIN(pos) pos != (int)std::string::npos

//Удаление части строки до find()
void YEAT(string& str, const string& stofind){
    int pos = str.find(stofind);
    if(FEIN(pos)){
        str = str.substr(pos, str.size() - pos - 1);
    }
}

//Подсчет символов по строке
void bigBodyTonka(char c, char v){
    //c == 1 and v == 0
    ll n;
    string str;
    cin>>n>>str;
    str.push_back(v);

    auto it = str.begin();
    auto next = (str.begin() + str.find(v));
    while(it != str.end()){
        cout<<count(it, next, c);
        it = next + 1;
        next = find(next + 1, str.end(), v);
    }
}

//Пример решения диофантового уравнения в строках
void diofantBiggestGay(){
    ll n, p, q;
    cin>>n>>p>>q;

    string str;
    cin>>str;
    //diofant equasion: px + qy = n;
    //x = (n - qy)/p
    //y = (n - px)/q
    for(int np = 0; np <= (n / p); np++){
        for(int nq = 0; nq <= (n - p * np) / q; nq++){
            if(np * p + nq * q == n){
                cout<<np + nq<<endl;
                for(int i = 0; i < np; i++){
                    cout<<str.substr(0, p)<<endl;
                    str = str.substr(p);
                }

                for(int i = 0; i < nq; i++){
                    cout<<str.substr(0, q)<<endl;
                    str = str.substr(q);
                }
                return;
            }
        }
    }
    cout<<-1<<endl;
}

void deleteBeginAndEndZeros(string& str){
    for(int i = 0; i < 2; i++){
        while(!str.empty() && str.back() == '0'){
            str.pop_back();
        }
        reverse(str.begin(), str.end());
    }
}

void solve() {
   
}

int main() {
    fast();
    diofantBiggestGay();
}
