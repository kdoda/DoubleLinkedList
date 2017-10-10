#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <iostream>

using namespace std;

template< class T >
struct List_node
{
    T _value;
    List_node<T> * _pPrev;
    List_node<T> * _pNext;

};

template< class T >
struct element
{
    bool is;
   List_node<T>* pos;

};


template<class T>
class Linked_list
{

public:
    typedef T value_type;
    typedef List_node<T>* position;

// konstruktoret
    Linked_list();
    Linked_list(int);
// konstruktori i kopjes
    Linked_list(const Linked_list<T>& );
//destruktori
    ~Linked_list();

// operatoret
    void create();
    bool empty() const;
    value_type read(position) const;
    void write(const value_type &, position);
    position begin() const;
    position last() const;
    bool end(position) const;
    position next(position) const;
    position previous(position) const;
    void insert(const value_type &, position);
    void erase(position);
    int size() const
    {
        return _length;
    };
    position fund() const
    {
        return _pHead;
    };
    void reverse();              ///ben reverse listes
    void reverseRek(position p); ///duhet te marri begin() el e par
    void rendit();               ///rendit rend rrites
    void merge(const Linked_list<T> &); ///i bahkon te lista qe e therret pa e fshire listen tj
    Linked_list<T> mergeIfSort(const Linked_list<T> &); ///merr list te renditur ne rend rrites dhe i kthen te dyja te bashkuara
    int distanca(position,position);  ///kthen nr e el midis dy pointer(pa i perfshire ato)ku poiteri i dyte eshte djthtas p1 (mund ta bej dhe pa e dit si eshte po spo e bej)
    void swap(position,position);
    void zhvendosMaxMin();  ///leficent zhvendos max ne fillim dhe min ne fund
    void fshiEleListes(const Linked_list<T> &);  ///fshin elementet te lista qe e therret te cilet jan te lista qe merr si parameter O(n*m)
    void fshiEleListesRenditur(const Linked_list<T> &);///kerkesa si siper po listat jane te renditura O(n+m)
    bool isElement(const value_type &);  ///kthen true nqs el ndodhet ne liste
    void deleteEl(const value_type &);   ///fshin te gjithe elementet me kete vlere
    struct element<T> eshteEl(const value_type &);///merr vler dhe kthe sruktur true nqs eshte dhe pozicionin
    bool isSublist(const Linked_list<T> &); //shikon nqs lista qe kemi marre eshte nenliste e listes tone

// overload i operatoreve
//e kthen me reference sepse objekti eshte krijuar tashem kur therritet operatori = ,dhe kthejm vet ato jo nje kopje te atij
    Linked_list<T>& operator=(const Linked_list<T>&); // operatori i vleredhenies
    bool operator==(const Linked_list<T> &) const; // kontrollon dy lista per barazi
    Linked_list<T> operator+(const Linked_list<T> &other); //ben merge dy lista dhe kthen nje te tret pa i ndryshuar ato

    friend std::ostream& operator<<(ostream& os, const Linked_list<T> &l)
    {

        position p;
        p = l.begin();
        os << "[";

        while (!l.end(p))
        {

            if (p != l.begin())
                os << ", " << l.read(p);
            else
                os << l.read(p);
            p = l.next(p);
        }
        os << "]" << endl;
        return os;
    }

private:
    List_node<T> * _pHead;
    int _length; // gjatesia e listes

};

#endif // _LINKED_LIST_H
