#ifndef DEF_MESSAGE
#define DEF_MESSAGE



typedef struct Message Message;
struct Message
{
    long type;             // Type du message.
    char message[256];     // Contenu du message.
};



#endif