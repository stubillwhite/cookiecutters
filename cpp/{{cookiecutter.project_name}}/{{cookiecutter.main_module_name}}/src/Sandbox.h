#ifndef STUW_TESTING_SANDBOX_H
#define STUW_TESTING_SANDBOX_H



class Sandbox
{
private:

    const char* p_message = "Simple starter created!";

public:

    Sandbox() = default;

    ~Sandbox() = default;
    const char* message();
};


#endif //STUW_TESTING_SANDBOX_H
