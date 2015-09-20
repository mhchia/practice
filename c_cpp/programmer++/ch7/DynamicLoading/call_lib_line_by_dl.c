#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void* handle;
    double (*func)(double);
    char* error;
    if (argc <= 1) {
        fprintf(stderr, "argument error\n");
        return EXIT_FAILURE;
    }
    handle = dlopen(argv[1], RTLD_NOW);
    if (handle == NULL) {
        fprintf(stderr, "Open library %s error : %s\n", argv[1], dlerror());
        return EXIT_FAILURE;
    }
    char *function_name = "sin";
    func = dlsym(handle, function_name);
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Symbol %s not found: %s\n", function_name, error);
        dlclose(handle);
        return EXIT_FAILURE;
    }

    fprintf(stdout, "%f\n", func(5));
    dlclose(handle);
}

