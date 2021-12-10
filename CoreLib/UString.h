/*
* @Moudule     : String
* @Date        : 2021/05/24
* @Author      : JomiXedYu
* @Description : This file is part of JxCode.CoreLib : https://github.com/JomiXedYu/JxCode.CoreLib
* @StdRequired : c++17
*/

#ifndef _CORELIB_STRING_H
#define _CORELIB_STRING_H

#include <vector>
#include <string>
#include <cstring>
#include <cstdint>

//Encoding: UTF-8

namespace JxCoreLib
{

    using string = std::string;
    using string_view = std::string_view;

    struct u8char final
    {
        char value[8]{ 0 };
        inline static int U8Length(const char* c)
        {
            for (int i = 0; i < 8; i++)
            {
                if (c[i] == 0) {
                    return i;
                }
            }
            return 8;
        }
        inline static void Charcpy(char* dest, const char* src)
        {
            for (int i = 0; i < 8; i++) dest[i] = src[i];
        }
        inline static bool Charcmp(const char* l, const char* r)
        {
            int len = U8Length(l);
            if (len != U8Length(r))
            {
                return false;
            }
            for (int i = 0; i < len; i++)
            {
                if (l[i] != r[i]) return false;
            }

            return true;
        }
        u8char() {}
        u8char(const char* c)
        {
            Charcpy(this->value, c);
        }
        bool operator==(const u8char& r)
        {
            return Charcmp(this->value, r.value);
        }
        bool operator!=(const u8char& r)
        {
            return !Charcmp(this->value, r.value);
        }
        string ToString()
        {
            return string(value);
        }

    };

    bool operator==(const u8char& left, const string& right);
    bool operator==(const string& left, const u8char& right);
    bool operator!=(const u8char& left, const string& right);
    bool operator!=(const string& left, const u8char& right);
    string operator+(const u8char& left, const string& right);
    string operator+(const string& left, const u8char& right);

    struct StringIndexMapping final
    {
    private:
        size_t block_size_;
    public:
        StringIndexMapping(string_view str, size_t block_size) noexcept(false);
    public:
        std::vector<int> mapping;
        size_t get_block_size() const;
        size_t get_block_count() const;
    public:
        size_t GetOffset(const size_t& pos) const noexcept(false);
        size_t GetBlockPos(const size_t& pos) const noexcept(false);
    };

    namespace StringUtil
    {
        bool IsLittleEndian() noexcept;
        size_t U8Length(string_view str, size_t pos) noexcept(false);
        string Replace(string_view src, string_view oldstr, string_view newstr);
        u8char PosAt(const string_view& src, const size_t& bytepos);
        u8char CharAt(const string_view& src, const size_t& charpos);
        u8char CharAt(const string_view& src, const size_t& charpos, const StringIndexMapping& mapping);
        size_t Length(const string_view& src);
        size_t Length(const string_view& src, const StringIndexMapping& mapping);
        std::vector<uint8_t> GetBytes(const string_view& str);
        std::u16string Utf8ToUtf16(const string& str);
        string Utf16ToUtf8(const std::u16string& str);
        string StringCast(const std::u8string& str);

        inline size_t Size(const char* str) { return ::strlen(str); }
        inline size_t Size(const string& str) { return str.length(); }
        inline size_t Size(string_view str) { return str.length(); }

        template<typename... TArgs>
        constexpr inline size_t Sum(TArgs... args) { return (arg + ... + 0); }

        inline void AppendStr(string& str, const char* nstr) { str.append(nstr); }
        inline void AppendStr(string& str, const string& nstr) { str.append(nstr); }
        inline void AppendStr(string& str, string_view nstr) { str.append(nstr); }

        inline void Append(string& str) {}

        template<typename T, typename... TArgs>
        inline void Append(string& str, const T& nstr, TArgs&&... args)
        {
            AppendStr(str, nstr);
            Append(str, args...);
        }

        template<typename... T>
        string Concat(const T&... args) {
            size_t size = Sum(Size(args)...);
            string str;
            str.reserve(size + 1);
            Append(str, args...);
            return str;
        }
    };

}


#endif // !_CORELIB_STRING_H
