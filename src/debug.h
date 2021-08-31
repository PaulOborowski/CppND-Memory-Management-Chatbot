#define DEBUG_BUILD
#ifdef DEBUG_BUILD
#define DEBUG(x)                                                               \
  do {                                                                         \
    std::cerr << x;                                                            \
  } while (0)
#else
#define DEBUG(x)                                                               \
  do {                                                                         \
  } while (0)
#endif