#pragma once
#include <array>
#include <vector>
using namespace std;


class KolejkaPriorytetowa
{   
    private:
    int *tab;
    int num_elem;
    
    public:
    int getNumElem();
    void insert(int x);
    int RemoveRootElem();
    void print();   //opcjonalnie dla wy�wietlenia kolejnych element�w macierzy, w kt�rej trzymany jest kopiec.
    int getRootElem();
    KolejkaPriorytetowa(int size);
    KolejkaPriorytetowa();
    
};