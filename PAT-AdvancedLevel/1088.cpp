#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
typedef long long LL;

LL gcd(LL a, LL b)
{
    return b == 0 ? a : gcd(b, a % b);
}

LL a1, b1, a2, b2;

void out(LL a, LL b)
{
    LL g = gcd(abs(a), b);
    a /= g, b /= g;
    LL i = a / b;
    if (i)
        a = abs(a);
    a = a % b;

    if (i == 0 && a == 0)
        printf("0");
    if (i < 0 || a < 0)
        printf("(");
    if (i != 0)
    {
        printf("%lld", i);
        if (a != 0)
            printf(" ");
    }
    if (a != 0)
        printf("%lld/%lld", a, b);
    if (i < 0 || a < 0)
        printf(")");
}

void add()
{
    out(a1, b1);
    printf(" + ");
    out(a2, b2);
    printf(" = ");

    LL ansa, ansb;
    ansb = b1 * b2;
    ansa = a1 * b2 + a2 * b1;
    out(ansa, ansb);

    printf("\n");
}

void sub()
{
    out(a1, b1);
    printf(" - ");
    out(a2, b2);
    printf(" = ");

    LL ansa, ansb;
    ansb = b1 * b2;
    ansa = a1 * b2 - a2 * b1;
    out(ansa, ansb);

    printf("\n");
}

void mul()
{
    out(a1, b1);
    printf(" * ");
    out(a2, b2);
    printf(" = ");

    LL ansa, ansb;
    ansb = b1 * b2;
    ansa = a1 * a2;
    out(ansa, ansb);

    printf("\n");
}

void div()
{
    out(a1, b1);
    printf(" / ");
    out(a2, b2);
    printf(" = ");

    LL ansa, ansb;
    ansb = b1 * a2;
    ansa = a1 * b2;
    if (ansb == 0)
        printf("Inf");
    else if (ansb < 0)
        out(-ansa, -ansb);
    else
        out(ansa, ansb);

    printf("\n");
}

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
    add();
    sub();
    mul();
    div();
    return 0;
}