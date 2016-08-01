#include <cmath>
#include <string>
#include <cstdlib>
#include "rkf_calon.h"

using namespace std;
/**
 * Runge-Kutta-Fehlberg solver
 * 
 *     @param a minimum of t-range
 *     @param b maximum of t-range
 * @param alpha initial value: y(a) = alpha
 *   @param TOL error tolerance
 *  @param hmin minimum step size
 *  @param hmax maximum step size
 *     @param f y'=f(t,y)
 *    @param os output stream for errors
 */
vector< array<long double,3> > rkf_calon (long double a, long double b, long double alpha, long double TOL, long double hmin, long double hmax, long double (*f)(long double, long double), ostream& os) {
  
  long double h, del, R, t, w;
  long double k1, k2, k3, k4, k5, k6;
  bool flag = true, fail = false;
  vector< array<long double,3> > out;
  array<long double,3> temp = {0,0,0};
  
  t=a;
  w=alpha;
  h=hmax;
  temp[0]=t;temp[1]=w;temp[2]=h;
  out.emplace_back(temp);
  
  while (flag) {
    k1 = h * f(t,w);
    k2 = h * f((t+h*0.25), (w+k1*0.25));
    k3 = h * f((t + h*3/8), (w + k1*3/32 + k2*9/32));
    k4 = h * f((t+h*12/13), (w + k1*1932/2197 - k2*7200/2197 + k3*7296/2197));
    k5 = h * f((t+h), (w + k1*439/216 - k2*8 + k3*3680/513 - k4*845/4104));
    k6 = h * f((t + h*.5), (w - k1*8/27 + k2*2 - k3*3544/2565 + k4*1859/4104 - k5*11/40));
    
    R = abs(k1/360 - k3*128/4275 - k4*2197/75240 + k5/50 + k6*2/55)/h;
    
    if (R<=TOL) {
      t=t+h;
      w+= k1*25/216 + k3*1408/2565 + k4*2197/4104 - k5/5;
      temp[0]=t;temp[1]=w;temp[2]=h;
      out.push_back(temp);
    }
    
    del = 0.84*pow((TOL/R),.25);
    if (del <= .1) h*=.1;
    else if (del >=4.0) h*=4.0;
    else h*=del;
    
    if (h>hmax) h=hmax;
    
    if (t>=b) flag=false;
    else if (t+h > b) h=b-t;
    else if (h<hmin) {
      flag=false;
      os << "minimum \'h\' exceeded, failure";
      fail = true;
    }
    
  }
  os << endl;
  if (fail) out.clear();
  
  return out;
}    