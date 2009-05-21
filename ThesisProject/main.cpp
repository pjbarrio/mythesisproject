#include "Init/Main/Init.h"

/*
 * This Method represents the main method which will be invoked when the execution starts.
 */


int main(int argc, char *argv[])
{

	Init* i = new Init();

    int ret = i->start(argc,argv);

    return ret;
}
