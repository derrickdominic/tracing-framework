#include <stdio.h>
#include <unistd.h>

const char kTraceFile[] = "test_wtf_c.wtf-trace";

void Process() {
  // WTF_SCOPE0("Process");
  wtf_scope0("Process");
  printf("Process\n");
  for (int i = 0; i < 100; i++) {
    if (i == 50) {
      // WTF_EVENT0("ProcessMidPoint");
      wtf_event0("ProcessMidPoint");
      printf("ProcessMidPoint\n");
    }
    usleep(5);
  }
}

int main(void) {
  // WTF_THREAD_ENABLE("Main");
  wtf_thread_enable("Main");
  printf("Main\n");

  Process();

  // Save the trace.
  printf("Saving the trace\n");
  // !wtf::Runtime::GetInstance()->SaveToFile(kTraceFile)
  if (!wtf_save_to_file(kTraceFile)) {
    fprintf(stderr, "Error saving file: %s", kTraceFile);
    return 1;
  }

  return 0;
}
