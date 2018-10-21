#include "wtf/macros.h"
#include "wtf/runtime.h"

extern "C" typedef wtf::ScopedEventIf<kWtfEnabledForNamespace> WtfScopedEventIf;
extern "C" typedef wtf::AutoScopeIf<kWtfEnabledForNamespace> WtfAutoScopeIf;

extern "C" void wtf_c_thread_enable(const char* name) {
  WTF_THREAD_ENABLE(name);
}

extern "C" int wtf_c_save_to_file(const char* filename) {
  return static_cast<int>(wtf::Runtime::GetInstance()->SaveToFile(filename));
}

extern "C" void AutoScopeIf_Enter(
    wtf::AutoScopeIf<kWtfEnabledForNamespace>* scope) {
  scope->Enter();
}

