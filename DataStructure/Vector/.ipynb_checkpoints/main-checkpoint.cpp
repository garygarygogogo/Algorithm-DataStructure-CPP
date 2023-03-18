#ifndef _MY_VECTOR_HPP_
#define _MY_VECTOR_HPP_

template<typename T>
class MyVector{
public:
    // 构造函数
    MyVector(){
        //这里默认数组大小为10
        //但是vector文件中默认构造的方式是0，之后插入按照1 2  4  8  16 二倍扩容。注GCC是二倍扩容，VS13是1.5倍扩容
        data = new T[10];
        _capacity = 10;
        _size = 0;
    }
    ~MyVector(){
        delete[] data;
    }
    //reserve只是保证vector的空间大小(_capacity)最少达到它的参数所指定的大小n。在区间[0, n)范围内,预留了内存但是并未初始化
    void reserve(size_t n){
        if(n>_capacity){
            data = new T[n]; 
            _capacity = n;
        }
    }
    //向数组中插入元素
    void push_back(T e){
        //如果当前容量已经不够了，重新分配内存，均摊复杂度O(1)
        if (_size == _capacity){
            resize(2 * _capacity);//两倍扩容
        }
        data[_size++] = e;
    }
    //删除数组尾部的数据，同时动态调整数组大小，节约内存空间
    T pop_back(){
        T temp = data[_size];
        _size--;
        //如果容量有多余的，释放掉
        if (_size == _capacity / 4){
            resize(_capacity / 2);
        }
        return temp;
    }
    //获取当前数组中元素的个数
    size_t size(){
        return _size;
    }
    //判断数组是否为空
    bool empty(){
        return _size==0?1:0;
    }
    //重载[]操作
    int &operator[](int i){
        return data[i];
    }
    //获取数组的容量大小
    size_t capacity(){
        return _capacity;
    }
    //清空数组,只会清空数组内的元素，不会改变数组的容量大小
    void clear(){
        _size=0;
    }
private:
    T *data;    //实际存储数据的数组
    size_t _capacity; //容量
    size_t _size;  //实际元素个数
    //扩容
    void resize(int st){
        //重新分配空间，在堆区新开辟内存，然后将以前数组的值赋给他，删除以前的数组
        T *newData = new T[st];
        for (int i = 0; i < _size; i++){
            newData[i] = data[i];
        }
        //实际使用时是清除数据，但不会释放内存
        delete[] data;
        data = newData;
        _capacity = st;
    }
};

#endif //_MY_VECTOR_HPP_