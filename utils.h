#include<fmt/core.h>

#define DEBUG
#ifdef DEBUG
#define D(x) (std::cerr << (x))
//... etc
#else 
#define D(x) do{}while(0)
//... etc
#endif

