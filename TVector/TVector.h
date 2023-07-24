class TVector {
public:
    TVector(int size = 0);
    TVector(const TVector& other);
    TVector(int n, double* p); // конструктор инициализатор
    ~TVector();
    
    void input();
    void output() const;
    
    TVector operator+(const TVector& other) const;
    TVector operator*(double num) const;
    friend TVector operator*(double num, const TVector& vec);
    friend double operator*(const TVector& v1, const TVector& v2);

    
    TVector& operator++();
    TVector operator++(int);
    TVector& operator--();
    TVector operator--(int);
    
    bool operator==(const TVector& other) const;
    bool operator!=(const TVector& other) const;
    
    double& operator[](int index);
    const double& operator[](int index) const;
    
private:
    double* data;
    int size;
};