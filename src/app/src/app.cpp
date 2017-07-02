#include <stdio.h>
#include "my_library/my_library_component.h"

int main(int argc, char ** argv)
{
    printf("cmake-base main function hello\n");
    mylibrary::MyLibraryComponent mylib;
    return 0;
}