#include <typeinfo>
#include <iomanip>
#include "rkf_calon.h" 
using namespace std;

long double test_function(long double,long double);

int main() {
  
  auto results = rkf_calon(0,3,.5,.0001,.01,.25,test_function,cout);
  
  if(results.empty()) cout << "RK45 failed.\n\n";
  cout << setw(11) << "t|" << setw(11) << "est.y(t)|" << setw(11) << "h|" << '\n';
  for(size_t i=0; i<3; i++) cout << setw(10) << "----------|" ;
  cout << "\n";
  for(auto i : results) {
    for(auto j : i) cout << setw(10) << j << "|";
    cout << '\n';
  }
  cout << "\n" << endl;
  
}

long double test_function(long double t, long double w) {
  return w-(t*t)+1;
}