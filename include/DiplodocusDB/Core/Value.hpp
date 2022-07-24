/*
    Copyright (c) 2018-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/diplodocusdb/core/blob/main/LICENSE.txt
*/

#ifndef _DIPLODOCUSDB_CORE_VALUE_HPP_
#define _DIPLODOCUSDB_CORE_VALUE_HPP_

#include "DataType.hpp"
#include <boost/date_time.hpp>
#include <boost/variant.hpp>
#include <string>

namespace DiplodocusDB
{

/// The data stored in a node and its type.
class Value
{
public:
    /// Constructor.
    /**
        The default constructor creates a value of type NULL.
    */
    Value();
    static Value Boolean(bool data);
    /// Returns a value of type Int8.
    /**
        @param data The data to store in the value.
    */
    static Value Int8(int8_t data);
    static Value Int16(int16_t data);
    /// Returns a value of type Int32.
    /**
        @param data The data to store in the value.
    */
    static Value Int32(int32_t data);
    static Value Int64(int64_t data);
    static Value UnsignedInt64(uint64_t data);
    static Value Double(double data);
    /// Returns a value of type UTF8String.
    /**
        @param data The data to store in the value.
    */
    static Value UTF8String(const std::string& data);
    static Value Binary(const std::string& data);
    static Value Date(const boost::gregorian::date& data);
    
    /// Returns the type of the data.
    const DataType& type() const;

    bool asBoolean() const;
    int8_t asInt8() const;
    int16_t asInt16() const;
    int32_t asInt32() const;
    int64_t asInt64() const;
    uint64_t asUnsignedInt64() const;
    double asDouble() const;
    const std::string& asUTF8String() const;
    const std::string& asBinary() const;
    const boost::gregorian::date& asDate() const;

    bool operator ==(const Value& other) const;
    bool operator !=(const Value& other) const;

    void setBoolean(bool data);
    void setInt8(int8_t data);
    void setInt16(int16_t data);
    void setInt32(int32_t data);
    void setInt64(int64_t data);
    void setUnsignedInt64(uint64_t data);
    void setDouble(double data);
    void setUTF8String(const std::string& data);
    void setBinary(const std::string& data);
    void setDate(const boost::gregorian::date& data);

private:
    DataType m_type;
    boost::variant<bool, int8_t, int16_t,int32_t, int64_t, uint64_t, double, std::string, boost::gregorian::date> m_data;
};

}

#endif
