#include <iostream>
#include <string>

template<typename T>
struct IsChristmas
{
  typedef char One;
  typedef struct { char a[2]; } Two;
  template<typename C> static One test( int C::* );
  template<typename C> static Two test(...);
  static constexpr bool Yes = sizeof( IsChristmas<T>::test<T>(0) ) == 1;
};

struct{ std::string operator()(){ return "Schöne Weihnachten und ein gutes neues Jahr!";} } christmas1;
char christmas2[] = "Überlegst du wirklich, wie das funktioniert?";

int main()
{
  if( IsChristmas<decltype(christmas1)>::Yes ){ std::cout << christmas1() << std::endl; }
  if( IsChristmas<decltype(christmas2)>::Yes ){ std::cout << christmas2   << std::endl; }
  return 0;
}
