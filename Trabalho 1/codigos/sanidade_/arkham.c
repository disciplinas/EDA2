#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct sana {
    int visitado;
    unsigned long atual, ant, prox;
}node;

struct sana arraySanidade[1000000];

void mergeSort(unsigned long arr[], int l, int r);
void merge(unsigned long arr[], int l, int m, int r);

void push(unsigned long data); // Function used to insert the element into the stack
void pop(); // Function used to delete the elememt from the stack
void display(); // Function used to display all the elements in the stack according to LIFO rule

int indice(unsigned long arr[],int posix, int arr_size);
unsigned long buscarBin(struct sana* arr, int l, int r, unsigned long x);

unsigned long interpolationSearch(struct sana* arr, int n, unsigned long x);


struct node{
    int data;
    struct node *next;
};

struct node *temp;

int main(){


    int contador = 0;
    while(scanf("%x", &arraySanidade[contador].atual) == 1){
        scanf("%x", &arraySanidade[contador].ant);
        scanf("%x", &arraySanidade[contador].prox);
        contador++;
    }

    unsigned long arrayAtual[contador];
    unsigned long arrayAnt[contador];
    unsigned long arrayProx[contador];

    for(int l = 0; l < contador; l++){
        arrayAtual[l] = arraySanidade[l].atual;
        arrayAnt[l] = arraySanidade[l].ant;
        arrayProx[l] = arraySanidade[l].prox;
    }


    int arr_size = sizeof(arrayAtual)/sizeof(arrayAtual[0]);
    int arr_ant_size = sizeof(arrayAnt)/sizeof(arrayAnt[0]);
    int arr_prox_size = sizeof(arrayProx)/sizeof(arrayProx[0]);
    mergeSort(arrayAtual, 0, arr_size-1);
    mergeSort(arrayAnt, 0, arr_ant_size-1);
    mergeSort(arrayProx, 0, arr_prox_size-1);



    for(int i = 0; i < contador; i++){
        printf("Atual: %d\n", arrayAtual[i]);
        //printf("Anterior: %d\n", arraySanidade[i].ant);
        //printf("Próximo: %d\n", arraySanidade[i].prox);
    }

    int posixPtr1 = indice(arrayAtual, 0, contador);
    int posixPtr2 = indice(arrayAtual, 1, contador);


    printf("Tam: %d\n", posixPtr1);
    printf("Tam: %d\n", posixPtr2);

    int size_t = posixPtr2 - posixPtr1;

    /* for(int l = 1; l < contador; l++){
        for(int k = 1; k < contador; k++){
            if(arraySanidade[l].atual == arrayAtual[k]){
                push(arrayProx[k]);
            }
        }
    }
 */
    display();
    
    return 0;

}

unsigned long buscarBin(struct sana* arr, int l, int r, unsigned long x){
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (arr[mid].atual == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (arr[mid].atual > x) 
            return buscarBin(arr, l, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return buscarBin(arr, mid + 1, r, x); 
    }
    // We reach here when element is not 
    // present in array 
    return -1; 
}

int indice(unsigned long arr[], int posix, int arr_size){
    for (int i = 0; i < arr_size; i++){
        if(arraySanidade[posix].atual == arr[i]){
            return i;
        }
    }
}

void merge(unsigned long arr[], int l, int m, int r) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    unsigned long L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(unsigned long arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void push (unsigned long data){
    struct node *pointer = (struct node*)malloc(sizeof(struct node));
    if(pointer == NULL){
        printf("Stack overflow");
    }
    else{
        if(temp == NULL){
            pointer -> data = data;
            pointer -> next = NULL;
            temp = pointer;
        }
        else{
            pointer -> data = data;
            pointer -> next = temp;
            temp = pointer;
        }
    }
}

void pop(){
    int item;
    struct node *pointer;
    if (temp == NULL){
        printf("Stack Underflow\n");
    }
    else{
        item = temp -> data;
        pointer = temp;
        temp = temp -> next;
        free(pointer);
        printf("The deleted item is %d\n",item);
    }
}

void display(){
    int i;
    struct node *pointer;
    pointer = temp;
    if(pointer == NULL){
        printf("Stack underflow\n");
    }else{
        printf("The elements of the stack are:\n");
        while(pointer!= NULL){
            printf("%d\n",pointer -> data);
            pointer = pointer -> next;
        }
    }
}

unsigned long interpolationSearch(struct sana* arr, int n, unsigned long x) 
{ 
    // Find indexes of two corners 
    int lo = 0, hi = (n - 1); 
  
    // Since array is sorted, an element present 
    // in array must be in range defined by corner 
    while (lo <= hi && x >= arr[lo].atual && x <= arr[hi].atual) 
    { 
        if (lo == hi){ 
            if (arr[lo].atual == x) return lo; 
            return -1; 
        } 
        // Probing the position with keeping 
        // uniform distribution in mind. 
        int pos = lo + (((double)(hi-lo) / 
              (arr[hi].atual-arr[lo].atual))*(x - arr[lo].atual)); 
  
        // Condition of target found 
        if (arr[pos].atual == x) 
            return pos; 
  
        // If x is larger, x is in upper part 
        if (arr[pos].atual < x) 
            lo = pos + 1; 
  
        // If x is smaller, x is in the lower part 
        else
            hi = pos - 1; 
    } 
    return -1; 
} 