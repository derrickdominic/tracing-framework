#include "wtf/macros.h"

extern "C" void wtf_scope0(const char* name) {
  WTF_SCOPE0(name);
}

extern "C" void wtf_event0(const char* name) {
  WTF_EVENT0(name);
}

extern "C" void wtf_thread_enable(const char* name) {
  WTF_THREAD_ENABLE(name);
}

extern "C" int wtf_save_to_file(const char* filename) {
  return static_cast<int>(wtf::Runtime::GetInstance()->SaveToFile(filename));
}
