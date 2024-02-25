#include "safe_int_array.h"
#include <stdexcept>

safe_int_array::safe_int_array(size_t sz) :
    size(sz),
    values(new int[sz])
{}

safe_int_array::safe_int_array(const safe_int_array &other) :
    size(other.size),
    values(new int[other.size])
{
    for (int i = 0; i < other.size; i++) {
        values[i] = other.values[i];
    }
}

safe_int_array& safe_int_array::operator=(const safe_int_array &other) {

    if (size != other.size) {
        size = other.size;
        delete[] values;
        values = new int[other.size];
    }

    for (int i = 0; i < other.size; i++) {
        values[i] = other.values[i];
    }
    return *this;
}

safe_int_array::~safe_int_array() {
    delete[] values;
}

int safe_int_array::get_value(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Bad index");
    }
    return values[index];
}

void safe_int_array::set_value(size_t index, int value) {
    if (index >= size) {
        throw std::out_of_range("Bad index");
    }
    values[index] = index;
}

void safe_int_array::print(std::ostream& out) const {
    out << "{";
    for (size_t i = 0; i < size; i++) {
        if (i > 0) {
            out << ", ";
        }
        out << values[i];
    }

    out << "}" << std::endl;
}

int safe_int_array::get_size() const {
   return size;
}

safe_int_array::safe_int_array(std::initializer_list<int> item) :
        size(item.size()),
        values(new int[item.size()])
{
    size_t i = 0;
    for (int val : item) {
        values[i] = val;
        i++;
    }
}

int& safe_int_array::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Bad index");
    }

    return values[index];
}