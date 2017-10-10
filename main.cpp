#include "Linked_list2.h"
#include "Linked_list2.cpp"
#include <iostream>
#include <cstdlib>
using namespace std;
//krijo nje funksion qe merr nje rradh dhe kthen nje rradhe me vlerat e saj positive pa ndryshuar te paren
int main(){

Linked_list<int> list1, list2,list10;

Linked_list<int>::position iter;

/* shtohen kater elementet ne listen list1 */

for(int x=1;x<=4;x++)
list1.insert(x, list1.fund());

for(int x=-1;x<=2;x++)
list10.insert(x, list10.fund());

cout<<endl<<"a eshte list 10 sublist e list1 : " << list1.isSublist(list10);
//prova qe a eshte nje element duke e marr ne strukture

struct element<int> x;

x=list1.eshteEl(1);
list1.insert(9,x.pos);

cout<<endl<<"po printojme vlerat e struktures  "<<x.is<<endl;

/* afishimi i elementeve te list1 */

cout <<endl<< "list1="<< list1;
list1.reverseRek(list1.begin());
cout << "list1="<< list1;

Linked_list<int> list4;
for(int i=0;i<10;i++)
    list4.insert(rand()%10, list4.begin());

cout<<"list4="<<list4;

list4.zhvendosMaxMin();

cout<<"lista 4 pasi eshte zhvendosur max ne fillim  dhe min ne fund="<<list4;

list4.fshiEleListes(list1);

cout<<"Lista 4 pasi jane fshire el qe ndodhen ne listen 1:"<<list4;


for(int i=0;i<10;i++)
    list4.insert(i,list4.fund());

cout<<endl<<list4.isElement(-9)<<endl;

list4.deleteEl(8);
list4.rendit();
cout<<"Lista 4 ne kete pikee renditur eshte:"<<list4;

///list 1 eshte e renditur ne kete pike

list4.fshiEleListesRenditur(list1);
cout<<"Lista 4 pasi jane fshire el qe ndodhen ne listen 1,kur te dyja kane qene te renditura eshte :"<<list4;


list1.merge(list4);
cout<<"lista 1 pasi eshte bashkuar me listen 4:"<<list1;


Linked_list<int> list5;
list5=list1+list4;
cout<<"lista5="<<list5;

Linked_list<int> list6, list7;
for(int i=0;i<10;i++)
{
    list6.insert(i,list6.fund());
    list7.insert(i*2,list7.fund());
}

Linked_list<int> list8(list6.mergeIfSort(list7));

cout<<"list8="<<list8;
iter=list8.begin();

for(int i=0;i<5;i++)
    iter=list8.next(iter);

cout<<"distanca="<<list8.distanca(list8.begin(),iter);

Linked_list<int> list3(list1);

cout<<endl<<(list1==list3);

cout<<endl<<"list3=" ;
cout<<list3;


list2 = list1;

cout <<endl<< "Pasi list2=list1, list2="; cout << list2;

/* perdoret operatori i bere overload == */

if (list1 == list2)

cout << "list1 == list2" << endl;

else

cout << "list1 != list2" << endl;

list2.erase(list2.begin());

cout << "Pas fshirjes se elementit te pare, list2="; cout << list2;

/* perdoret operatori i bere overload == */

if (list1 == list2)

cout << "list1 == list2" << endl;

else

cout << "list1 != list2" << endl;



}
