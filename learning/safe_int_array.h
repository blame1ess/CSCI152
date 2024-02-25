#include <string>
#include <ostream>

class safe_int_array {
    size_t size;
    int* values;
public:
    // creates a fresh int array of given size / constructor
    safe_int_array(size_t sz);

    // Copy constructor (make a copy of the safe_int_array into the newly created safe array
    safe_int_array(const safe_int_array& other);

    // Assignment
    safe_int_array& operator = (const safe_int_array& other);

    //Value getter - throws an exception if the value is bad
    int get_value(size_t index) const;

    //Value setter - throws an exception if the index is bad
    void set_value(size_t index, int value);

    int get_size() const;

    void print(std::ostream& out) const;

    // Initializer - list constructor
    safe_int_array(std::initializer_list<int> item);

    // [] Accessor - throws an exception if the index is bad.
    int& operator[] (size_t index);

    //destructor
    ~safe_int_array();
};