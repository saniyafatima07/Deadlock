#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
using namespace std;

mutex mtxA;
mutex mtxB;

void safe_lock1(){
    cout<< "Accessing resource A - thread 1 "<<endl;
    mtxA.lock();
    cout<< "Acquired resource A- thread 1"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    cout<< "Accessing resource B - thread 1 "<<endl;
    mtxB.lock();
    cout<< "Acquired resource B- thread 1"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    mtxB.unlock();
    cout<<"Released resource B"<<endl;
    mtxA.unlock();
    cout<<"Released resource A"<<endl;
}

void safe_lock2(){
    cout<< "Accessing resource A - thread 2 "<<endl;
    mtxA.lock();
    cout<< "Acquired resource A- thread 2"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    cout<< "Accessing resource B - thread 2 "<<endl;
    mtxB.lock();
    cout<< "Acquired resource B- thread 2"<<endl;

    this_thread::sleep_for(chrono::seconds(1));
    mtxB.unlock();
    cout<<"Released resource B"<<endl;
    mtxA.unlock();
    cout<<"Released resource A"<<endl;
}

int main(){
    thread t1(safe_lock1);
    thread t2(safe_lock2);
    t1.join();
    t2.join();
}
