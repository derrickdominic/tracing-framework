#ifndef WTF_C_H_
#define WTF_C_H_

struct WtfScopedEventIf;
struct WtfAutoScopeIf;

void wtf_c_thread_enable(const char* name);

int wtf_c_save_to_file(const char* filename);

// #define WTF_SCOPE0(name_spec)                                           \
//   static __INTERNAL_WTF_NAMESPACE::ScopedEventIf<kWtfEnabledForNamespace> \
//       __WTF_INTERNAL_UNIQUE(__wtf_scope_event0_){name_spec};              \
//   __INTERNAL_WTF_NAMESPACE::AutoScopeIf<kWtfEnabledForNamespace>          \
//       __WTF_INTERNAL_UNIQUE(__wtf_scope0_){                               \
//           __WTF_INTERNAL_UNIQUE(__wtf_scope_event0_)};                    \
//   __WTF_INTERNAL_UNIQUE(__wtf_scope0_).Enter()

#endif  // WTF_C_H_
