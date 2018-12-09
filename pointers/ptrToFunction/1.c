typedef struct String_Struct* String;

struct String_Struct
{
    char* (*get)(const void* self);
    void (*set)(const void* self, char* value);
    int (*length)(const void* self);
};

char* getString(const void* self);
void setString(const void* self, char* value);
int lengthString(const void* self);

String newString();

String newString(){
    String self = (String)malloc(sizeof(struct String_Struct));

    self->get = &getString;
    self->set = &setString;
    self->length = &lengthString;

    self->set(self, "");
    /**
     * There is no concept of an instance of an object and having methods that
     * are actually a part of an object, so a "self object" must be passed in
     * on each invocation. Sound familiar? Recall oop .
     **/
    return self;
}

char* getString(const void* self_obj)
{
    return ((String)self_obj)->internal->value;
}
