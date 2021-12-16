// Praktikum3.cpp 
// Ros 09.11.2021

#include <iostream>
#include <chrono>
#include "Frame.h"
#include "Line.h"
#include "Shape.h"
#include "Triangle.h"
#include "Kreis.h"

int main()try
{
    Frame frm;

    //auto firstStart = std::chrono::high_resolution_clock::now();                                    // high_resolution_clock::time_point

    Line line1 { 20, 5, 5, 30 };                                                         // start_x, start_y, end_x, end_y
    //line1->draw(&frm);
    //frm.show();
    //frm.reset();

    //auto firstEnd = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> firstDiff = firstEnd - firstStart;
    //std::cout << "first - " << firstDiff.count() << '\n';

    //  =============================================================================================================================  //

    //auto secondStart = std::chrono::high_resolution_clock::now();

    Line line2 { 5, 5, 20, 30 };                                                         // start_x, start_y, end_x, end_y
    //line2.draw(&frm);
    //frm.showCoutPut();
    //frm.reset();

    //auto secondEnd = std::chrono::high_resolution_clock::now();
    //std::chrono::duration<double> secondDiff = secondEnd - secondStart;
    //std::cout << "first - " << secondDiff.count() << '\n';
    // std::cout.put() ist schneller auf 15-20%

    //  =============================================================================================================================  //

    Triangle triangle1 { 15, 5, 20, 13, 9 };                                                         // start_x, start_y, len1, len2, len3
    //triangle1.draw(&frm);
    //frm.showCoutPut();
    //frm.reset();

    Kreis kreis{ 20,20,10 };
    //kreis.draw(&frm);
    //frm.show();

    line1.show_all_shapes(&frm);

    return 0;
}
catch (std::exception& e)
{
    std::cerr << e.what();
    return -1;
}
catch (...)
{
    std::cerr << "some wrong";
    return -2;
}