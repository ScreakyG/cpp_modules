/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgonzale <fgonzale@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:29:09 by fgonzale          #+#    #+#             */
/*   Updated: 2023/12/28 15:08:59 by fgonzale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void copy_file(std::ifstream& inputFile, std::string& filename, std::string& s1, std::string& s2)
{
	std::string suffix = ".replace";
	std::string outfileName = filename + suffix;
	std::ofstream outputFile(outfileName.c_str());
	std::string line;

	if (!outputFile.is_open())
	{
		std::perror("Error ");
		inputFile.close();
		return ;
	}
	while (getline(inputFile, line))
	{
		std::size_t found = line.find(s1);
		while (!s1.empty() && found != std::string::npos)
		{
			line.erase(found, s1.length());
			line.insert(found, s2);
			found = line.find(s1, found + s2.length());
		}
		outputFile << line << std::endl;
	}
	outputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Please use like this : ./a.out <filename> <s1> <s2>." << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::ifstream inputFile(filename.c_str());
	if (inputFile.is_open())
		copy_file(inputFile, filename, s1, s2);
	else
	{
		std::perror("Error ");
		return (1);
	}
	inputFile.close();
	return (0);
}