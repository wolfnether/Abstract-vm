cmake_minimum_required(VERSION 2.8.4)
project(abstractvm)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_C_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES
exception/AssertNoTrue.cpp
exception/DivideByZeroException.cpp
exception/EmptyStackException.cpp
exception/NoExitException.cpp
exception/OverflowException.cpp
exception/SyntaxException.cpp
exception/UnderflowException.cpp
exception/UnknownInstructionException.cpp
operand/eOperandType.cpp
operand/IOperandFactory.cpp
operand/Operand.cpp
parser/Token.cpp
parser/Parser.cpp
parser/Instruction.cpp
main.cpp
)

add_executable(vm ${SOURCE_FILES})