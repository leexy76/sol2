// The MIT License (MIT) 

// Copyright (c) 2013-2016 Rapptz, ThePhD and contributors

// Permission is hereby granted, free of charge, to any person obtaining a copy of
// this software and associated documentation files (the "Software"), to deal in
// the Software without restriction, including without limitation the rights to
// use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
// the Software, and to permit persons to whom the Software is furnished to do so,
// subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
// FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
// IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef SOL_USERDATA_HPP
#define SOL_USERDATA_HPP

#include "reference.hpp"

namespace sol {
class userdata : public reference {
public:
    userdata () noexcept = default;
    userdata(const userdata&) = default;
    userdata(userdata&&) = default;
    userdata& operator=(const userdata&) = default;
    userdata& operator=(userdata&&) = default;
    userdata(lua_State* L, int index = -1) : reference(L, index) {
#ifdef SOL_CHECK_ARGUMENTS
        type_assert(L, index, type::userdata);
#endif // Safety
    }
};

class lightuserdata : public reference {
public:
    lightuserdata () noexcept = default;
    lightuserdata(const lightuserdata&) = default;
    lightuserdata(lightuserdata&&) = default;
    lightuserdata& operator=(const lightuserdata&) = default;
    lightuserdata& operator=(lightuserdata&&) = default;
    lightuserdata(lua_State* L, int index = -1) : reference(L, index) {
#ifdef SOL_CHECK_ARGUMENTS
        type_assert(L, index, type::lightuserdata);
#endif // Safety
    }
};

} // sol

#endif // SOL_USERDATA_HPP
