#include <iostream>
#include <vector>
#include "Matrix.hpp"
using namespace std;
using namespace zich;

    zich::Matrix::Matrix(std::vector<double> const & arr,int row,int col)
    {
        int arrlen=arr.size();
        if(row<=0||col<=0||arrlen!=(row*col))
        {
            	string ex="not a valid code";
		        throw invalid_argument(ex);
        }

        unsigned long row1=(unsigned long)(row);
        unsigned long col1=(unsigned long)(col);
       this->setcol(col);

       this->setrow(row);
       this->setarr(arr);
       vector<vector<double>> mat(row1,vector<double>(col1,0));
       for (size_t i = 0; i < row; i++)
       {
           for (size_t j = 0; j < col; j++)
           {
            mat[i][j]=arr[i*col1+j];
           }
           
       }
       this->setmatrix(mat);
       
       
    }
    zich::Matrix zich::Matrix::operator*=(double d)
    {
        unsigned long cols=(unsigned long)(this->getcol());
                vector<double> arr=this->getarr();
                vector<vector<double>> mat=this->getmatrix();         
               for (size_t i = 0; i < this->getrow(); i++)
               {
                   for (size_t j = 0; j < this->getcol(); j++)
                   {
                       mat[i][j]*=d;
                       arr[i*cols+j]*=d;                 }
                   
               }
               this->setarr(arr);
                this->setmatrix(mat);
               return *this;
    }
    zich::Matrix zich::Matrix::operator-(zich::Matrix const & mat){
        if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }
       vector<double> arr=this->getarr();
        unsigned long cols=(unsigned long)(this->getcol());

        for (size_t i = 0; i < mat._row; i++)
        {
            for (size_t j = 0; j < mat._cols; j++)
            {
              arr[i*cols+j]-=mat.mymatrix.matrix[i][j];
            }
            
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
        
        
    }
    zich::Matrix zich::Matrix::operator+(zich::Matrix const & mat)
    {
                if (this->getrow()!=mat._row||this->getcol()!=mat._cols)
        {
                string ex="not a valid code";
		        throw invalid_argument(ex);
        }


        unsigned long cols=(unsigned long)(this->getcol());
        vector< double> arr=this->getarr();

        for (size_t i = 0; i < mat._row; i++)
        {
            for (size_t j = 0; j < mat._cols; j++)
            {
              arr[i*cols+j]+=mat.mymatrix.matrix[i][j];
            }
            
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
    } 
     zich::Matrix zich::Matrix::operator*(zich::Matrix const & mat)
    {
        if (this->getcol()!=mat._row)
        {
                	string ex="not a valid code";
		        throw invalid_argument(ex);
        }
        
        return mat;
    }
        bool zich::Matrix::operator==(zich::Matrix const & mat)
    {
        return true;
    }
           bool zich::Matrix::operator>=(zich::Matrix const & mat)
    {
        return true;
    }
           bool zich::Matrix::operator>(zich::Matrix const  &mat)
    {
        return true;
    }
    zich::Matrix zich::Matrix::operator-()
    {
        vector<vector<double>> mat=this->getmatrix();
                unsigned long cols=(unsigned long)(this->getcol());

       vector<double> arr=this->getarr();
       for (size_t i = 0; i <arr.size(); i++)
       {
        arr[i]*=-1;
       }
       Matrix ret{arr,this->getrow(),this->getcol()};
       return ret;
    }
    zich::Matrix zich::operator*(int d,const zich::Matrix& mat){
        unsigned long cols=(unsigned long)(mat._cols);
        vector<double> arr=mat._arr;
        for (size_t i = 0; i < arr.size(); i++)
        {
            arr[i]*=d;
        }
        Matrix ret{arr,mat._row,mat._cols};
        return ret;
    }

std::ostream & zich::operator<<(std::ostream& stream, const zich::Matrix& x){
    for (size_t i = 0; i < x._row; i++)
    {
        stream<<"[";
        for (size_t j = 0; j < x._cols; j++)
        {
            stream<<x.mymatrix.matrix[i][j];
            stream<<" ";
        }
                stream<<"]\n";

        
    }
    
    return stream;
}