/*
 * libnbt++ - A library for the Minecraft Named Binary Tag format.
 * Copyright (C) 2013, 2015  ljfa-ag
 *
 * This file is part of libnbt++.
 *
 * libnbt++ is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libnbt++ is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libnbt++.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef ENDIAN_STR_H_INCLUDED
#define ENDIAN_STR_H_INCLUDED

#include <cstdint>
#include <iosfwd>
#include "nbt_export.h"

/**
 * @brief Reading and writing numbers from and to streams
 * in binary format with different byte orders.
 */
namespace endian
{

enum endian { little, big };

///Reads number from stream in specified endian
template<class T>
void read(std::basic_istream<unsigned char>& is, T& x, endian e);

///Reads number from stream in little endian
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, uint8_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, uint16_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, uint32_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, uint64_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, int8_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, int16_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, int32_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, int64_t& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, float& x);
NBT_EXPORT void read_little(std::basic_istream<unsigned char>& is, double& x);

///Reads number from stream in big endian
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, uint8_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, uint16_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, uint32_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, uint64_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, int8_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, int16_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, int32_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, int64_t& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, float& x);
NBT_EXPORT void read_big(std::basic_istream<unsigned char>& is, double& x);

///Writes number to stream in specified endian
template<class T>
void write(std::basic_ostream<unsigned char>& os, T x, endian e);

///Writes number to stream in little endian
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, uint8_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, uint16_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, uint32_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, uint64_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, int8_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, int16_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, int32_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, int64_t x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, float x);
NBT_EXPORT void write_little(std::basic_ostream<unsigned char>& os, double x);

///Writes number to stream in big endian
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, uint8_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, uint16_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, uint32_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, uint64_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, int8_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, int16_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, int32_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, int64_t x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, float x);
NBT_EXPORT void write_big(std::basic_ostream<unsigned char>& os, double x);

template<class T>
void read(std::basic_istream<unsigned char>& is, T& x, endian e)
{
    if(e == little)
        read_little(is, x);
    else
        read_big(is, x);
}

template<class T>
void write(std::basic_ostream<unsigned char>& os, T x, endian e)
{
    if(e == little)
        write_little(os, x);
    else
        write_big(os, x);
}

}

#endif // ENDIAN_STR_H_INCLUDED
