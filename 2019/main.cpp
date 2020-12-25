#include <iostream>
#include <string>

template<typename First>
void print( First data )
{
  std::cout << std::string(data) << std::endl;
}

template<typename First, typename... T>
void print( First data, T... data2 )
{
  std::cout << std::string(data) << std::endl;
  print<T...>( data2... );
}

struct Merry{ operator std::string() { return "Grüße"; } };
struct Xmas{ operator std::string() { return "Kargi"; } };

int main()
{
  print( Merry(), Xmas() );
  return 0;
}
