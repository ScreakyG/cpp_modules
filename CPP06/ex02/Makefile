NAME = a.out

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -g
CXX = c++

SRCS = main.cpp 
SRCS_OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

all: $(NAME)

# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(NAME): $(SRCS_OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
		rm -rf $(SRCS_OBJS) $(DEPS)

fclean: clean
		rm -rf $(NAME)

re: fclean all

-include $(DEPS)
