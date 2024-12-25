#ifndef DEF_MESSAGE
#define DEF_MESSAGE



typedef struct Message Message;
struct Message
{
    long type;
    char message[256];
};



#endif