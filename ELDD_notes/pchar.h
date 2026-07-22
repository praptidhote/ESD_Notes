#ifndef __PCHAR_H
#define __PCHAR_H

typedef struct {
    short size;    
    short len;      
    short avail;    
}info_t;

#define FIFO_CLEAR      _IO('x', 1)
#define FIFO_GET_INFO   _IOR('x', 2, info_t)

#endif
