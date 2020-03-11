#include <iostream>
#include <sstream>

struct NotEsc : public std::runtime_error {
    using std::runtime_error::runtime_error;
};

class Vim {
public:
    explicit Vim(std::istream& istream) : istream_(istream) {
    }
    
    std::string ReadLine() {
        std::string result;
        char symbol = istream_.peek();
        if (symbol == '<') {
            Esc();
        }
        
        if (mode_ == Mode::READ) {
            
        }
        
    }
    
    enum class Mode {
        READ,
        WRITE
    };
    
    void Esc() {
        if (istream_.get() != '<'
                || istream_.get() != 'E'
                || istream_.get() != 'S'
                || istream_.get() != 'C'
                || istream_.get() != '>') {
            throw NotEsc("Expected '<ESC>'");
        }
        mode_ = Mode::READ;
    }

private:
    std::istream& istream_;
    Mode mode_ = Mode::READ;
};

int main() {
    Vim vim(std::cin);
    return 0;
}
