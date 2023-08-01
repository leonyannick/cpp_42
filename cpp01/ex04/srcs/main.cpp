/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/01 19:36:34 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

/**
 * loops through str and finds occurrences of key and replaces them with
 * replacement
*/
static std::string		findAndReplace( std::string str, std::string key,
										std::string replacement ) {
	size_t		pos;
	
	while (1) {
		pos = str.find(key, 0);
		if (pos == std::string::npos)
			break;
		str.erase(pos, key.length());
		str.insert(pos, replacement);
	}
	return (str);
}

/**
 * takes 3 cmd line arguments: <filename>, <key>, <replacement>
 * program searches filename for occurrences of key and replaces it with
 * replacement -> everything is saved in the output file with the name
 * <filename>.replace
*/
int main( int argc, char **argv ) {
	if ( argc != 4) {
		std::cout << USAGE << std::endl;
		return ( EXIT_SUCCESS );
	}
	
	std::string		infile = argv[1];
	std::string		outfile = infile + ".replace";
	std::string		key = argv[2];
	std::string		replacement = argv[3];

	std::string		line;
	//construcor of fstream take a c string
	std::ifstream	ifs(infile.c_str());
	std::ofstream	ofs(outfile.c_str());

	//parse file line by line, replace occurrences and append to outfile
	while (1) {
		std::getline(ifs, line);
		if (line.empty())
			break;
		// std::cout << line << std::endl;
		ofs << findAndReplace(line, key, replacement) << std::endl;
	}
	ifs.close();
	ofs.close();
	return ( EXIT_SUCCESS );
}
