// MIT License
// 
// Copyright(c) 2018 Jang daemyung
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef UTL_SINGLETON_H
#define UTL_SINGLETON_H

#include <cassert>
#include <memory>

#include "noncopyable.h"
#include "nonmovable.h"

namespace utl
{

template <typename Class>
class Singleton : private Noncopyable, private Nonmovable
{
	template <typename Class>
	friend class SingletonFactory;

public:
	static auto& get ()
	{
		assert
		(
			nullptr != instance_ptr_ && "Singleton isn't created!!!"
		);

		return *instance_ptr_;
	}

private:
	static std::unique_ptr<Class> instance_ptr_;
};

template <typename Class>
std::unique_ptr<Class> Singleton<Class>::instance_ptr_ = nullptr;

}

#endif