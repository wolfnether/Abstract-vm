#ifndef IOPERANDFACTORY_HPP
#define IOPERANDFACTORY_HPP

#include <string>

enum class eOperandType{
    Int8, Int16, Int32, Float, Double
};

class IOperandFactory{
public:
    IOperand const * createOperand( eOperandType type, std::string const & value ) const;
private:
    IOperand const * createInt8( std::string const & value ) const;
    IOperand const * createInt16( std::string const & value ) const;
    IOperand const * createInt32( std::string const & value ) const;
    IOperand const * createFloat( std::string const & value ) const;
    IOperand const * createDouble( std::string const & value ) const;
    static IOperand const *(IOperandFactory::*aptr)(std::string const &)[5];
};

#endif