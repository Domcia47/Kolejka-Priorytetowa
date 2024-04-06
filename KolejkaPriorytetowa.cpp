#include <iostream>
#include <stdexcept>
#include "KolejkaPriorytetowa.h"

using namespace std;

int calcParentsIndex(int index){
    return (index - 1) / 2;
}
int calcLeftChildIndex(int index){
    return 2*index+1;   
}
int calcRightChildIndex(int index){
    return 2*index+2;   
}

KolejkaPriorytetowa::KolejkaPriorytetowa(int size)  : tab( new int[size]), num_elem(0){};
KolejkaPriorytetowa::KolejkaPriorytetowa()  : tab( new int[1000000]), num_elem(0){};
int KolejkaPriorytetowa::getNumElem(){
    return num_elem;
}
void KolejkaPriorytetowa::insert(int x){
    if(num_elem == 0){
        tab[0] = x;
        num_elem++;
        return;
    }

    int index = num_elem;
    tab[index] = x;
    num_elem++;

    while(index != 0){
        int parentIndex = calcParentsIndex(index);
        if(tab[index] < tab[parentIndex]){
            swap(tab[index], tab[parentIndex]);
            index = parentIndex;
        }
        else{
            break;
        }
    }
}
int KolejkaPriorytetowa::RemoveRootElem(){
    if(num_elem==0){
        throw std::underflow_error("Trying to remove from an empty structure");
    }
    if(num_elem==1){
        num_elem = 0;
        return tab[0];
    }
    if(num_elem==2){
        int temp = tab[0];
        tab[0]=tab[1];
        num_elem--;
        return temp;
    }
    int temp = tab[0];
    tab[0]= tab[--num_elem];
    int index = 0;
    int child_1 = 1;
    int child_2 = 2;
    int prev_child_1;
    int prev_child_2;
    while(child_1<num_elem && child_2<num_elem){
        if(tab[index]>tab[child_1]||tab[index]>tab[child_2]){
            if(tab[child_1]<tab[child_2]){
                swap(tab[index],tab[child_1]);
                index=child_1;
            }
            else{
                swap(tab[index],tab[child_2]);
                index=child_2;
            }
        }
        else break;
        //obliczenie nowych indesków dzieci 
        child_1=calcLeftChildIndex(index);
        child_2=calcRightChildIndex(index);
        
    }
    if(child_1<num_elem){
        if(tab[child_1]<tab[index]){
            swap(tab[child_1],tab[index]);
        }
    }
    return temp;

}
void KolejkaPriorytetowa::print(){
    for(int i = 0; i< num_elem; i++){
        std::cout<<tab[i]<<" ";
    }
    std::cout<<std::endl;
}
int KolejkaPriorytetowa::getRootElem(){
    if(num_elem<=0){
        throw std::underflow_error("Trying to remove from an empty structure");
    }
    return tab[0];
}

int main() {
    
    KolejkaPriorytetowa kolejka;

    kolejka.insert(6);
    kolejka.insert(3);
    kolejka.insert(21);
    kolejka.insert(142);
    kolejka.insert(-12);
    kolejka.insert(21);
    kolejka.insert(25);
    kolejka.insert(17);
    kolejka.insert(1);


for(int i=0;i<12;i++)
{
    cout << kolejka.getRootElem() << " ";
    kolejka.RemoveRootElem();
}

}