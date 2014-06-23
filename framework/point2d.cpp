#include "point2d.hpp"
#define _USE_MATH_DEFINES
#include <cmath>


Point2d::Point2d():
	ycoord_{0},
	xcoord_{0}
{};

Point2d::Point2d(double const& x_value, double const& y_value):

	xcoord_{x_value},
	ycoord_{y_value}
{};

Point2d::~Point2d(){

};

double Point2d::x() const {
	return xcoord_;
}


double Point2d::y() const {
	return ycoord_;
}

void Point2d::translate(double const& x_new, double const& y_new){
	xcoord_=x_new;
	ycoord_=y_new;
}

void Point2d::rotate(Point2d const& ursprung, double const& bm){
	double temp_xcoord_ = (xcoord_ - ursprung.x()) * cos(bm) + (ycoord_ - ursprung.y()) * sin(bm) + ursprung.x();
	double temp_ycoord_ = (ycoord_ - ursprung.y()) * cos(bm) - (xcoord_ - ursprung.x()) * sin(bm) + ursprung.y();
	xcoord_ = temp_xcoord_;
	ycoord_ = temp_ycoord_;
}

void Point2d::rotate(double const& bm){
	double temp_xcoord_ = (xcoord_) * cos(bm) + (ycoord_) * sin(bm);
	double temp_ycoord_ = (ycoord_) * cos(bm) - (xcoord_) * sin(bm);
	xcoord_ = temp_xcoord_;
	ycoord_ = temp_ycoord_;
}