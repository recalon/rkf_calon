# rkf_calon
Runge-Kutta-Fehlberg solver, C++

This is an RKF solver function for C++. No proprietary libraries
are used here. It will solve IVPs of the form:

a <= t <= b; y(a)=*alpha*; y'=f(t,y).

Inputs are in the following order:
..* **a**: minimum of t-range;
..* **b**: maximum of t-range;
..* **_alpha_**: initial value;
..* **TOL**: error tolerance;
..* **hmin**: minimum step size;
..* **hmax**: maximum step size;
..* **function pointer**: see below;
..* **os**: output stream object for failure text; function is 
...        overloaded to omit ostream object; function output can
...        notify of failure.

Output is a std::vector of std::array<double,3> where array's position
[0] is t-value, [1] is est. y value, [2] is step size used in the
calculations to arrive at t- and est. y-values. If the step size drop-
ped below the minimum the function will return an empty vector.


This solver takes a function pointer parameter (function accepting two
'long double's and returning a 'long double') so that any first-order
ODE may be solved. A good, simple format for such a function is:

long double function(long double t, long double y) {
  return [your f(t,y) here];
}

Doxygen mardown supported.
