#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex mtxA;
mutex mtxB;

void safe_lock1(int a, int b){
    a=a+1;
    cout<< "Accessing resource A - thread 1 "<<endl;
    mtxA.lock();

    this_thread::sleep_for(chrono::milliseconds(1000));
    int sum = a + b;
    cout<< "Accessing resource B - thread 1 "<<endl;
    mtxB.lock();

    this_thread::sleep_for(chrono::milliseconds(1000));
    mtxB.unlock();
    mtxA.unlock();
}

void safe_lock2(int a, int b){
    a=a-1;
    cout<< "Accessing resource A - thread 2 "<<endl;
    mtxA.lock();

    this_thread::sleep_for(chrono::milliseconds(1000));
    int sum = a + b;
    cout<< "Accessing resource B - thread 2 "<<endl;
    mtxB.lock();

    this_thread::sleep_for(chrono::milliseconds(1000));
    mtxB.unlock();
    mtxA.unlock();
}

int main(){
    int a=10, b=20;
    thread t1(safe_lock1,a,b);
    thread t2(safe_lock2,a,b);
    t1.join();
    t2.join();
}
