#ifndef SRC_COMMON_RESULTHANDLER_HPP
#define SRC_COMMON_RESULTHANDLER_HPP

#include <utility>

#include <Common/DataTypeHandler.hpp>
#include <Common/Logger.hpp>

namespace src::common
{
namespace
{

Logger resultLogger("ResultHandler");

} // namespace

// Resource acquisition is initialization (RAII)
class Result
{
public:
    Result() :
        type_(DataType::String),
        data_(nullptr)
    {
    }

    Result(const Result& other)
    {
        initializeBasedOnOtherResult(other);
    }

    Result(Result&& other)
    {
        moveOtherResult(std::forward<Result>(other));
    }

    Result& operator=(const Result& other)
    {
        cleanUpData();
        initializeBasedOnOtherResult(other);
        return *this;
    }

    Result& operator=(Result&& other)
    {
        cleanUpData();
        moveOtherResult(std::forward<Result>(other));
        return *this;
    }

    ~Result()
    {
        cleanUpData();
    }

    template <typename T>
    Result& set(const T& data)
    {
        cleanUpData();
        type_ = getDataType<T>();
        data_ = new T(data);
        return *this;
    }

    template <typename T>
    T get() const
    {
        return *(static_cast<T*>(data_));
    }

private:
    void initializeBasedOnOtherResult(const Result& other)
    {
        type_ = other.type_;
        switch(other.type_)
        {
            case DataType::Int :              { data_ = newData<int>(other.data_);                break; }
            case DataType::Unsigned :         { data_ = newData<unsigned>(other.data_);           break; }
            case DataType::Long :             { data_ = newData<long>(other.data_);               break; }
            case DataType::LongLong :         { data_ = newData<long long>(other.data_);          break; }
            case DataType::UnsignedLong :     { data_ = newData<unsigned long>(other.data_);      break; }
            case DataType::UnsignedLongLong : { data_ = newData<unsigned long long>(other.data_); break; }
            case DataType::Short :            { data_ = newData<short>(other.data_);              break; }
            case DataType::Char :             { data_ = newData<char>(other.data_);               break; }
            case DataType::Bool :             { data_ = newData<bool>(other.data_);               break; }
            case DataType::Float :            { data_ = newData<float>(other.data_);              break; }
            case DataType::Double :           { data_ = newData<double>(other.data_);             break; }
            case DataType::String :           { data_ = newData<std::string>(other.data_);        break; }
            default: resultLogger.print("Error. Unrecognized data type. Brace yourself, memory leak is coming!");
        }
    }

    template <typename T>
    T* newData(void* data)
    {
        return new T(*(static_cast<T*>(data)));
    }

    void cleanUpData()
    {
        if (!data_) return;
        switch(type_)
        {
            case DataType::Int :              { deleteData<int>(data_);                break; }
            case DataType::Unsigned :         { deleteData<unsigned>(data_);           break; }
            case DataType::Long :             { deleteData<long>(data_);               break; }
            case DataType::LongLong :         { deleteData<long long>(data_);          break; }
            case DataType::UnsignedLong :     { deleteData<unsigned long>(data_);      break; }
            case DataType::UnsignedLongLong : { deleteData<unsigned long long>(data_); break; }
            case DataType::Short :            { deleteData<short>(data_);              break; }
            case DataType::Char :             { deleteData<char>(data_);               break; }
            case DataType::Bool :             { deleteData<bool>(data_);               break; }
            case DataType::Float :            { deleteData<float>(data_);              break; }
            case DataType::Double :           { deleteData<double>(data_);             break; }
            case DataType::String :           { deleteData<std::string>(data_);        break; }
            default: resultLogger.print("Error. Unrecognized data type. Brace yourself, memory leak is coming!");
        }
    }

    template <typename T>
    void deleteData(void* data)
    {
        delete static_cast<T*>(data);
    }

    void moveOtherResult(Result&& other)
    {
        type_ = other.type_;
        data_ = other.data_;

        other.type_ = DataType::String;
        other.data_ = nullptr;
    }

    void moveOtherResult(const Result& other) = delete;

    DataType type_;
    void* data_;
};

} // namespace src::common

#endif // SRC_COMMON_RESULTHANDLER_HPP
