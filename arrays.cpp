#include<iostream> // cin , cout , ...
#include<vector> // vectors
#include<iomanip> // input/output format , boolalpha , ...
#include<cmath> // ceil , floor , ...
#include <algorithm> // beging , end , reverse , ...
#include <climits> // INT_MIN , INT_MAX , ...
#include <cctype> // for digit functions
#include <stack> // PUSH , POP , ...
#include <string> // empty() , ...
using namespace std; // Using the standard namespace

//1_ Introduction to array
/*
int main(){
    int A[5]={1,3};
    A[2]=5;
    int size = sizeof(A)/sizeof(A[0]);
    
    // Three ways to print the input
    cout<<A[0]<<endl; // 1
    cout<<1[A]<<endl; // 3
    cout<<*(A+2)<<endl; // 5
    
    cout<<A[3]<<endl; // it will take 0
    cout<<A[7]<<endl; // garbage value
    for(int i=0;i<size;i++){
        cout<<A[i]<<" "; // 1 3 5 0 0 
    }
    for(int i=0;i<size;i++){
        cout<<endl<<&A[i]<<" "; // address
    }
}
*/

                //_________________________________//

//2_ How to increse the array in the heap
// You can take the size of the array from the user in C++ (in running time) but in C language you can't (you must decide it in compiling time)
/*
int main(){
    int *p,*q;
    p=new int[5];
    q=new int[10];
    p[0]=0;
    p[1]=2;
    p[2]=4;
    p[3]=8;
    p[4]=10;
    for(int i=0;i<5;i++){
        q[i]=p[i];
    }
    delete []p; // to avoid memory leak
    p=q;
    p[5]=12; // p or q
    for(int i=0;i<6;i++){
        cout<<p[i]<<" "; // 0 2 4 8 10 12
    }
}
*/

                //_________________________________//

//3_ 2D Array
/*
// three methods to creat 2D array

// Completely in stack
int A[3][4]={
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12}
};
cout<<A[0][3]<<endl; // 4

// Partial in stack, partial in heap
int *B[3];
B[0]=new int[4];
B[1]=new int[4];
B[2]=new int[4];
B[0][3]=4;
cout<<B[0][3]<<endl; // 4

// Mostly in heap
int **arr;
arr=new int*[3];
arr[0]=new int[4];
arr[1]=new int[4];
arr[2]=new int[4];
arr[0][3]=4;
cout<<arr[0][3]<<endl; // 4
*/

                //_________________________________//

//4_ How the address is allocated for element in an array

//Notes

//The compiler uses the address to arrive any element in the array

//The address isn't found in compile time(it's just found in the running time) so the compiler uses a formula to allocate the address

//L0 = the base address(the address of the first element in the array)

//m,n = int arr[m][n]

//i,j = arr[i][j]

//UU = the input size(int -> 4,char -> 1,...)

//In 2D array there're two methods to allocate the address during the compiling time

//1_ row major formula to find the address (int arr[m][n] .. arr[i][j]) -> L0+(i*n+j)*UU "from left to right"

//2_ colomun major formula to find the address(arr[i][j]) -> L0+(j*m+i)*UU "from right to left"

//Ex: int arr[3][4] .. arr[1][2] row-> 200+(1*4+2)*4 coloumn-> 200+(2*3+1)*4

// for normal array the formula is -> L0+i*UU .. Ex: int array[3] -> 200+3*4

// reverse the *quiz*

                //_________________________________//

