#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main() {
   int rad{5};
   float pi{3.14159};
   float diametro{0};
   float area{0};
   float circunferencia{0};

   diametro=(2*rad);
   area= pi*(rad*rad);
   circunferencia= pi*diametro;

   cout<<"area:"<<area<<"  diametro:"<<diametro<<"  circunferencia:"<<circunferencia<<endl;



}