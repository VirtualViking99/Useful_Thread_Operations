// Useful_Thread_Operations.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// Some useful functionalities
// 
// get_id(): Returns a unique thread id for each active thread of execution, an 0 for non active threads
// 
//
#pragma once
#pragma warning(disable:6273)
#pragma warning(disable:4477)

#include <iostream>
#include<chrono>
#include <thread>


void foo()
{
    printf("This Thread ID - %d\n", std::this_thread::get_id());


}


void get_ID_Test()
{
    std::thread thread1(foo);
    std::thread thread2(foo);
    std::thread thread3(foo);
    std::thread thread4; //unjoined

    // 2. we can querry the id of a thread using thread object iself, instead of using 
// thread namespace
// 

    printf("\n\n thread1 ID - %d \n", thread1.get_id());
    printf("thread2 ID - %d \n", thread2.get_id());
    printf("thread3 ID - %d \n", thread3.get_id());
    printf("thread4 ID - %d \n", thread4.get_id());     //3. default constructed thread does not represent an active thread of execution, returns 0


    //2a. the results of this operation are similar to the previous case
    //




    thread1.join();
    thread2.join();
    thread3.join();

//4. after joining a thread, the thread does not represent an active thread of execution
    printf("\n \nthread3 ID - %d \n", thread3.get_id());//returns 0

}



//5. sleep_for(): blocks blocks executuion of curent thread for at least the specified
// sleep duration. May go longer  due to scheduling  or resource contention delays
// 
// std::this_thread::yield(): Yield will give up it's curent time slice and 
// reinsert the thread into the scheduling queue. The ammount of time that 
// expires until the thread is executed again is usually entirely dependent upon the 
// Operating System scheduling it, allowing other threads awaiting TimeSlice available
// to perform their tasks
// 
// std::thread::hardware_concurrency(): returns the number of  concurrent threads
// supported by the implementation. the value shouldbe considered only a hint.  In
// a computer, there are limmited numbers of cores available, so if we use more 
// threads than cores avialable, the cores will have to perform task swithcing 
// or round robin fashion executoin which takes overhead.  a break even point that
// the overhead causes to make the parallel implementation of particular algorithms 
// to lag behind its sequention counterparts. in an application it is wise to launch 
// a number of thread equal or less than the number of parallel threads allowed by the
// system. this number is usually equal to the number of logical cores youhave, but
// not always true depending on situation. value can be querried with this function
// 
// 
//  




int main()
{
    std::cout << "Hello World!\n \n";

    get_ID_Test();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    int allowed_Threads = std::thread::hardware_concurrency();
    printf("\n \nAllowed threads count in my device: %d \n \n", allowed_Threads);
}


//1. the initial output of get_ID_test outputs three sepparate 
// thread id humbers in multi-digit numbers.
// 