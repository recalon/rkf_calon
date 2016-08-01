# rkf_calon
Runge-Kutta-Fehlberg solver, C++

This solver takes a function pointer parameter (function accepting two
'long double's and returning a 'long double') so that any first-order
ODE may be solved. A good, simple format for such a function is:

long double function(long double t, long double y) {
  return [your y'(t)=f(t,y) here];
}

Doxygen mardown supported.
