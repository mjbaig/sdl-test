#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define ERROR_EXIT(...) fprintf(stderr, __VA_ARGS__)
#define ERROR(R, ...)                                                          \
  fprintf(stderr, __VA_ARGS__);                                                \
  return R

#endif
