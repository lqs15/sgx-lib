#include <stdarg.h>
#include <stdlib.h>

#include "sgx_lib_t.h"
#include "sgx_lib_t_util.h"
#include "sgx_lib_t_debug.h"

void log_msg(char* msg) {
  print_ocall(msg);
  print_ocall("\n");
}

void printf(char* format, ...) {
  char *formatted;
  va_list argptr;
  va_start(argptr, format);
  formatted = vsprintf(format, argptr);
  va_end(argptr);
  print_ocall(formatted);
  free(formatted);
}