//5_ Operations ON Arrays
/*
struct array1
{
    int A[10];
    int size;
    int length;
};
void display(struct array1 arr)
{
    if(arr.length==0)
        cout<<"There's no elements in the array!";
    cout<<"The elements are : ";
    for(int i=0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
    }cout<<endl;
}
void append(struct array1 *arr,int x){ // pass the array by address cuz we want to modifiy the array
    if(arr->length<arr->size){ // while passing by address, use (->)
        arr->A[arr->length]=x;
        arr->length++;
    }
}
void insert(struct array1 *arr,int x,int index){
    if(index>=0 && index<=arr->length){
        for(int i=arr->length;i>index;i--){
            arr->A[i]=arr->A[i-1]; // not arr->A[i+1]=arr->A[i] because of the *length*
        }
        arr->A[index]=x;
        arr->length++;
    }
}
void dellete(struct array1 *arr,int index){
    if(index>=0 && index<arr->length){
        for(int i=index;i<arr->length-1;i++){
        arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}
void swap(int *x,int *z){
    int temp = *x;
    *x=*z;
    *z=temp;
}
int linearSearch(struct array1 *arr,int value, int &originalIndex){
    for(int i=0;i<arr->length;i++){
        if(value==arr->A[i]){
            originalIndex = i; // Store the original index
            swap(&arr->A[i],&arr->A[0]);
            return 0; // New index will always be 0
        }
    }
    originalIndex = -1; // If value not found
    return -1;
}
int binarySearch(struct array1 arr2,int low,int high,int key){ // The array should be sorted
while(low<=high){ // = -> if the array has only one element
    int mid = low +(high-low)/2;
    if(arr2.A[mid]==key){
    return mid;
    }else if(key<arr2.A[mid]){
        high = mid-1;
    }
    else{
            low = mid+1;
    }}
    return -1;
}
int RbinarySearch(struct array1 arr2,int low,int high,int key){ // The array should be sorted
    int mid = low +(high-low)/2; // instead of (high+low)/2 to avoid  overflow for large high and low values
    if(low<=high){ // = -> if the array has only one element
        if(arr2.A[mid]==key){
            return mid;
        }else if(key<arr2.A[mid]){
            return RbinarySearch(arr2,low,mid-1,key);
        }else if(key>arr2.A[mid]){
            return RbinarySearch(arr2,mid+1,high,key);
        }
    }
    return -1;
}
int main(){
    struct array1 arr={{1,2,3,4,5},10,5};
    struct array1 arr2={{1,2,3,4,5},10,5};

    display(arr); // The elements are: 1 2 3 4 5  

    append(&arr,10);

    display(arr); // The elements are: 1 2 3 4 5 10

    insert(&arr,10,0);

    display(arr); // The elements are: 10 1 2 3 4 5 10

    dellete(&arr,0);

    display(arr); // The elements are: 1 2 3 4 5 10

    int originalIndex;
    int newIndex = linearSearch(&arr, 4, originalIndex);
    if (newIndex != -1) {
        cout << "The value's found, the original index is: " << originalIndex << ", the new index is: " << newIndex << endl; // 3 , 0
    } else {
        cout << "Value not found in the array." << endl;
    }

    display(arr); // The elements are: 4 1 3 5 10

    display(arr2); // The elements are: 1 2 3 4 5

    int binary = binarySearch(arr2,0,arr2.length-1,3);
    cout<<binary<<endl; // 2

    int binary2 = RbinarySearch(arr2,0,arr2.length-1,8);
    cout<<binary2<<endl; // -1
}
*/

                //_________________________________//

