#include<iostream>
using namespace std;


typedef int Item;
#define key(A)(A)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {Item T = B; B=A; A=T;}
#define compexch(A,B) (if(less(B,A) exch(A,B)))

void selectionSort(Item *v, int l, int r);


int main(){
    cout << "Hello World" << endl;
    int v[14] = {95,62,61,63,64,50,70,75,93,0,1,2,3,45};
    int l = 0;
    int r = 14;
    selectionSort(v, l, r);
    for (int i = 1; i <= 14; i++)
    {
        cout << v[i] << " ";
    }
    
    return 0;
}

void selectionSort(Item *v, int l, int r){
    int i, j;
    for(i=l; i < r; i++){
        int menor = i;
        for(j=i+1; j<=r; j++){
            if(less(v[j], v[menor])){
                menor = j;
            }
        }exch(v[menor], v[i]);
    }

}