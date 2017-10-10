#include "Linked_list2.h"

using namespace std;

template< class T >
Linked_list< T >::Linked_list()
{

    _pHead = new List_node<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;
    _length =0;
}

template< class T >
Linked_list< T >::Linked_list(const Linked_list<T>& L)
{
    _length =0;
    _pHead = new List_node<T>;
    _pHead->_pNext = _pHead;
    _pHead->_pPrev = _pHead;

    if (!L.empty())
    {
        position p = L.last();
        for (int i=0; i <L._length; i++) //jo baraz ktu e kishte bo gabim
        {
            insert(L.read(p), begin());
            p = L.previous(p);
        }
    }
/*    //ose kshu
    if (!L.empty())
    {
        position p = L.begin();
        for (int i=0; i < L._length; i++)
        {
            insert(L.read(p),_pHead);
            p = L.next(p);
        }
    }
*/
}

template< class T >
Linked_list< T >::~Linked_list()
{

    while(!empty())
        erase(begin());

    delete _pHead;

}


template< class T >
void Linked_list< T >::create()
{
    if (empty())
        _length = 0;
}


template< class T >
bool Linked_list< T >::empty() const
{
    return(_pHead == _pHead->_pNext);
}


template< class T >
typename Linked_list< T >::position Linked_list< T >::begin() const
{
    return (_pHead->_pNext);
}


template< class T >
typename Linked_list< T >::position Linked_list< T >::last() const
{
    return (_pHead->_pPrev);
}


template< class T >
typename Linked_list< T >::position Linked_list< T >::next(position p) const
{
  if (p != _pHead)
    return(p->_pNext);
}


template< class T >
typename Linked_list< T >::position Linked_list< T >::previous(position p) const
{
    if (p != _pHead)  //mendoj se duhet te jet p->prev!=_pHead, qe te mos kthej ate node qe permban prev dhe next
        return(p->_pPrev);
}


template< class T >
bool Linked_list< T >::end(position p) const
{
    return(p == _pHead);
}

template< class T >
typename Linked_list< T >::value_type Linked_list< T >::read(position p) const
{
    if (!end(p))
        return(p->_value);
}


template< class T >
void Linked_list< T >::write(const value_type &a, position p)
{
    if (!end(p))
        p->_value = a;
}

template< class T >
void Linked_list< T >::insert(const value_type &a, position p)
{

    position t = new List_node<T>;

    t->_value = a;
    t->_pNext = p;
    t->_pPrev = p->_pPrev;
    p->_pPrev->_pNext = t;
    p->_pPrev = t;
    _length++;

}

template< class T >
void Linked_list< T >::erase(position p)
{
    if (!empty() && !end(p)) ///duhet ta kontrollojm kete e ndryshme nga empty dhe end sepse fshim qelizen qe mban dhe previos dhe next(qe ska vler)
    {        ///nuk eshte me NULL kjo
        p->_pPrev->_pNext = p->_pNext;
        p->_pNext->_pPrev = p->_pPrev;
        delete p;
    }
}

template<class T>
Linked_list<T>& Linked_list<T>::operator=(const Linked_list<T>& L)
{

    if (this != &L)
    {
        /*  duhet ta  fshish njeher listen eksiztuese
         while(!empty())
        erase(begin());
          delete _pHead; */

        _length = 0; ///edhe kjo gabim duhet ta heqesh dhe ta besh length 0 sepse e inkremento insert
        _pHead = new List_node<T>;
        _pHead->_pNext = _pHead;
        _pHead->_pPrev = _pHead;
//cout << L.empty();
//cout << L.size();
        if (!L.empty())
        {
            position p = L.last();
            for (int i=0; i < L.size(); i++)
            {
//cout << i, L.read(p);
                insert(L.read(p), begin());
                p = L.previous(p);
            }
        }
    }
    return *this;///per lidhje ne kaskade
}

template<class T>
bool Linked_list<T>::operator==(const Linked_list<T> &L) const
{

    if (L.size() != _length)
        return false;

    position p, pL;
    p = begin();
    pL = L.begin();
    while (!end(p))
    {
        if (p->_value != pL->_value)
            return false;

        p = p->_pNext;
        pL = pL->_pNext;
    }
return true;
}

template<class T>
void Linked_list<T>::reverse()
{
 position p=begin();
 position afterP=p->_pNext;
 while(!end(p))
 {
     p->_pNext=p->_pPrev;
     p->_pPrev=afterP;

     p=afterP;
     afterP=afterP->_pNext;

 }
p->_pNext=p->_pPrev;
p->_pPrev=afterP;

}

template<class T>
void Linked_list<T>::reverseRek(position current)
{

    if(end(current->_pNext)) ///nodi i fundit
    {
        _pHead->_pPrev=_pHead->_pNext;
        _pHead->_pNext=current;
        position afterCurr=current->_pNext;
        current->_pNext=current->_pPrev;
        current->_pPrev=afterCurr;
        return;

    }
    reverseRek(current->_pNext);

        position afterCurr=current->_pNext;
        current->_pNext=current->_pPrev;
        current->_pPrev=afterCurr;
}

template<class T>
void Linked_list<T>::rendit()
{
    for( position p=begin();!end(p->_pNext);p=p->_pNext)
        for(position q=p->_pNext;!end(q);q=q->_pNext)
        if(p->_value > q->_value)
    {
        T temp=p->_value;
        p->_value=q->_value;
        q->_value=temp;
    }
}

