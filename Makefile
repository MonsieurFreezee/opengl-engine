FILES 		=	main.cpp														\
				components/entity.cpp											\
				components/mesh.cpp												\
				components/model.cpp											\
				components/texture.cpp											\
				engine/render.cpp												\
				engine/window.cpp												\
				entities/camera.cpp												\
				entities/player.cpp												\
				interfaces/renderable.cpp										\
				interfaces/updateable.cpp										\
				maths/position.cpp												\
				maths/rotation.cpp												\
				shaders/shader_program.cpp										\
				shaders/shader.cpp												\
				utils/io_utils.cpp												\
				utils/obj_loader.cpp											\
				utils/string_utils.cpp

NAME		=	opengl-engine
CXX			=	g++
LDFLAGS 	=	-lGL -lglut -lGLEW -lGLU -lglfw -lSOIL -lX11 -lXxf86vm -lXrandr -lpthread -lXi
CXXFLAGS	=	-I includes/ -std=c++14 -W -Wall -Werror $(LDFLAGS)
SRC 		=	$(addprefix src/,$(FILES))
OBJ 		=	$(SRC:.cpp=.o)

run: all
	./$(NAME)

all: $(NAME) clean

$(NAME): $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean fclean

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)
