NAME = a.out

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
CXX = c++
SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp
SRCS_OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(NAME): $(SRCS_OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS_OBJS) -o $(NAME)

clean:
		rm -rf $(SRCS_OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all
