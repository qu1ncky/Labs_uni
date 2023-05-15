    #include "TCompl.h"

    TCompl::TCompl(double re, double im)
        : Re(re), Im(im) {
        std::cout << "Конструктор с параметрами." << std::endl;
    }

    TCompl::TCompl()
        : Re(0), Im(0) {
        std::cout << "Конструктор по умолчанию." << std::endl;
    }

    TCompl::TCompl(const TCompl& ob)
        : Re(ob.Re), Im(ob.Im) {
        std::cout << "Конструктор копирования." << std::endl;
    }

    TCompl::TCompl(double x)
        : Re(x), Im(0) {}

    TCompl::~TCompl() {
        std::cout << "Деструктор" << std::endl;
    }

    TCompl& TCompl::operator=(const TCompl& op2) {
        if (this == &op2)
            return *this;

        Re = op2.Re;
        Im = op2.Im;
        return *this;
    }

    TCompl& TCompl::operator+=(const TCompl& op2) {
        Re += op2.Re;
        Im += op2.Im;
        return *this;
    }

    TCompl& TCompl::operator-=(const TCompl& op2) {
        Re -= op2.Re;
        Im -= op2.Im;
        return *this;
    }

    TCompl& TCompl::operator*=(const TCompl& op2) {
        double tempRe = Re * op2.Re - Im * op2.Im;
        Im = Re * op2.Im + op2.Re * Im;
        Re = tempRe;
        return *this;
    }

    TCompl& TCompl::operator/=(const TCompl& op2) {
        try {
            if (op2.Re * op2.Re + op2.Im * op2.Im == 0)
                throw std::runtime_error("Ошибка! Деление на ноль.\n");

            double tempRe = (Re * op2.Re + Im * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
            Im = (op2.Re * Im - Re * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
            Re = tempRe;
        } catch (const std::exception& e) {
            std::cout << e.what();
        }
        return *this;
    }

    TCompl TCompl::operator+(const TCompl& op2) const {
        TCompl res(Re + op2.Re, Im + op2.Im);
        return res;
    }

    TCompl operator+(double op1, const TCompl& op2) {
        TCompl res(op1 + op2.Re, op2.Im);
        return res;
    }

    TCompl TCompl::operator-(const TCompl& op2) const {
        TCompl res(Re - op2.Re, Im - op2.Im);
        return res;
    }

    // TCompl operator-(double op1, const TCompl& op2) {
    //     TCompl res(op1 - op2.Re, -op2.Im);
    //     return res;
    // }

    TCompl TCompl::operator*(const TCompl& op2) const {
        TCompl res(Re * op2.Re - Im * op2.Im, Re * op2.Im + op2.Re * Im);
        return res;
    }

    TCompl TCompl::operator/(const TCompl& op2) const {
        TCompl res;
        try {
            if (op2.Re * op2.Re + op2.Im * op2.Im == 0)
                throw std::runtime_error("Ошибка! Деление на ноль.\n");

            res.Re = (Re * op2.Re + Im * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
            res.Im = (op2.Re * Im - Re * op2.Im) / (op2.Re * op2.Re + op2.Im * op2.Im);
        } catch (const std::exception& e) {
            std::cout << e.what();
        }
        return res;
    }

    bool TCompl::operator==(const TCompl& op2) const {
        return (Re == op2.Re) && (Im == op2.Im);
    }

    void TCompl::print() const {
        std::cout << Re;
        if (Im > 0) {
            if (Im == 1) {
                std::cout << " + " << "i";
            } else {
                std::cout << " + " << Im << "i";
            }
        } else if (Im < 0) {
            if (Im == -1) {
                std::cout << " - " << "i";
            } else {
                std::cout << " - " << -1 * Im << "i";
            }
        }
        std::cout << std::endl;
    }

    TCompl& TCompl::input() {
    std::cout << "Введите вещественную часть: ";
    std::cin >> Re;
    std::cout << "Введите мнимую часть: ";
    std::cin >> Im;
    return *this;
    }