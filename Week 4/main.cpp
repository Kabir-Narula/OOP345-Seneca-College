#include <iostream>

using namespace std;

template<typename T>
struct ValueCategory { static constexpr char const * value = "prvalue"; };

template<typename T>
struct ValueCategory <T&> { static constexpr char const * value = "lvalue"; };

template<typename T>
struct ValueCategory <T&&> { static constexpr char const * value = "xvalue"; };



int main(){
  
  int data;
  cout << "0 is a " << ValueCategory<decltype((0))>::value << endl;
  cout << "data is a " << ValueCategory<decltype((data))>::value << endl;
  cout << "data + 0 is a " << ValueCategory<decltype((data + 0))>::value << endl;
  cout << "data +=0 is a " << ValueCategory<decltype((data +=0))>::value << endl;
  cout << "data ++ is a " << ValueCategory<decltype((data ++))>::value << endl;
  cout << "++ data is a " << ValueCategory<decltype((++data))>::value << endl;

  return  0;
}