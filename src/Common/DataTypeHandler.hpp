#ifndef SRC_COMMON_DATATYPEHANDLER_HPP
#define SRC_COMMON_DATATYPEHANDLER_HPP

#include <algorithm>
#include <map>
#include <type_traits>
#include <typeinfo>

#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

Logger dataTypeLogger("DataTypeHandler");

} // namespace

enum class DataType
{
    Int,
    Unsigned,
    Long,
    LongLong,
    UnsignedLong,
    UnsignedLongLong,
    Short,
    Char,
    Bool,
    Float,
    Double,
    String,
};

template <typename T>
bool isIntegralType()
{
    return std::is_integral<T>::value;
}

template <typename T>
bool isFloatingType()
{
    return std::is_floating_point<T>::value;
}

template <typename T>
DataType getDataType()
{
    static const std::map<std::string, DataType> PRIMITIVES_ID_AND_TYPE
    {
        {"i", DataType::Int},
        {"j", DataType::Unsigned},
        {"l", DataType::Long},
        {"x", DataType::LongLong},
        {"m", DataType::UnsignedLong},
        {"y", DataType::UnsignedLongLong},
        {"s", DataType::Short},
        {"c", DataType::Char},
        {"b", DataType::Bool},
        {"f", DataType::Float},
        {"d", DataType::Double},
    };

    std::string id = typeid(T).name();
    auto it = std::find_if(PRIMITIVES_ID_AND_TYPE.begin(), PRIMITIVES_ID_AND_TYPE.end(),
                            [&id](const auto& idAndType)
                            {
                                return idAndType.first == id;
                            });

    if (it != PRIMITIVES_ID_AND_TYPE.end())
    {
        return it->second;
    }
    else if (typeid(T) != typeid(std::string))
    {
        dataTypeLogger.print("Error. Unrecognized data type. Defaulting to string!");
    }
    return DataType::String;
}

} // namespace src::common

#endif // SRC_COMMON_DATATYPEHANDLER_HPP
