#define _GNU_SOURCE
#include <dlfcn.h>
#define _FCNTL_H
#include <bits/fcntl.h>
#include <stdio.h>
#include <stdlib.h>

void* (*_malloc)(size_t size);

int i = 1;
void* malloc(size_t size) {
	_malloc = dlsym(RTLD_NEXT, "malloc");
	//printf("malloc(%li) #%i\n", size, i++);	
	if (i > 150 == 0 && size == 1) {
		return 0;
	} else {
		return _malloc(size);
	}
}