//6_ get(),set(),max(),min(),sum(),avg(),rev() functions
/*
struct array1{
    int A[10];
    int size;
    int length;
};
void display(struct array1 arr){
    if(arr.length<=0){
        cout<<"There's no elements!";
        return; // Exit the function early
    }else{
        cout<<"The elements are : ";
        for(int i =0;i<arr.length;i++){
        cout<<arr.A[i]<<" ";
        }
    }cout<<endl;
}
void set(struct array1 *arr,int index,int value){
    if(index>=0 && index<arr->length){
        arr->A[index]=value;
    }
    else{
        cout<<"Invalid index!";
    }
}
int get(struct array1 arr,int index){
    if(index>=0 && index<arr.length){
        return arr.A[index];
    }
    return -1;
}
int max(struct array1 arr){
    int maxElement = arr.A[0];
    for(int i =1;i<arr.length;i++){
        if(maxElement<arr.A[i]){
            maxElement=arr.A[i];
        }
    }return maxElement;
}
int min(struct array1 arr){
    int minElement = arr.A[0];
    for(int i =1;i<arr.length;i++){
        if(minElement>arr.A[i]){
            minElement=arr.A[i];
        }
    }return minElement;
}
int sum(struct array1 arr){
    int sum=0;
    for(int i=0;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}
double sum2(struct array1 arr){
    int sum=arr.A[0];
    for(int i=1;i<arr.length;i++){
        sum+=arr.A[i];
    }
    return sum;
}
double avg(struct array1 arr){
    double sum=arr.A[0];
    for(int i=1;i<arr.length;i++){
        sum+=arr.A[i];
    }
    double average = sum/arr.length;
    return average;
}
double avg2(struct array1 arr){
    double average = sum2(arr)/arr.length;
    return average;
}
void rev(struct array1 *arr){
    int i,j;
    int *b = new int[arr->length];
    for(i=0;i<arr->length;i++){
        b[i]=arr->A[arr->length-1-i];
    }for(i=0;i<arr->length;i++){
        arr->A[i]=b[i];
    }
    delete[]b;
}
void rev2(struct array1 *arr){
    int i,j,temp;
    for(i=0,j=arr->length-1; i<j; i++, j--){
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}
int main(){
    struct array1 arr = {{2,3,7,4,3,9},10,6};

    display(arr); // 2 3 7 4 3 9

    int getValue = get(arr,2);
    cout<<getValue<<endl; // 7

    set(&arr,2,2);

    display(arr); // 2 3 2 4 3 9

    cout << "Max: " << max(arr) << endl; // 9
    cout << "Min: " << min(arr) << endl; // 2
    cout << "Sum: " << sum(arr) << endl; // 23
    cout << "Avg: " << avg(arr) << endl; // 3.83333
    cout << "Avg2: " << avg2(arr) << endl; // 3.83333

    rev(&arr);
    display(arr); // 9 3 4 2 3 2

    rev2(&arr);
    display(arr); // 2 3 2 4 3 9
}
*/

                //_________________________________//

//7_ Insert an element in a sorted array , Check if the array is sorted , Cheft the - elements to the left of the array
/*
struct array1{
    int A[10];
    int size;
    int length;
};
void display(struct array1 arr1){
    // Validation
    if(arr1.length<=0){
        cout<<"Invalid array!";
        return;
    }else{
        cout<<"The elements are : ";
        for(int i = 0;i<arr1.length;i++){
            cout<<arr1.A[i]<<" ";
        }
    }cout<<endl;
}
void insertElement(struct array1 *arr1,int value){
    int i = arr1->length -1;
    if(arr1->length >= arr1->size){
        cout<<"Invalid array!";
        return;
    }
    while(i>=0 && arr1->A[i]>value){
        arr1->A[i+1] = arr1->A[i];
        i--;
    }arr1->A[i+1]=value;
    arr1->length++;
}
void ifSorted(struct array1 arr1){
    for(int i = 0;i<arr1.length-1;i++){
        if(arr1.A[i]>arr1.A[i+1]){
            cout<<"The array is not sorted";
            return;
        }
    }cout<<"The array is sorted"<<endl;
}
void shift_minus_to_left(struct array1 *arr4){
    int i=0;
    int j = arr4->length-1;
    while(i<j){
        while(arr4->A[i]<0)
            i++;
        while(arr4->A[j]>0)
            j--;
        if(i<j){
            int temp = arr4->A[i];
            arr4->A[i] = arr4->A[j];
            arr4->A[j] = temp;
        }
    }
}
int main(){
    struct array1 arr2 = {{2,4,5,7,8,9},10,6};
    struct array1 arr3 = {{2,-4,5,-7,8,-9},10,6};

    display(arr2); // 2 4 5 7 8 9
    insertElement(&arr2,6);
    display(arr2); // 2 4 5 6 7 8 9
    ifSorted(arr2); // The array is sorted
    shift_minus_to_left(&arr3);
    display(arr3); // -9 -4 -7 5 8 2
}
*/

                //_________________________________//

