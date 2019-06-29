#ifndef SRC_COMMON_RESULTHANDLER_HPP
#define SRC_COMMON_RESULTHANDLER_HPP

#include <Common/DataTypeHandler.hpp>
#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

Logger resultLogger("ResultHandler");

} // namespace

class Result
{
public:
    Result() :
        type_(DataType::Int),
        data_(nullptr)
    {
    }

    Result(const Result& other) :
        type_(other.type_),
        data_(other.data_)
    {
    }

    Result& operator=(const Result& other)
    {
        deleteData();
        type_ = other.type_;
        data_ = other.data_;
        return *this;
    }

    ~Result()
    {
        deleteData();
    }

    template <typename T>
    void set(const T& data)
    {
        deleteData();
        type_ = getDataType<T>();
        data_ = new T(data);
    }

    template <typename T>
    T get() const
    {
        return *(static_cast<T*>(data_));
    }

private:
    void deleteData()
    {
        if (!data_) return;
        switch(type_)
        {
            case DataType::Int :      { delete static_cast<int*>(data_);         break; }
            case DataType::Unsigned : { delete static_cast<unsigned*>(data_);    break; }
            case DataType::Long :     { delete static_cast<long*>(data_);        break; }
            case DataType::Short :    { delete static_cast<short*>(data_);       break; }
            case DataType::Char :     { delete static_cast<char*>(data_);        break; }
            case DataType::Bool :     { delete static_cast<bool*>(data_);        break; }
            case DataType::Float :    { delete static_cast<float*>(data_);       break; }
            case DataType::Double :   { delete static_cast<double*>(data_);      break; }
            case DataType::String :   { delete static_cast<std::string*>(data_); break; }
            default: resultLogger.print("Unrecognized data type. Brace yourself, memory leak is coming!");
        }
    }

    DataType type_;
    void* data_;
};

} // namespace src::common

#endif // SRC_COMMON_RESULTHANDLER_HPP
