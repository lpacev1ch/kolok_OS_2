#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::initFlag;
