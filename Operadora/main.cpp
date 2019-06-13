#include <iostream>
#include"../Header/Data.h"

using namespace std;

int main()
{
    Data Atual;

    Data A1= Data(1,9,5000);
    Data A=A1;

    cout<<A.getDia() <<" / "<<A.getMes() << " / "<<A.getAno()<<endl;


    return 0;
}
