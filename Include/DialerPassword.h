#ifndef SAFEUM_DIALER_PASSWORD_H
#define SAFEUM_DIALER_PASSWORD_H

#include <HierarchyBase.h>

MemoryBufferT *CalculatePasswordHash(char *Company, char *Login, char *Password);

ErrnoT PasswordPublicGet(MemoryBufferT **X,
                         MemoryBufferT **Y,
                         char *Company, char *Login, char *Password);

#endif
