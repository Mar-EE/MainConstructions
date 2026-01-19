#pragma once
#include <exception>
#include <iostream>
#include <algorithm>
#include <cstddef>

class Bad_range : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Индекс выходит за пределы контейнера!";
    }
};

class Bad_length : public std::exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "Задана неправильная длина контейнера!";
    }
};

template <typename X> class Array
{
public:
    Array() = default;
    Array(int length) : _length{ length } {
        if (length < 0)
        {
            throw Bad_length();
        }
        _data = new X[length]{};
    }
    ~Array() {
        delete[] _data;
    }


    X& operator[](int index) {
        if (index < 0 || index >= _length)
        {
            throw Bad_range();
        }
        return _data[index];
    }

    void erase() {
        delete[] _data;
        _data = nullptr;
        _length = 0;
    }

    void resize(int newLength) {
        if (newLength == _length)
            return;

        if (newLength <= 0)
        {
            erase();
            return;
        }

        X* data{ new X[newLength] };

        if (_length > 0)
        {
            int elementsToCopy{ (newLength > _length) ? _length : newLength };
            std::copy_n(_data, elementsToCopy, data);
        }

        delete[] _data;

        _data = data;
        _length = newLength;
    }

    void add(X value) {
        if (_lastIndex == _length)
        {
            resize(_length + _increaseLength);
        }
        _data[_lastIndex] = value;
        _lastIndex++;
    }

    int findValue(X value) {
        for (int i{ 0 }; i < this->_length; ++i)
        {
            if (this->_data[i] == value)
            {
                return i;
            }
        }
        return -1;
    }

    int getLength() const {
        return _length;
    }

    int getLastIndex() const {
        return _lastIndex;
    }

private:
    int const _increaseLength = 100;
    int _lastIndex{0};
    int _length{};
    X* _data{};
};