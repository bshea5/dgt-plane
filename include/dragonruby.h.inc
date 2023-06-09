#ifndef DRB_FFI_EXPOSE
#error "Define DRB_FFI_EXPOSE before including this file"
#endif

DRB_FFI_EXPOSE(void (*mrb_raise)(struct mrb_state *mrb, struct RClass *c, const char *msg), mrb_raise)
DRB_FFI_EXPOSE(void (*mrb_raisef)(struct mrb_state *mrb, struct RClass *c, const char *fmt, ...), mrb_raisef)
DRB_FFI_EXPOSE(struct RClass *(*mrb_module_get)(struct mrb_state *mrb, const char *name), mrb_module_get)
DRB_FFI_EXPOSE(struct RClass *(*mrb_module_get_under)(struct mrb_state *mrb, struct RClass *outer, const char *name), mrb_module_get_under)
DRB_FFI_EXPOSE(struct RClass *(*mrb_define_module_under)(struct mrb_state *mrb, struct RClass *outer, const char *name), mrb_define_module_under)
DRB_FFI_EXPOSE(struct RClass *(*mrb_class_get_under)(struct mrb_state *mrb, struct RClass *outer, const char *name), mrb_class_get_under)
DRB_FFI_EXPOSE(struct RClass *(*mrb_define_class_under)(struct mrb_state *mrb, struct RClass *outer, const char *name, struct RClass *super), mrb_define_class_under)
DRB_FFI_EXPOSE(void (*mrb_define_module_function)(struct mrb_state *mrb, struct RClass *cla, const char *name, mrb_func_t fun, mrb_aspec aspec), mrb_define_module_function)
DRB_FFI_EXPOSE(void (*mrb_define_method)(struct mrb_state *mrb, struct RClass *cla, const char *name, mrb_func_t func, mrb_aspec aspec), mrb_define_method)
DRB_FFI_EXPOSE(void (*mrb_define_class_method)(struct mrb_state *mrb, struct RClass *cla, const char *name, mrb_func_t fun, mrb_aspec aspec), mrb_define_class_method)
DRB_FFI_EXPOSE(int64_t (*mrb_get_args)(struct mrb_state *mrb, mrb_args_format format, ...), mrb_get_args)
DRB_FFI_EXPOSE(mrb_value (*mrb_str_new_cstr)(struct mrb_state *, const char *), mrb_str_new_cstr)
DRB_FFI_EXPOSE(struct RData *(*mrb_data_object_alloc)(struct mrb_state *mrb, struct RClass *klass, void *ptr, const struct mrb_data_type *type), mrb_data_object_alloc)
DRB_FFI_EXPOSE(void (*drb_free_foreign_object)(struct mrb_state *mrb, void *ptr), drb_free_foreign_object)
DRB_FFI_EXPOSE(void (*drb_typecheck_float)(struct mrb_state *mrb, mrb_value self), drb_typecheck_float)
DRB_FFI_EXPOSE(void (*drb_typecheck_int)(struct mrb_state *mrb, mrb_value self), drb_typecheck_int)
DRB_FFI_EXPOSE(void (*drb_typecheck_bool)(struct mrb_state *mrb, mrb_value self), drb_typecheck_bool)
DRB_FFI_EXPOSE(mrb_value (*drb_float_value)(struct mrb_state *mrb, mrb_float f), drb_float_value)
DRB_FFI_EXPOSE(struct RClass *(*drb_getruntime_error)(struct mrb_state *mrb), drb_getruntime_error)
DRB_FFI_EXPOSE(struct RClass *(*drb_getargument_error)(struct mrb_state *mrb), drb_getargument_error)
DRB_FFI_EXPOSE(void (*drb_typecheck_aggregate)(struct mrb_state *mrb, mrb_value self, struct RClass *expected, struct mrb_data_type *data_type), drb_typecheck_aggregate)
DRB_FFI_EXPOSE(void (*drb_upload_pixel_array)(const char *name, const int w, const int h, const uint32_t *pixels), drb_upload_pixel_array)
DRB_FFI_EXPOSE(void *(*drb_load_image)(const char *fname, int *w, int *h), drb_load_image)
DRB_FFI_EXPOSE(void (*drb_free_image)(void *pixels), drb_free_image)
DRB_FFI_EXPOSE(void (*drb_log_write)(const char *subsystem, const int level, const char *str), drb_log_write)
