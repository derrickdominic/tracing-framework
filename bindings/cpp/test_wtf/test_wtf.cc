#include <wtf/macros.h>
#include <iostream>
#include <unistd.h>

constexpr char kTraceFile[] = "test.wtf-trace";

void Process() {
  WTF_SCOPE0("Process");
  std::cout << "Process\n";
  for (int i = 0; i < 100; i++) {
    if (i == 50) {
      WTF_EVENT0("ProcessMidPoint");
      std::cout << "ProcessMidPoint\n";
    }
    usleep(5);
  }
}

int main(void) {
  WTF_THREAD_ENABLE("Main");
  std::cout << "Main\n";

  Process();

  // Save a trace.
  std::cout << "Saving the trace\n";
  if (!wtf::Runtime::GetInstance()->SaveToFile(kTraceFile)) {
    std::cerr << "Error saving file: " << kTraceFile;
    return 1;
  }

  return 0;
}
