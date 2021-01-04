#ifndef _DARRAY_H
#include <exception>

template <class T>
class DynamicArray{
    T* _data;
    int _size;
    int _counter;

    public:
    DynamicArray(int size):_size(size){
        _data=new T[size];
        _counter = 0;
    }
    //c'tor with default value
    DynamicArray(int size,T default_value){
        _size=size;
        _data=new T[size];
        for (int i=0;i<_size;i++){
            _data[i]=default_value;
        }
    }
    //copy c'tor
    DynamicArray(DynamicArray<T>& to_copy){
        _size=to_copy.getSize();
        try{
            T* temp_data=new T[_size];
            int temp_size=to_copy.getSize();
            for (int i=0;i<temp_size;i++){
                temp_data[i]=to_copy[i];
            }
        }
        catch(std::exception& e){
            delete[] temp_data;
            throw std::runtime_error("Failed to copy Dynamic Array");
        }
        delete[] _data;
        _counter=to_copy.counter;
        _size=temp_size;
        _data=temp_data;
    }

    DynamicArray& operator=(DynamicArray<T>& to_assign){
        try{
            int new_size = to_assign.getSize();
            T* assign_data = to_assign.getData();
            T* temp_data = new T[new_size];
            
            for(int i = 0; i<new_size;i++){
                temp_data[i] = assign_data[i]; 
            }

            delete[] _data;
            _size = new_size;
            _counter = to_assign.getCounter();
            _data = temp_data;
        }
        catch(...){
            delete[] temp_data;
        }
    }

    void push(T new_value){
        if (_counter+1<_size){
            _data[_counter++] = new_value;
        }
        else{
            expand();
            _data[_counter++] = new_value;
        }
        
    }

    void expand(){
        try{
            T* new_data = new T[size * 2];
            for (int i = 0; i < size; i++)
            {
                new_data[i] = _data[i];
            }
            delete[] _data;
            size = size*2;
            _data = new_data;
        }
        catch(...){
            throw std::runtime_error("Failed to expand Dynamic Array");  
            delete[] new_data;          
        }


    }

    //Getters
    int getSize() const{
        return _size;
    }

    int getCounter() const{
        return _counter;
    }


    T* getData(){
        return _data;
    }

    T& operator[](int index){
        if (index<_size){
            return _data[index];
        }
        else{
            throw std::runtime_error("Out of range index");
        }
    }

    ~DynmaicArray<T>(){
        delete[] _data;
    }
    void printArray(){
        for (int i=0;i<_size;i++){
            print(_data[i]);
        }
    }

};

#endif