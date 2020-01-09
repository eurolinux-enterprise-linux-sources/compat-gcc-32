#include <stdio.h>

static struct sss{
  long long f;
  short a[10];
} sss;

#define _offsetof(st,f) ((char *)&((st *) 16)->f - (char *) 16)

int main (void) {
  printf ("++++Array of short in struct starting with longlong:\n");
  printf ("size=%d,align=%d\n",
          sizeof (sss), __alignof__ (sss));
  printf ("offset-longlong=%d,offset-arrayof-short=%d,\nalign-longlong=%d,align-arrayof-short=%d\n",
          _offsetof (struct sss, f), _offsetof (struct sss, a),
          __alignof__ (sss.f), __alignof__ (sss.a));
  printf ("offset-short-a[5]=%d,align-short-a[5]=%d\n",
          _offsetof (struct sss, a[5]),
          __alignof__ (sss.a[5]));
  return 0;
}
