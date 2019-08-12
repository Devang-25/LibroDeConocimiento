#include <Common/File/FileHandler.hpp>

#include <fstream>

#include <Common/Logger.hpp>

namespace src::common::file
{
namespace
{

common::Logger logger("FileHandler");

} // namespace

std::string readContentsOfFile(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName);

    std::stringstream ss;
    ss << file.rdbuf();
    file.close();

    std::string contents = ss.str();
    if (contents.empty()) logger.print("Error. File ", fileName, " either do not exist or has no contents!");
    else                  logger.print("File ", fileName, " was successfully read");

    return contents;
}

void writeContentsToFile(
    const std::string& fileName,
    const std::string& contents)
{
    std::ofstream file;
    file.open(fileName);
    file << contents;
    file.close();
}

} // namespace src::common::file
