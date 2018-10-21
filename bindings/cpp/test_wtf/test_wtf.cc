// https://en.cppreference.com/w/cpp/thread/thread/thread
//
// Expected output:
//   Thread 1 executing
//   Thread 2 executing
//   Thread 1 executing
//   Thread 2 executing
//   Thread 1 executing
//   Thread 2 executing
//   Thread 1 executing
//   Thread 2 executing
//   Thread 2 executing
//   Thread 1 executing
//   Final value of n is 5

#include <unistd.h>
#include <iostream>
#include <thread>
#include <utility>
#include <wtf/macros.h>

constexpr char kTraceFile[] = "test-wtf.wtf-trace";
 
void A(int a) {
  WTF_SCOPE("A: a", int)(a);
  usleep(50000);
}
 
void B(int b) {
  WTF_SCOPE("B: b", int)(b);
  usleep(100000);
}
 
int main() {
  WTF_THREAD_ENABLE("main");
  WTF_SCOPE0("main");
  
  std::thread t1(
      [](int n) { 
        WTF_THREAD_ENABLE("t1");
        A(n);
      }, 10);
  std::thread t2(
      [](int n) { 
        WTF_THREAD_ENABLE("t2");
        B(n);
      }, 10);
  
  t1.join();
  t2.join();
  
  if (!wtf::Runtime::GetInstance()->SaveToFile(kTraceFile)) {
    std::cerr << "Error saving file: " << kTraceFile;
    return 1;
  }
  
  return 0;
}
