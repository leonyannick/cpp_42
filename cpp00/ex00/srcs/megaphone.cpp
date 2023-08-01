/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:42:31 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 13:42:35 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <cstring>
#include <iostream>

void print_str_upper(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    std::cout << (char)toupper(str[i]);
  }
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  }
  for (int i = 1; i < argc; i++) {
    print_str_upper(argv[i]);
  }
  std::cout << std::endl;
  return (0);
}
