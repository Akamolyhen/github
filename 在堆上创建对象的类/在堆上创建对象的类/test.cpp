#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//只能在堆上创建对象的类
//1.构造函数私有化
//2.提供公共接口：在堆上创建对象
//3.在类外无法创建对象，函数用类名调用，公共接口必须为static接口
//4.防止拷贝：<1>拷贝构造私有化，只声明不实现
//            <2>靠别构造声明成delete函数（c++11）

class Heap
{
	friend void fun1();
public:
	static Heap* getHeap()//静态，为了在类外用类名调用
	{
		return new Heap;
	}
	
	Heap(const Heap& hp)= delete;//把拷贝构造定义成一个删除函数，即使是公有的也不能调用

private:
	Heap(){}//私有化构造函数
	//Heap(const Heap& hp);//私有化拷贝构造函数
};

//Heap::Heap(const Heap& hp)
//{}

void fun1()
{
	Heap* hp = Heap::getHeap();
	//Heap hp2(*hp);
}

int main()
{
	Heap* hp = Heap::getHeap();
	//Heap hp2(*hp);
	return 0;
}