//8_ Merging , Union , Intersection and Difference operations in two sorted arrays to one sorted array
/*
struct array2{
    int B[10];
    int size;
    int length;
};

void display(struct array2 arr1){
    // Validation
    if(arr1.length<=0){
        cout<<"Invalid array!";
        return;
    }else{
        cout<<"The elements are : ";
        for(int i = 0;i<arr1.length;i++){
            cout<<arr1.B[i]<<" ";
        }
    }cout<<endl;
}

struct array2 *merge(struct array2 *arr,struct array2 *arr2){
    // creat the third array in heap
    struct array2 *arr3 = new array2;
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j < arr2->length){
        if(arr->B[i]<arr2->B[j]){
            arr3->B[k++] = arr->B[i++];
        }else{
            arr3->B[k++] = arr2->B[j++];
        }
    }
    // If there're elements yet in arr
    while(i<arr->length){
        arr3->B[k++]=arr->B[i++];
    }
    // If there're elements yet in arr2
    while(j<arr2->length){
        arr3->B[k++]=arr2->B[j++];
    }
    // Set the size of arr3
    arr3->size = arr->size + arr2->size;
    // Set the length of arr3
    arr3->length = arr->length + arr2->length;
    return arr3;
}

struct array2 *uniion(struct array2 *arr,struct array2 *arr2){ // Like merge but without duplicates
    // creat the third array in heap
    struct array2 *arr3 = new array2;
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j < arr2->length){
        if(arr->B[i]<arr2->B[j]){
            arr3->B[k++] = arr->B[i++];
        }else if(arr2->B[j]<arr->B[i]){
            arr3->B[k++] = arr2->B[j++];
        }else{
            arr3->B[k++] = arr->B[i++];
            j++;
        }
    }
    // If there're elements yet in arr
    while(i<arr->length){
        arr3->B[k++]=arr->B[i++];
    }
    // If there're elements yet in arr2
    while(j<arr2->length){
        arr3->B[k++]=arr2->B[j++];
    }
    // Set the size and the length of arr3
    arr3->size = arr->size + arr2->size;
    arr3->length = k;
    return arr3;
}

struct array2 *intersection(struct array2 *arr,struct array2 *arr2){ // Like merge but without duplicates
    // creat the third array in heap
    struct array2 *arr3 = new array2;
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j < arr2->length){
        if(arr->B[i]<arr2->B[j]){
            i++;
        }else if(arr2->B[j]<arr->B[i]){
            j++;
        }else if(arr->B[i]==arr2->B[j]){
            arr3->B[k++] = arr->B[i++];
            j++;
        }
    }
    // Set the size and the length of arr3
    arr3->size = arr->size + arr2->size;
    arr3->length = k;
    return arr3;
}

struct array2 *difference(struct array2 *arr,struct array2 *arr2){ // Like merge but without duplicates
    // creat the third array in heap
    struct array2 *arr3 = new array2;
    int i,j,k;
    i=j=k=0;
    while(i<arr->length && j < arr2->length){
        if(arr->B[i]<arr2->B[j]){
            arr3->B[k++] = arr->B[i++];
        }else if(arr2->B[j]<arr->B[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    // If there're elements yet in arr
    while(i<arr->length){
        arr3->B[k++]=arr->B[i++];
    }
    // Set the size and the length of arr3
    arr3->size = arr->size + arr2->size;
    arr3->length = k;
    return arr3;
}

int main(){
    struct array2 arr3 = {{2,4,6,8},10,4};
    struct array2 arr4 = {{2,5,6,9},10,4};

    struct array2* p = merge(&arr3,&arr4);
    struct array2* p2 = uniion(&arr3,&arr4);
    struct array2* p3 = intersection(&arr3,&arr4);
    struct array2* p4 = difference(&arr3,&arr4);

    for(int i=0;i<p->length;i++){
        cout<<p->B[i]<<" "; // 2 2 4 5 6 6 8 9
    }cout<<endl;
    display(*p2); // 2 4 5 6 8 9
    display(*p3); // 2 6
    for(int i=0;i<p4->length;i++){
        cout<<p4->B[i]<<" "; // 4 8
    }cout<<endl;

    delete p;
    delete p2;
    delete p3;
    delete p4;
}
*/

                //_________________________________//

