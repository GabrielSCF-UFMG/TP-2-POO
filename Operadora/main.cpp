#include <iostream>
#include<vector>
#include<algorithm>
#include<time.h>
#include<stdlib.h>

using namespace std;

int main()
{

    vector <int> numero;
    int i=0;
   for(int k=0;k<15;k++) {
     srand( (unsigned)time(NULL) );
         for( i=0 ; i <8 ; i++)
                  numero.push_back(rand()%10);


        unsigned semente=unsigned  (rand());
         srand( semente);
         int sorte=rand() %100;
        if(sorte%2==0)
           std::random_shuffle ( numero.begin(),numero.end() );
         if(sorte%3==0)
           std::random_shuffle ( numero.begin(),numero.end() );
         if(sorte%5==0)
           std::random_shuffle ( numero.begin(),numero.end() );

         for( i=0 ; i <8 ; i++)
               cout<<numero[i];
         cout<<endl;
   }

    return 0;
}
