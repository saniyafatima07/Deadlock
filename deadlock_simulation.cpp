#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtxA;
mutex mtxB;

void func1(){
 
   cout<<"Accessing resource A - thread 1 "<<endl;
   mtxA.lock();
   cout<<"Acquired resource A- thread 1"<<endl;

   this_thread::sleep_for(chrono::seconds(1));
   cout<<"Accessing resource B - thread 1"<<endl;
   mtxB.lock();
   cout<<"Acquired resource B- thread 1"<<endl;

   this_thread::sleep_for(chrono::seconds(1));
   mtxB.unlock();
   cout<<"Released resource B"<<endl;
   mtxA.unlock();
   cout<<"Released resource A"<<endl;
}

void func2(){
  
    cout<<"Accessing resource B - thread 2"<<endl;
    mtxB.lock();
    cout<<"Acquired resource B- thread 2"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    cout<<"Accessing resource A - thread 2"<<endl;
    mtxA.lock();
    cout<<"Acquired resource A- thread 2"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    mtxA.unlock();
    cout<<"Released resource A"<<endl;
    mtxB.unlock();
    cout<<"Released resource B"<<endl;
}

int main(){
    thread t1(func1);
    thread t2(func2);
    t1.join();
    t2.join();
}