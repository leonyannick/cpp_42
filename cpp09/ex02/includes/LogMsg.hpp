#ifndef LOGMSG_HPP
# define LOGMSG_HPP

#define BG_BOLD_BLACK "\033[1;40m"
#define BG_BOLD_RED "\033[1;41m"
#define BG_BOLD_GREEN "\033[1;42m"
#define BG_BOLD_YELLOW "\033[1;43m"
#define BG_BOLD_BLUE "\033[1;44m"
#define BG_BOLD_MAGENTA "\033[1;45m"
#define BG_BOLD_CYAN "\033[1;46m"
#define BG_BOLD_WHITE "\033[1;47m"

#define RESET "\033[0m"

#define LOG_DEBUG 0

#define LOG_MSG(option, color, statement) \
	if (option == 1) \
    	std::cout << color << statement << RESET << std::endl; \

#endif

