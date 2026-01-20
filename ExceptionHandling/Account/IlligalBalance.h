#ifndef __ILLIGAL_BALANCE__
#define __ILLIGAL_BALANCE__

#include<exception>
class IlligalBalance : public std::exception
{
    public:
        IlligalBalance() noexcept = default;
        ~IlligalBalance() = default;
        virtual const char * what () const noexcept
        {
            return "Error: Negative amount is not allowed.";
        }
};

#endif