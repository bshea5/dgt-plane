#ifndef DRAGONRUBY_DRAGONRUBY_H
#define DRAGONRUBY_DRAGONRUBY_H

#include <mruby.h>
#include <stdlib.h>
#if defined(_WIN32)
#include <windows.h>
#endif

#if defined(_WIN32)
#define DRB_FFI_EXPORT __declspec(dllexport)
#elif defined(__GNUC__) || defined(__clang__)
#define DRB_FFI_EXPORT __attribute__((visibility("default")))
#else
#define DRB_FFI_EXPORT
#endif

#ifndef __DRB_ANNOTATE
#define __DRB_ANNOTATE(key, value) __attribute__((annotate(key #value)))
#endif

#ifndef DRB_FFI_NAME
#define DRB_FFI_NAME(name) __DRB_ANNOTATE("drb_ffi:", name)
#endif

#ifndef DRB_FFI
#define DRB_FFI __DRB_ANNOTATE("drb_ffi:", )
#endif

typedef enum drb_foreign_object_kind {
  drb_foreign_object_kind_struct,
  drb_foreign_object_kind_pointer
} drb_foreign_object_kind;

typedef struct drb_foreign_object {
  drb_foreign_object_kind kind;
} drb_foreign_object;

struct mrb_state;
struct RClass;
struct RData;
struct mrb_data_type;

typedef struct drb_api_t {
#define DRB_FFI_EXPOSE(type, name) type;
#include <dragonruby.h.inc>
#undef DRB_FFI_EXPOSE
} drb_api_t;

#endif // DRAGONRUBY_DRAGONRUBY_H
