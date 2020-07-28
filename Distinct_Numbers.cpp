#include<iostream>
 
 
void max_heapify(int *a, int size, int i){
 
  int l = 2*i ;
  int r = (2*i)+1;
  int largest;
  int temp;
 
  // check if parent has higher key value than children
  if(l <= size && a[l] > a[i])
    largest = l;
  else
    largest = i;
 
  if(r <= size && a[r] > a[largest])
    largest = r;
 
  if(largest != i){
    // it means one of the children is bigger so swap it's key with parent
    temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;
 
    // perform heapify recursively till all the branches are max heapified
    max_heapify(a, size, largest);
  }
 
}
 
 
void heap_sort(int *a, int size){
 
  // build max heap from unordered array
  for(int i = size/2; i>0; i--)
    max_heapify(a, size, i);
 
  // run the sorting function till heap size is not zero
  while(size != 0){
 
    // find max element at a[1] and swap it with a[size]
    int temp;
    temp = a[1];
    a[1] = a[size];
    a[size] = temp;
 
    // remove last element
    size--;
 
    // max heapify the first element to obtain again a max heap
    max_heapify(a, size, 1);
  }
}
 
 
int main(){
 
  int size;
  // std::cout << "enter number of elements -->\n";
  std::cin >> size;
 
  int a[size];
  // std::cout << "enter array -->\n";
  for(int i=1; i<=size; i++){
    std::cin >> a[i];
  }
 
  // perform sorting
  heap_sort(a, size);
 
  // view the sorted array
  // for(int i=1; i<=size; i++){
  //   std::cout << a[i];
  // }
 
  int num_distinct = 0;
  for(int i=1; i<=size; i++){
    if(a[i] != a[i+1])
      num_distinct++;
  }
 
  std::cout << num_distinct;
 
 
  return 0;
}
