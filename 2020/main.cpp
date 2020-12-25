#include <iostream>

template<typename T>
void print( const T& data )
{
  std::cout << std::string(data) << std::endl;
}

template<typename T>
void print( const T&& data)
{
  std::cout << std::string(std::move(data)) << std::endl;
}

template<typename ...T>
void hope( T&&... data )
{
  ( print( std::forward<T>(data)),...);
}

struct you_soon
{
  operator std::string() const && { return "xmas";}
  operator std::string() const & { return "merry";}
} to_see;

int main()
{
  hope( to_see, you_soon() );
  return 0;
}
