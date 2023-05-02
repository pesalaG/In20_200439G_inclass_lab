#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
    int largest ;
    int l = 2*root + 1; // left is indexed as = 2*i + 1
    int r = 2*root + 2; // right is indexed as = 2*i + 2

    // check the left chid
    if (l < n && arr[l] > arr[root]){
        largest = l;}
    else {largest = root;}

    // checking the right child
    if (r < n && arr[r] > arr[largest]){
        largest = r;}

    // swapping and heafying is done if root is not largest
    if (largest != root) {
        swap(arr[root], arr[largest]);
        //heapify
        heapify(arr, n, largest);
    }
}
 
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
    int ind =n / 2 - 1;
    for (int i = ind ; i >= 0; i--){
        heapify(arr, n, i);
       }
  // extracting elements from heap one by one
    for (int j=n-1; j>=0; j--) {
        // creating the sorted array using heap
        swap(arr[0], arr[j]);

        heapify(arr, j, 0);
    } 
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   int size;
   cout<<"enter the array size :";
   cin >> size;
   
   int heap_arr[size];
   for(int i=0;i<size;i++){
       heap_arr[i]=rand()%100;
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,size);
  
   heapSort(heap_arr, size);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, size);
}
