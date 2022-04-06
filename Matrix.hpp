#include <iostream>
#include <vector>

namespace zich{
  

    class Matrix
    {
        struct myMatrix
        {
            std::vector<std::vector<double>> matrix;

        };
        
        private:
        std::vector<double> _arr;
        int _row=0;
        int _cols=0;
        myMatrix mymatrix;

        public:

        Matrix();
        Matrix(const std::vector<double>&  arr,int ,int );
        Matrix operator*=(double);
        Matrix operator-(const Matrix& m );
        Matrix operator*(const Matrix& m);
        Matrix operator+(const Matrix& m);
        Matrix operator-();
        bool operator==(const Matrix&m);
        bool operator>=(const  Matrix&m);
        bool operator>(const Matrix&m);

        friend  Matrix operator*(int,const Matrix& m);

        friend std::ostream & operator<< (std::ostream &stream, const  Matrix &matrix );
        void setrow(int row){this->_row=row;}
        void setcol(int col){this->_cols=col;}
        void setarr(std::vector<double> arr){this->_arr=arr;}
        void setmatrix(std::vector<std::vector<double>> mat){this->mymatrix.matrix=mat;}
        int getrow(){return this->_row;}
        int getcol(){return this->_cols;}
        std::vector<double> getarr(){return this->_arr;}
        std::vector<std::vector<double>> getmatrix(){return this->mymatrix.matrix;}






    };
    
}