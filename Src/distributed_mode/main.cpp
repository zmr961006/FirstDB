#include <iostream>
#include "FDB_Server.h"

static int fd;


int main()
{
    FDB_Server test_Server(true, 10086, 1);
    test_Server.server_start();

    return 0;
}
