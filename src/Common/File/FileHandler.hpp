#ifndef SRC_COMMON_FILE_FILEHANDLER_HPP
#define SRC_COMMON_FILE_FILEHANDLER_HPP

#include <string>

namespace src::common::file
{

std::string readContentsOfFile(const std::string& fileName);

void writeContentsToFile(
    const std::string& fileName,
    const std::string& contents);

} // namespace src::common::file

#endif // SRC_COMMON_FILE_FILEHANDLER_HPP
