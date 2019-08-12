#include <Common/File/FileHandler.hpp>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

#include <boost/algorithm/string.hpp>

#include <Common/Logger.hpp>

namespace src::common::file
{
namespace
{

common::Logger logger("FileHandler");

std::stringstream parseMatrixSize(const std::stringstream& ss)
{
    std::string rowSeparator = "\n";
    std::string columnSeparator = " ";

    std::vector<std::string> rows;
    std::string streamContents = ss.str();
    boost::split(rows, streamContents, boost::is_any_of(rowSeparator));

    std::vector<std::string> columns;
    std::string line = rows.empty() ? "" : rows.front();
    boost::split(columns, line, boost::is_any_of(columnSeparator));

    std::stringstream oss;
    oss << rows.size() << " " << columns.size();

    return oss;
}

std::pair<unsigned, unsigned> getMatrixSize(std::istream& inputStream = std::cin)
{
    unsigned rows;
    unsigned cols;

    logger.print("Enter number of rows: ");
    inputStream >> rows;

    logger.print("Enter number of columns: ");
    inputStream >> cols;

    return {rows, cols};
}

std::vector<std::vector<int>> getMatrixContents(
    const unsigned rows,
    const unsigned cols,
    std::istream& inputStream = std::cin)
{
    logger.print("\nEnter ", rows, " x ", cols, " matrix");
    logger.print();

    std::vector<std::vector<int>> matrix;
    matrix.reserve(rows);
    for (unsigned rowIndex = 0u; rowIndex < rows; ++rowIndex)
    {
        matrix.push_back({});
        matrix[rowIndex].reserve(cols);
        for (unsigned colIndex = 0u; colIndex < cols; ++colIndex)
        {
            int element;
            inputStream >> element;
            matrix[rowIndex].push_back(element);
        }
    }
    return matrix;
}

} // namespace

std::vector<std::vector<int>> getMatrixFromFile(const std::string& fileName)
{
    auto matrixContentsStream = readContentsOfFile(fileName);
    auto matrixSizeStream = parseMatrixSize(matrixContentsStream);
    return getMatrixFromStreams(matrixSizeStream, matrixContentsStream);
}

std::vector<std::vector<int>> getMatrixFromStreams(
    std::istream& matrixSizeStream,
    std::istream& matrixContentsStream)
{
    auto [rows, cols] = getMatrixSize(matrixSizeStream);
    return getMatrixContents(rows, cols, matrixContentsStream);
}

std::stringstream readContentsOfFile(const std::string& fileName)
{
    std::ifstream file;
    file.open(fileName);

    std::stringstream ss;
    ss << file.rdbuf();
    file.close();

    std::string contents = ss.str();
    if (contents.empty()) logger.print("Error. File ", fileName, " either do not exist or has no contents!");
    else                  logger.print("File ", fileName, " was successfully read");

    return ss;
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
