NAME= ft_retro

SRCS= srcs/main.cpp \
	  srcs/Game.cpp \
	  srcs/AGameEntity.cpp \
	  srcs/AShip.cpp \
	  srcs/PlayerShip.cpp \
	  srcs/EnemyShip.cpp \
	  srcs/Missle.cpp \

OBJS= $(SRCS:.cpp=.o)
LIBS=

CXXFLAGS += -std=c++98

CPPFLAGS += -Wall -Wextra -Werror
CFLAGS +=
LDFLAGS += -Wall -Wextra -Werror -lncurses -fsanitize=address

CXX = clang++

.PHONY: format clean fclean re

all:$(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) $(LDFLAGS) $(CXXFLAGS) $(OBJS) -o $@

format: $(SRCS) $(HDRS)
	clang-format -style=Google -i $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

%.o: %.cpp $(HDRS)
	$(CXX) -c $(CXXFLAGS) $(CPPFLAGS) $< -o $@

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) $^ -o $@
