#include "circle.hpp"


Circle::Circle():
	radius_{1},
	mid_{0.0,0.0},
	color_{0}
{};

Circle::Circle(double const& rad, Point2d const& m):
	radius_{rad},
	mid_{m},
	color_{0}
{};

Circle::Circle(double const& rad):
	radius_{rad},
	mid_{0.0,0.0},
	color_{0}
{};

Circle::Circle(double const& rad, Point2d const& m, ColorRGB const& c):
	radius_{rad},
	mid_{m},
	color_{c}
{};
Circle::~Circle(){};

double Circle::r() const{
	return Circle::radius_;
}

Point2d Circle::mid() const{
	return Circle::mid_;
}

ColorRGB Circle::color() const{
	return color_;
}

double Circle::circumference() const{
	return 2*M_PI*radius_;
}

bool Circle::is_inside(Point2d const& p) const{
	if(sqrt(pow(p.x()-mid_.x(),2)+pow(p.y()-mid_.y(),2))<=radius_){
		return true;
	}else{
		return false;
	}


}

bool Circle::operator<(Circle const& rhs)const{
	// radius_ *= 3.0;
	return (radius_ < rhs.radius_);

}

bool Circle::operator>(Circle const& rhs)const{
	return (radius_ > rhs.radius_);

}
