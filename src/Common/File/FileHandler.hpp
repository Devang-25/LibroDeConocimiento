#ifndef SRC_COMMON_FILE_FILEHANDLER_HPP
#define SRC_COMMON_FILE_FILEHANDLER_HPP

#include <iostream>
#include <string>
#include <vector>

namespace src::common::file
{

std::vector<std::vector<int>> getMatrixFromFile(
    const std::string& fileName);

std::vector<std::vector<int>> getMatrixFromStreams(
    std::istream& matrixSizeStream = std::cin,
    std::istream& matrixContentsStream = std::cin);

std::stringstream readContentsOfFile(const std::string& fileName);

void writeContentsToFile(
    const std::string& fileName,
    const std::string& contents);

} // namespace src::common::file

#endif // SRC_COMMON_FILE_FILEHANDLER_HPP
