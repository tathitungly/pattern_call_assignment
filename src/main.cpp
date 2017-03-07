#include <stdio.h>
#include "pattern.h"

int main( int argc, const char* argv[] )
{
    Pattern a(9, "test", "test.pat", false);
    printf( "Leben ist schoen with ID=%d\n", a.getId() );

}
