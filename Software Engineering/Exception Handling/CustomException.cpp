#include <exception>
#include <iostream>
#include <string>


class VectorLengthException : public std::exception{
    
    private:
        std::string message;

    public:
        VectorLengthException(const std::string& msg) : message(msg){}

        const char* what() const noexcept override
        {
            return message.c_str();
        }

};