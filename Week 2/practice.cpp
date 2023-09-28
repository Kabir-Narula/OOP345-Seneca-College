// types sets of  possible values + set of possible operations..
 
//Fundamental types--
// - Integer types: char    short    int    long   long long
// - Float types:  float    double    long double


//Built-in types
// - pointers, arrays,reference types

// Characters in C++
// - UFT8 , UFT16 , UFT32 , UFT64
// - wchar_t, 
//- char16_t, char32_t, char64_t

#include <iostream>
using namespace std;
#include  <iomanip>


/*void dumpMem( void  *p, size_t cnt){
    unsigned char* pC = reinterpret_cast<unsigned char*>(p);
    cout << hex << setfill('0');
    for ( int i = 0; i < cnt; ++i)
    cout << " " << setw(2) << static_cast<unsigned char>(pC[i]);
    cout << dec << setfill(' ') << endl;
} */

 struct foo{

    double m_data = 123.46;
    operator int () const
    {
     return static_cast<int>(m_data);  // conversion to in type from double.
    }
    foo(){ cout << this << endl; }


  
  };



int main ( int , char**){
  
  //double arr[]{ 3.2 , 2.1, 0 };
  //dumpMem(arr ,8);
  //dumpMem(arr ,24);

  // Prefixes for  [ Character]
  //wchar_t str[] { L"I am Levi"};   // need prefix L
  //char16_t str1[] { u"Hi"};  // need prefix u
  //char32_t str2[] { U"hi"};  // need prefix U

  // Postfixes for [ Number ]
  //auto data = 10LL;
  //auto data = 'a'; // single quotation for characters 
  //auto data = "b"; // double quotation for strings
  //auto data = 1.2; // by default double
  //auto data = 1.2f; // to convert to double use postfix [f]

  // Pointers---
  //double *p; // 8-bytes
  //char *str; // 8-bytes   [ same for all pointers]
  //void *ptr; // 8-bytes 

  //*p ;// double types
  //*str; //char types
  //*ptr; //

  //double arr[5] { 3.2,2.1,0};
  //double * P = arr;

  // for (auto i = 0; i < 5; i++)
  //cout << arr[i] << endl;

 // for (double item : arr)
  //cout << item << " ";

  // int data1 = 32;
   //int data2 = 44;

   int data1;
   data1 += foo();
   cout << data1 << endl;  // prints integer type from double 123.46 // 123
   


   //reference_wrapper<int>  refData1 = std:: ref(data1);
   //reference_wrapper<int> refData2 = std::ref(data2);


  //reference_wrapper<int> refArr[2] { std:: ref(data1), std::ref(data2)};

 
  
  return 0;
}