//9_ Convert a C Program to a C++ Menu Driver Program
/*
class array2{
private:
    int *B;
    int size;
    int length;
    void swap(int *x,int *z);
public:
    // Default constructor
    array2(){
        size=100;
        length=0;
        B = new int[size];
        
    }
    // Parameterized constructor
    array2(int sz){
        size=sz;
        length=0;
        B = new int[size];
    for (int i = 0; i < size; i++) {
        B[i] = 0;
    }
    }
    // Destructor
    ~array2(){
        delete[]B;
    }
    void clear();
    void display();
    void set(int index,int value);
    int get(int index);
    int max();
    void insertElement(int value);
    void ifSorted();
    void shift_minus_to_left();
    void append(int x);
    void insert(int x,int index);
    void dellete(int index);
    int linearSearch(int value, int &originalIndex);
    int binarySearch(int low,int high,int key);
    int RbinarySearch(int low,int high,int key);
    array2 *merge(array2 arr2);
    array2 *uniion(array2 arr2);
    array2 *intersection(array2 arr2);
    array2 *difference(array2 arr2);
};

    
void array2::display(){
    // Validation
    if(length<0){
        cout<<"Invalid array!"<<endl;
        return;
    }else if (length==0){
        cout<<"The array is empty yet!"<<endl;
        return;
    }else{
        cout<<"The elements are : ";
        for(int i = 0;i<length;i++){
            cout<<B[i]<<" ";
        }
    }cout<<endl;
}
void array2::swap(int *x,int *z){
    int temp = *x;
    *x=*z;
    *z=temp;
}
void array2::set(int index, int value){
    if(index >= 0 && index < size){
        B[index] = value;
        if(index >= length){
            length = index + 1;
        }
    }
}
void array2::clear() {
    length=0;
}
int array2::get(int index){
    if(index>=0 && index<length){
        return B[index];
    }
    return -1;
}
int array2::max(){
    int maxElement = B[0];
    for(int i =1;i<length;i++){
        if(maxElement<B[i]){
            maxElement=B[i];
        }
    }return maxElement;
}
void array2::insertElement(int value){
    int i = length -1;
    if(length >= size){
        cout<<"Invalid array!"<<endl;
        return;
    }
    while(i>=0 && B[i]>value){
        B[i+1] = B[i];
        i--;
    }B[i+1]=value;
    length++;
}
void array2::ifSorted(){
    for(int i = 0;i<length-1;i++){
        if(B[i]>B[i+1]){
            cout<<"The array is not sorted"<<endl;
            return;
        }
    }cout<<"The array is sorted"<<endl;
}
void array2::shift_minus_to_left(){
    int i=0;
    int j = length-1;
    while(i<j){
        while(B[i]<0)
            i++;
        while(B[j]>0)
            j--;
        if(i<j){
            int temp = B[i];
            B[i] = B[j];
            B[j] = temp;
        }
    }
}
void array2::append(int x){
    if(length<size){
        B[length]=x;
        length++;
    }
}
void array2::insert(int x,int index){
    if(index>=0 && index<=length){
        for(int i=length;i>index;i--){
            B[i]=B[i-1]; // not A[i+1]=A[i] because of the *length*
        }
        B[index]=x;
        length++;
    }
}
void array2::dellete(int index){
    if(index>=0 && index<length){
        for(int i=index;i<length-1;i++){
        B[i]=B[i+1];
        }
        length--;
    }
}
int array2::linearSearch(int value, int &originalIndex){
    for(int i=0;i<length;i++){
        if(value==B[i]){
            originalIndex = i; // Store the original index
            swap(&B[i],&B[0]);
            return 0; // New index will always be 0
        }
    }
    originalIndex = -1; // If value not found
    return originalIndex;
}
int array2::binarySearch(int low,int high,int key){ // The array should be sorted
while(low<=high){ // = -> if the array has only one element
    int mid = low +(high-low)/2;
    if(B[mid]==key){
    return mid;
    }else if(key<B[mid]){
        high = mid-1;
    }
    else{
            low = mid+1;
    }}
    return -1;
}
int array2::RbinarySearch(int low,int high,int key){ // The array should be sorted
    int mid = low +(high-low)/2; // instead of (high+low)/2 to avoid  overflow for large high and low values
    if(low<=high){ // = -> if the array has only one element
        if(B[mid]==key){
            return mid;
        }else if(key<B[mid]){
            return RbinarySearch(low,mid-1,key);
        }else if(key>B[mid]){
            return RbinarySearch(mid+1,high,key);
        }
    }
    return -1;
}
array2* array2::merge(array2 arr2){
    // creat the third array in heap
    array2 *arr3 = new array2(length+arr2.length); // If we wrote length+arr2.length, then we don't need to set the size of arr3 at the end
    int i,j,k;
    i=j=k=0;
    while(i<length && j < arr2.length){
        if(B[i]<arr2.B[j]){
            arr3->B[k++] = B[i++];
        }else{
            arr3->B[k++] = arr2.B[j++];
        }
    }
    // If there're elements yet in arr
    while(i<length){
        arr3->B[k++]=B[i++];
    }
    // If there're elements yet in arr2
    while(j<arr2.length){
        arr3->B[k++]=arr2.B[j++];
    }
    // Set the length of arr3
    arr3->length = k;
    // arr3->size = size + arr2.size; We don't have to give a size cuz we already gave the size
    return arr3;
}
array2* array2::uniion(array2 arr2){ // Like merge but without duplicates
    // creat the third array in heap
    array2 *arr3 = new array2(length+arr2.length);
    int i,j,k;
    i=j=k=0;
    while(i<length && j<arr2.length){
        if(B[i]<arr2.B[j]){
            arr3->B[k++] = B[i++];
        }else if(arr2.B[j]<B[i]){
            arr3->B[k++] = arr2.B[j++];
        }else{
            arr3->B[k++] = B[i++];
            j++;
        }
    }
    // If there're elements yet in arr
    while(i<length){
        arr3->B[k++]=B[i++];
    }
    // If there're elements yet in arr2
    while(j<arr2.length){
        arr3->B[k++]=arr2.B[j++];
    }
    // Set the length of arr3
    arr3->length = k;
    return arr3;
}

array2* array2::intersection(array2 arr2){ // Like merge but without duplicates
    // creat the third array in heap
    array2 *arr3 = new array2();
    int i,j,k;
    i=j=k=0;
    while(i<length && j < arr2.length){
        if(B[i]<arr2.B[j]){
            i++;
        }else if(arr2.B[j]<B[i]){
            j++;
        }else if(B[i]==arr2.B[j]){
            arr3->B[k++] = B[i++];
            j++;
        }
    }
    // Set the size and the length of arr3
    arr3->size = size + arr2.size;
    arr3->length = k;
    return arr3;
}

array2* array2::difference(array2 arr2){ // Like merge but without duplicates
    // creat the third array in heap
    array2 *arr3 = new array2(length + arr2.length);
    int i,j,k;
    i=j=k=0;
    while(i<length && j < arr2.length){
        if(B[i]<arr2.B[j]){
            arr3->B[k++] = B[i++];
        }else if(arr2.B[j]<B[i]){
            j++;
        }else{
            i++;
            j++;
        }
    }
    // If there're elements yet in arr
    while(i<length){
        arr3->B[k++]=B[i++];
    }
    // Set the length of arr3
    arr3->length = k;
    return arr3;
}

int main(){
    array2 *arr1,*arr2;
    int sz,num,x,index,originalIndex,low,high,key,i,number;
    cout<<"Enter the size of the array : ";
    cin>>sz;
    // Validation Size
    while(cin.fail()||sz<=0||sz>1000){ // cin.fail() -> for non-integer input
        cout<<"Invalid input. Please enter an invalid input : ";
        cin>>sz;
        cin.clear(); // reask for the input
        cin.ignore(numeric_limits<streamsize>::max()); // from #include <limits> library
    }
    arr1 = new array2(sz);
    arr2 = new array2(sz);

    cout<<endl<<endl<<"Menu"<<endl;
    cout<<"1. Set"<<endl;
    cout<<"2. Display"<<endl;
    cout<<"3. Get"<<endl;
    cout<<"4. Max"<<endl;
    cout<<"5. InsertElement"<<endl;
    cout<<"6. IfSorted"<<endl;
    cout<<"7.Shift_minus_to_left"<<endl;
    cout<<"8. Append"<<endl;
    cout<<"9. Insert"<<endl;
    cout<<"10. Dellete"<<endl;
    cout<<"11. LinearSearch"<<endl;
    cout<<"12. BinarySearch"<<endl;
    cout<<"13. RbinarySearch"<<endl;
    cout<<"14. Merge"<<endl;
    cout<<"15. Union"<<endl;
    cout<<"16. Intersection"<<endl;
    cout<<"17. Difference"<<endl;
    
    do
    {
    cout<<"Enter the number of your choice : ";
    cin>>num;
    switch(num){
        case 1:
            cout<<"Enter the index : ";
            cin>>index;
            cout<<"Enter the element : ";
            cin>>x;
            arr1->set(index,x);
            break;
        case 2:
            arr1->display();
            break;
        case 3:
            cout<<"Enter the index : ";
            cin>>index;
            cout<<arr1->get(index)<<endl;
            break;
        case 4:
            cout<<arr1->max()<<endl;
            break;
        case 5:
            cout<<"Enter the element : ";
            cin>>x;
            arr1->insertElement(x);
            break;
        case 6:
            arr1->ifSorted();
            break;
        case 7:
            arr1->shift_minus_to_left();
            break;
        case 8:
            cout<<"Enter the element : ";
            cin>>x;
            arr1->append(x);
            break;
        case 9:
            cout<<"Enter the element : ";
            cin>>x;
            cout<<"Enter the index : ";
            cin>>index;
            arr1->insert(x,index);
            break;
        case 10:
            cout<<"Enter the index : ";
            cin>>index;
            arr1->dellete(index);
            break;
        case 11:
            cout<<"Enter the element : ";
            cin>>x;
            cout<<arr1->linearSearch(x,originalIndex)<<endl;
            break;
        case 12:
            cout<<"Enter low, high, key : ";
            cin>>low>>high>>key;
            cout<<arr1->binarySearch(low,high,key)<<endl;
            break;
        case 13:
            cout<<"Enter low, high, key : ";
            cin>>low>>high>>key;
            cout<<arr1->RbinarySearch(low,high,key)<<endl;
            break;
        case 14:{
            cout<<"Enter the number of elements you want to add for the second array : ";
            cin>>number;
            cout<<"Enter the elements : ";
            for(i=0;i<number;i++){
                cin>>x;
                arr2->append(x);
            }
            array2* merged = arr1->merge(*arr2);
            merged->display();
            delete merged;
            arr2->clear();
            break;
        }
        case 15:{
            cout<<"Enter the number of elements you want to add for the second array : ";
            cin>>number;
            cout<<"Enter the elements : ";
            for(i=0;i<number;i++){
                cin>>x;
                arr2->append(x);
            }
            array2 *uni = arr1->uniion(*arr2);
            uni->display();
            delete uni;
            arr2->clear();
            break;
        }
        case 16:{
            cout<<"Enter the number of elements you want to add for the second array : ";
            cin>>number;
            cout<<"Enter the elements : ";
            for(i=0;i<number;i++){
                cin>>x;
                arr2->append(x);
            }
            array2 *inter = arr1->intersection(*arr2);
            inter->display();
            delete inter;
            arr2->clear();
            break;
        }
        case 17:{
            cout<<"Enter the number of elements you want to add for the second array : ";
            cin>>number;
            cout<<"Enter the elements : ";
            for(i=0;i<number;i++){
                cin>>x;
                arr2->append(x);
            }
            array2* diff = arr1->difference(*arr2);
            diff->display();
            delete diff;
            arr2->clear();
            break;
        }
    }}while(num<18);
    //if(num<0)|| num>1
    delete arr1;
    delete arr2;
}
*/