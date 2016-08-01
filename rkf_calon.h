#include <vector>
#include <array>
#include <iostream>
using namespace std;

vector< array<long double,3> > rkf_calon(long double, long double, long double, long double, long double, long double, long double (*f)(long double, long double), ostream&);
