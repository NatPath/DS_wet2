#ifndef _HASH_TABLE_H
#include <exception>
#include "List.h"

template<class T>
class HashTable{

   List<T>* _data_chains;
   int _size;
   int _counter;
   
   double getOverLoadFactor() const{
       return (double)_counter/(double)_size;       
   }

   int hash_function(T& to_hash) const{
       int key=to_hash.get_id();
       return key%_size;
   } 
   //
   void expand(){
       try{
           List<T>* temp_data=new List<T>[2*_size];
           //rehash all elements
           for (i = 0; i < _size; i++)
           {
               //iterate over a chain
               ListNode<T>* itt= _data_chains[i].getRoot();
               ListNode<T>* next;
               while(next!=nullptr){
                    int key=hash_function(itt->getValue.get);
                    next = itt->getNext();
                    _data_chains[key].add(*itt);
                                      
               }
           }
       }
       catch(){
           delete[] temp_data;
       }
   }
   public:
   HashTable(){
       _size=2;//?
       _data_chains = new List<T>[_size];
   }
   ListNode<T>& find(T& to_find){
       int table_index=hash_function(to_find);
       return _data_chains.find(to_find);
   }
   void insert(T& to_insert){
       if (find(to_insert)!=nullptr){
           return;
       }
       else{
           int key=hash_function(to_insert);
           _data_chains[key].add(to_insert);
           _counter++;
           if (getOverLoadFactor()>2){
               expand();
           }
       }
   }
   /*
   void insert(ListNode<T>& to_insert){
      
       if (find(to_insert.getValue().get)!=nullptr){
           return;
       }
       else{
           int key=hash_function(to_insert.getValue().get);
           _data_chains[key].add(to_insert);
           _counter++;
           if (getOverLoadFactor()>2){
               expand();
           }
       }
   }
   */
   void remove(T& to_remove){
       _data_chains[hash_function(to_remove)].remove(to_remove);

   }

   ~HashTable(){
       delete[] _data_chains;
   }
};

#endif