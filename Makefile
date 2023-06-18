##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## MAKEFILE
##

SRC	= 	raytrecor.cpp		\
		parser.cpp			\
		generator_image.cpp	\

OBJ = $(subst .cpp,.o,$(SRC))

MAIN = raytracer

$(MAIN): $(OBJ)
	g++ -o $(MAIN) $(OBJ) -lconfig++

all: $(MAIN)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(MAIN)

re: fclean all