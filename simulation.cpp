#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtxA;
mutex mtxB;

void func1(int a,int b){
   a=a+1;
   cout<<"Accessing resource A"<<endl;
   mtxA.lock();

   this_thread::sleep_for(chrono::seconds(1000));
   int sum = a+b;
   cout<<"Accessing resource B"<<endl;
   mtxB.lock();

   this_thread::sleep_for(chrono::seconds(1000));
   mtxB.unlock();
   mtxA.unlock();
}
void func2(int a,int b){
    b=b+1;
    cout<<"Accessing resource B"<<endl;
    mtxB.lock();

    this_thread::sleep_for(chrono::seconds(1000));
    int sum=a+b;
    cout<<"Accessing resource A"<<endl;
    mtxA.lock();

    this_thread::sleep_for(chrono::seconds(1000));
    mtxA.unlock();
    mtxB.unlock();
}

int main(){
    int a=10, b=20;
    thread t1(func1, a, b);
    thread t2(func2,a,b);
    t1.join();
    t2.join();
}