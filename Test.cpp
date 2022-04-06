#include "doctest.h"
#include "Matrix.hpp"
#include <string.h>
using namespace std;
using namespace zich;
    std::vector<double> arr1={1,2,3,4,5,6,7,8,9};
    std::vector<double> arr2={1,2,3,4,5,6,7,8};
    std::vector<double> arr3={1,2,3,4,5,6};
    std::vector<double> arr4={9,8,7,6,5,4,3,2,1};
    std::vector<double> idn={1,0,0,0,1,0,0,0,1};
    std::vector<double> arr5={1,1.5,2,2.5,3,3.5,4,4.5,5};



    TEST_CASE("Good input") {//test1
    zich::Matrix x1{arr1,3,3};
    vector<vector<double>> t={{1,2,3},{4,5,6},{7,8,9}};
    CHECK(x1.getmatrix()==t);//1

    vector<vector<double>> t0={{10,10,10},{10,10,10},{10,10,10}};
      zich::Matrix x{arr1,3,3};
      zich::Matrix y1{arr4,3,3};
      zich::Matrix z=x+y1;
      CHECK(z.getmatrix()==t0);//2

    Matrix x2(arr1,1,9);
    vector<vector<double>> t1={{-1,-2,-3,-4,-5,-6,-7,-8,-9}};
    CHECK((-x).getmatrix()==t1);//3
    
    Matrix m(arr2,2,4);
    vector<vector<double>> t2={{1,2,3,4},{5,6,7,8}};
    CHECK(m.getmatrix()==t2);//4

    vector<vector<double>> t3={{0,0,0,0},{0,0,0,0}};
    Matrix n=(-m);
    CHECK((n+m).getmatrix()==t3);//5
    
    vector<vector<double>> t4={{3,6,9},{12,15,18},{21,24,27}};
    CHECK((3*x1).getmatrix()==t4);//6
    
    x1*=-2;
    vector<vector<double>> t5={{-2,-4,-6},{-8,-10,-12},{-14,-16,-18}};
    CHECK(x1.getmatrix()==t5);//7
    Matrix x4{idn,3,3};
    CHECK((x1*x4).getmatrix()==t);//8 //mult matrix with identity matrix
    Matrix x5(arr3,3,2);
    vector<vector<double>> mult={{22,49,76},{28,64,100}};
    CHECK_EQ((x4*x5).getmatrix(),mult);//9
    Matrix x6{arr5,3,3};
    vector<vector<double>> t6={{2,3,4},{5,6,7},{8,9,10}};
    CHECK((2*x5).getmatrix()==t6);//10
    bool b1=x6>x5;
    CHECK_FALSE(b1);//11
        bool b2=x2>x1;

    CHECK_FALSE(b2);//12
    bool b3=m>x1;
    CHECK_FALSE(b3);//13


    }
    TEST_CASE("Bad input") {//test 11
    Matrix n11(arr1,3,3);
    Matrix n12(arr1,9,1);
    Matrix n21(arr4,9,1);
    Matrix n22(arr4,3,3);
          Matrix n5(arr3,3,2);

    Matrix mn11=(-n11);
    Matrix mn12=(-n12);
    vector<vector<double>> t={{3,6,9},{12,15,18},{21,24,27}};
    CHECK_THROWS(Matrix(arr1,2,2));//illegal zisez//15
    CHECK_THROWS(Matrix(arr1,-9,-1));//ilegal zisez//16
    CHECK_THROWS(n11+n12);//dont same size//17
    CHECK_THROWS(n11*n12);//cols in n11!=rows n12//18
    n11*=-3;
    CHECK_THROWS(Matrix n3(arr3,3,3););//19
    Matrix n6{arr5,3,3};
    CHECK_THROWS(((n6*n5)+n11));//20
    CHECK_THROWS(n5*n11);//21

    

    }


   


