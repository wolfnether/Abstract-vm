SRC=exception/AssertNoTrueException.cpp\
exception/DivideByZeroException.cpp\
exception/EmptyStackException.cpp\
exception/NoExitException.cpp\
exception/OverflowException.cpp\
exception/SyntaxException.cpp\
exception/UnderflowException.cpp\
exception/UnknownInstructionException.cpp\
main.cpp\
operand/IOperandFactory.cpp\
operand/Operand.cpp\
operand/eOperandType.cpp\
parser/Instruction.cpp\
parser/Parser.cpp\
parser/Token.cpp\
vm/VM.cpp\

OBJ=$(SRC:%.cpp=%.o)

NAME=Avm

all: $(NAME)

$(NAME):$(OBJ)
	g++ -o $@ $^

%.o:%.cpp 
	g++ -c -o $@ $< -Werror -Wall -Wextra -std=gnu++11

clean:
	rm -Rf $(OBJ)
fclean:clean
	rm -Rf $(NAME)
re:fclean all