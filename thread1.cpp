#include<iostream>
#include<thread>
using namespace std;

/*
Threads
-Threads are lightweight.
-Subprocess
-Independent
-We can divide indepedent parts of process into multiple threads and can run them simultaneously

Best example is 

-While we type something on Microsoft word , multiple things are happening at the same time.
1. Saving of data when we are typing.
2. Formatting of data.
3. Spell checking .

This is due to use of multiple threads .

In the program below we are creating two threads below.
Lets say our CPU is of octacore.
So these two independent functions will go to two different CPU's for execution .
Results mostly will be different when we run program everytime.

We need to join every thread at the end because our main thread is int_main and we need to join our created
threads to main so that they won't lost.

*/

void fun1(){
	for(int i=0;i<1000;i++){
		cout<<"Hi"<<endl;
	}
}

void fun2(){
	for(int i=0;i<1000;i++){
		cout<<"Hello"<<endl;
	}	
}
int main(){
	thread t1(fun1);
    thread t2(fun2);
	t1.join();
	t2.join();
}
