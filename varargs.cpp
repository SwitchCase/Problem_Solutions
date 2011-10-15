#include <cstdarg>
#include <iostream>

using namespace std;

double average (int n, ... )
{
  va_list arguments;                     // A place to store the list of arguments
  double sum = 0;

  va_start ( arguments, num );           // Initializing arguments to store all values after num
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    sum += va_arg ( arguments, int ); // Adds the next value in argument list to sum.
  va_end ( arguments );                  // Cleans up the list
  cout<<sum<<" "<<num<<endl;
  
  return 1.0*sum / num;                      // Returns some number (typecast prevents truncation)
}
int main()
{
  cout<< average ( 3, 12, 22, 4 ) <<endl;
  cout<< average ( 5, 3, 2, 1, 5, 3 ) <<endl;
}

