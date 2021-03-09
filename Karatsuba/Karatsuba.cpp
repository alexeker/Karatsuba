// Karatsuba.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
int Get_Length(int a) {
    int length = 1;
    while (a /= 10) {
        length++;
    }
    return length;
}
int Left(int x) {
    return x / std::pow(10,Get_Length(x)/2);
}
int Right(int x) {
    return x - Left(x) * std::pow(10, Get_Length(x) / 2);
}
int Karatsuba_alg(int a, int b) {
    int x = a;
    int y = b;
    int N = std::min(Get_Length(x), Get_Length(y));
    long long res = 0;
    if (N == 1) return x * y;
    else {
        int X_l, X_r, Y_l, Y_r, pr1,pr2,pr3;
        X_l = Left(x);
        X_r = Right(x);
        Y_l = Left(y);
        Y_r = Right(y);
        pr1 = Karatsuba_alg(X_l, Y_l);
        pr2 = Karatsuba_alg(X_r, Y_r);
        pr3 = Karatsuba_alg((X_l + X_r), (Y_l + Y_r));
        res =  pr1 * std::pow(10, N) + (pr3 - pr2 - pr1) * std::pow(10, (N / 2)) + pr2;
        return res;
    }

}
int main()
{
    using namespace std;
    int vyv = Karatsuba_alg(1234, 5678);
    cout << vyv << endl;
    return 0;

}
