#include <pl32-memory.h>

typedef struct plwindow plwindow_t;

int plInit();
void plExit();

int plCreateWindow(plwindow_t* windowPtr, );
void plDestroyWindow(plwindow_t* windowPtr);

unsigned int getFrameMs();
float getFMSCalc();

int plSetup();
int plMain(int argc, const char* argv);
