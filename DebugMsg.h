
#ifndef DEBUG_MSG_H
#define DEBUG_MSG_H

//#define DEBUG     // switch on or off

#ifdef DEBUG
#define DEBUG_MSG(str) do { std::cout << str << std::endl; } while (false);
#else
#define DEBUG_MSG(str) do { } while (false);
#endif


#endif // DEBUG_MSG_H


