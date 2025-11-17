#pragma once

/**
 * @brief Greeting class that provides a basic greeting message.
 */
class Greeting {
   private:
    const char* p_message = "Basic project setup complete";

   public:
    Greeting() = default;

    ~Greeting() = default;
    const char* message();
};
