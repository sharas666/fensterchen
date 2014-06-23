#include "rectangle.hpp"

Rectangle::Rectangle():
	left_bottom_corner_{0,0},
	angle_{0},
	sidelength_a{1},
	sidelength_b{1},
	color_{0}
{};

Rectangle::Rectangle(Point2d const& left_bottom_corner, double const& angle, double const& side_a, double const& side_b, ColorRGB const& c):
	left_bottom_corner_{left_bottom_corner},
	angle_{angle},
	sidelength_a{side_a},
	sidelength_b{side_b},
	color_{c}
{};

Rectangle::Rectangle(Point2d const& left_bottom_corner, double const& side_a, double const& side_b, ColorRGB const& c):
	left_bottom_corner_{left_bottom_corner},
	angle_{0},
	sidelength_a{side_a},
	sidelength_b{side_b},
	color_{c}
{};

Rectangle::~Rectangle(){};

double Rectangle::a()const{
	return sidelength_a;
}

double Rectangle::b()const{
	return sidelength_b;
}

ColorRGB Rectangle::c()const{
	return color_;
}

Point2d Rectangle::corner()const{
	return left_bottom_corner_;
}

double Rectangle::angle()const{
	return angle_;
}

ColorRGB Rectangle::color()const{
	return color_;
}


bool Rectangle::is_inside(Point2d const& p)const{
	if( (p.x()>=left_bottom_corner_.x())&&
		(p.y()>=left_bottom_corner_.y())&&
		(p.x()<=left_bottom_corner_.x()+sidelength_a)&&
		(p.y()<=left_bottom_corner_.y()+sidelength_b) ){
		return true;
	}else{
		return false;
	}
	
}

double Rectangle::circumference()const{
	return 2*(sidelength_a + sidelength_b);

}