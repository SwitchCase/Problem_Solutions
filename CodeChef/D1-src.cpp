#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <cstdlib>
#include <sstream>
#include<cstdio>
#include<cstring>
#include<cassert>


using namespace std;
int primes[1000];
double other[500001];
int p;

int slow[500001];
int ans[500001];

void doSlow() {
  for (int i=0;i<=500000;i++)
    slow[i] = 1;
  for (int i=2;i<=500000;i++) {
    int t = i+i;
    for (int j=t;j<=500000;j+=i) {
      slow[j] = (slow[j]*i)%10000;

    }
  }

  for (int i=2;i<=500000;i++) {
    if (slow[i] != ans[i])
      printf("%d\n",i);
  }
}

double dpow(int t,int y)
{
  if (y == 0)
    return 1.0;
  if (y%2 == 0) {
    double r =dpow(t,y/2);
    return r*r;
  }
  return dpow(t,y-1)*(double)t;
}

void fill() {
  p = 1;
  primes[0] = 2;
  for (int i=3;i<1000;i++) {
    bool prime = true;
    for (int j=0;j<p;j++) {
      if (i%primes[j] == 0) {
        prime = false;
        break;
      }
    }
    if (prime)
      primes[p++] = i;
  }
}

int fact[20];
int f;
int g;

int power(int t,int y) {
  if (y == 0)
    return 1;
  if (y%2 == 0) {
    int x = power(t,y/2);
    x = x*x;
    if (x > 10000) {
      g = 1;
      x %= 10000;
    }
    return x;
  }
  long long x = (long long)power(t,y-1)*(long long)t;
  if (x > 10000) {
    g = 1;
    x %= 10000;
  }
  return (int)x;
}

int fac(int n)
{
  f = 0;
  for (int i=0;i<p;i++)
  {
    if (primes[i] > n)
      break;
    if (n%primes[i] == 0) {
      fact[f] = 0;
      while (n%primes[i] == 0) {
        fact[f]++;
        n /= primes[i];
      }
      f++;
    }
  }
  if (n > 1) {
    fact[f] = 1;
    f++;
  }

  int t = 1;
  for (int i=0;i<f;i++) {
    t = t*(fact[i]+1);
  }
  return t;
}

int s[500001];
void sieve()
{
  memset(s,0,sizeof(int)*500001);
  for (int i=2;i<=500000;i++) {
    if (s[i] == 0) {
      int t = i;
      for (int j=t;j<=500000;j+=t) {
          s[j] = i;
      }
    }
  }
}

int powers[500001];
int topower[500001];
int leadZero[500001];

void doit() {
  powers[1] = 1;
  powers[2] = 2;
  ans[1] = 1;
  ans[2] = 1;
  leadZero[0] = 0;
  leadZero[1] = 0;
  int f = 2;
  int f2 = f*f;
  for (int i=3;i<=500000;i++) {
    int t = s[i];
    int x = i;
    int y = 0;
    while (x%t == 0)
    {
      y++;
      x /= t;
    }
    powers[i] = powers[x]*(y+1);
    int top = 0;
    if (i == f2) {
      f++;
      f2 = f*f;
      top = powers[i]-2;
      topower[i] = f-1;
    } else {
      topower[i] = i;
      top = powers[i]/2 - 1;
    }
    g = 0;
    ans[i] = power(topower[i],top);
    other[i] = dpow(topower[i],top);
    leadZero[i] = g;
  }
}

int main()
{
  sieve();
  doit();
  //doSlow();
  int t;

  scanf ("%d",&t);
  int n;
  while(t--) {
    scanf ("%d",&n);
    if (leadZero[n])
      printf ("%04d\n",ans[n]);
    else
      printf ("%d\n",ans[n]);
  }
  return 0;
}
