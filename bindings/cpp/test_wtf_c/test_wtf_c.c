#include <stdio.h>
#include <unistd.h>

#include "wtf_c.h"

const char kTraceFile[] = "test_wtf_c.wtf-trace";

struct WtfScopedEventIf;

void Process() {
  // static CScopedEvent event("Process");
  // CScope scope(event);
  // scope.Enter();
  
  
  // scope.Leave();

  // static WtfScopedEventIf scoped_event;
  //"Process"};

  for (int i = 0; i < 5; i++) {
    usleep(5);
  }
}

int main(void) {
  wtf_c_thread_enable("main");

  for (int i = 0; i < 5; i++) {
    Process();
    usleep(5);
  }

  if (!wtf_c_save_to_file(kTraceFile)) {
    fprintf(stderr, "Error saving trace as file %s", kTraceFile);
    return 1;
  }

  return 0;
}
