#include <stdio.h>
#include <unistd.h>

#include "wtf_c.h"

const char kTraceFile[] = "test_wtf_c.wtf-trace";

void Process() {
  // WTF_C_SCOPE0("Process");
  wtf_scope0("Process");
  
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      // WTF_C_EVENT0("ProcessMidPoint");
    }
    usleep(5);
  }
}

int main(void) {
  // WTF_C_THREAD_ENABLE("Main");

  Process();

  // if (!wtf::Runtime::GetInstance()->SaveToFile(kTraceFile)) {
  //   fprintf(stderr, "Error saving file: %s", kTraceFile);
  //   return 1;
  // }

  return 0;
}
