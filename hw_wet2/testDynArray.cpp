#include "DynamicArray.h"
#include "Lecture.h"


void testPrintArray(){
    DynamicArray<Lecture> a(2);
    int n=2000;
    for (int i=0;i<n;i++){
        a.push(Lecture(i,i));
    }
    for(int i=0;i<n;i++){
        print(a[i]);
    }
    //a.printArray();
    print(a.getSize());
}
int main(){
    testPrintArray();
    return 0;
}