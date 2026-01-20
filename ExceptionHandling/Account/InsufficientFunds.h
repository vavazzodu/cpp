#ifndef __INSUFFICIENT_FUNDS__
#define __INSUFFICIENT_FUNDS__
#include<exception>
class InsufficientFunds: public std::exception
{
    public:
        InsufficientFunds() noexcept = default;
        ~InsufficientFunds() = default;
        virtual const char * what() const noexcept
        {
            return "Error: Insufficient balance in the account.";
        }
};

#endif