template<class T>
void Linked_list<T>::merge(const Linked_list<T> &other)
{
    position p=other.begin();
    while(!other.end(p)){
    insert(read(p),_pHead);
    p=p->_pNext;
    }
}

template<class T>
Linked_list<T> Linked_list<T>::mergeIfSort(const Linked_list<T> &other)
{
    Linked_list<T> temp;
    position p1=begin();
    position p2=other.begin();

    while(!end(p1) && !other.end(p2))
    {
        if(p1->_value<p2->_value){
               insert(p1->_value,temp._pHead);
               p1=p1->_pNext;
        }
        else {
            insert(p2->_value,temp._pHead);
               p2=p2->_pNext;
        }

    }
    if(end(p1))
        while(!other.end(p2))
        {
            insert(p2->_value,temp._pHead);
               p2=p2->_pNext;
        }
    else if(other.end(p2))
    while(!end(p1))
        {
            insert(p1->_value,temp._pHead);
               p1=p1->_pNext;
        }

    return temp;

}


template<class T>
Linked_list<T> Linked_list<T>::operator+(const Linked_list<T> &other){

Linked_list<T> temp(*this); //krijojm nje objekt temp si kopje te objektit ku jemi
temp.merge(other);
return temp;
}

template<class T>
int Linked_list<T>::distanca(position p1,position p2)
{
    int nr=0;
    p1=p1->_pNext;
    while(p1!=p2)
    {
        nr++;
        p1=p1->_pNext;

    }
    return  nr;
}

template<class T>
void Linked_list<T>::swap(position p1,position p2)
{
    T temp=p1->_value;
    p1->_value=p2->_value;
    p2->_value=temp;
}


template<class T>
void Linked_list<T>::zhvendosMaxMin()
{
    position p=begin();
    position minn,maxx;
    T min=p->_value;
    T max=p->_value;

    while(!end(p))
    {
        if(p->_value<min)
        {
            min=p->_value;
            minn=p;
        }
        if(p->_value>max)
            {
            max=p->_value;
            maxx=p;
            }

        p=p->_pNext;
        }
            swap(begin(),maxx);
            swap(last(),minn);

}


template<class T>
void Linked_list<T>::fshiEleListes(const Linked_list<T> & other)
{
    position p1=begin();
    position p2=other.begin(); //per listen tjeter

    while(!other.end(p2))
          {
            p1=begin();
                while(!end(p1))
               {

                p1=p1->_pNext;
                    if(p1->_pPrev->_value==p2->_value)
                    erase(p1->_pPrev);

             ///edhe po ta besh kte p1=p1->_pNext ktu fnksiono po nuk eshte tamam e sakt sepse ti e ke fshir nga heap por e akseson prap eshte po kuptim po ajo vler ngelet ne memorie prandaj askseseohet
                }
                p2=p2->_pNext;
          }
}

template<class T>
void Linked_list<T>::fshiEleListesRenditur(const Linked_list<T> &other)
{
    position p1=begin();
    position afterP1;
    position p2=other.begin();

    while(!other.end(p2)&& !end(p1))
    {
        if(p1->_value==p2->_value)
          {
            afterP1=p1->_pNext;  ///duhet ta rujm p1->_next sepse p1 fshihet
            erase(p1);
            p1=afterP1;
          }
        else if(p1->_value > p2->_value)
            p2=p2->_pNext;
        else if(p1->_value < p2->_value)
            p1=p1->_pNext;
    }

}

template<class T>
bool Linked_list<T>::isElement(const value_type &x)
{
    position p1=begin();
    while(!end(p1))
    {
        if(p1->_value==x)
            return true;

        p1=p1->_pNext;
    }
    return false;
}
template<class T>
void Linked_list<T>::deleteEl(const value_type & x)
{
     position p1=begin();
     position afterP1;
     while(!end(p1))
     {
         if(p1->_value==x)
         {
             afterP1=p1->_pNext;  ///duhet ta rujm p1->_next sepse p1 fshihet
             erase(p1);
             p1=afterP1;
         }
         else p1=p1->_pNext;
     }

}

template<class T>
struct element<T> Linked_list<T>::eshteEl(const value_type & x)
{
struct element<T> temp;

position p1=begin();
while(!end(p1))
     {
         if(p1->_value==x)
         {
             temp.is=true;
             temp.pos=p1;
             return temp;
         }
         p1=p1->_pNext;
     }
     temp.is=false;
     temp.pos=NULL;
       return temp;
}

template<class T>
bool Linked_list<T>::isSublist(const Linked_list<T> & other)
{
    position q=other.begin();
    position p;
    bool flag=false;

    while(!other.end(q)) //per cdo el te listes tjter shohim a eshte ne kete list
    {
        p=this->begin(); //fillojme nga fillimi gjithmon
        flag=false;

        while(!this->end(p))
        {
            if(q->_value==p->_value)
            {
                flag=true;
                break;
            }
            p=p->_pNext;
        }
        if(flag==true) //do te thote qe ai element ka qene shohim per tjetrin
          q=q->_pNext;
        else break; //nqs ky element ska qen,nqs te pakten 1 skaqen bejme break dhe kthejme
    }

    return flag;
}

template class Linked_list<int>;
template class Linked_list<float>;











