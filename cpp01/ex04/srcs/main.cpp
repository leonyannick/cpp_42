/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaumann <lbaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:59 by lbaumann          #+#    #+#             */
/*   Updated: 2023/08/02 16:55:02 by lbaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Sed.hpp"

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

	//construcor of fstream take a c string
	//open infile and save its content in a string stream
	//convert the stringstream to a std::string and save inside text
	std::ifstream	ifs(infile.c_str());
	if (ifs.fail()) {
		std::perror("infile");
		return ( EXIT_FAILURE );
	}
	std::stringstream	buffer;
	buffer << ifs.rdbuf();
	ifs.close();
	std::string		text = buffer.str();
	
	//look for all occurrences of key and replace them with replacement
	size_t		pos = 0;
	while (( pos = text.find(key, pos) ) != std::string::npos) {
		text.erase(pos, key.length());
		text.insert(pos, replacement);
	}

	std::ofstream	ofs(outfile.c_str());
	if (ofs.fail()) {
		std::perror("outfile");
		return ( EXIT_FAILURE );
	}
	ofs << text;
	ofs.close();
	return ( EXIT_SUCCESS );
}
