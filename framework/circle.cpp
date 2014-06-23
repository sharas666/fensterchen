#include "circle.hpp"


Circle::Circle():
	Shape{"standard_constructed_circle",{0,0,0}},
	m_radius_{1},
	m_mid_{0.0,0.0}
	
{}

Circle::Circle(double const& rad, Point2d const& m, std::string name):
	Shape{name},
	m_radius_{rad},
	m_mid_{m}
	
{}

Circle::Circle(double const& rad, std::string name):
	Shape{name},
	m_radius_{rad},
	m_mid_{0.0,0.0}
	
{}

Circle::Circle(double const& rad, Point2d const& m, ColorRGB const& c, std::string name):
	Shape{name,c},
	m_radius_{rad},
	m_mid_{m}
	
{}
Circle::~Circle(){};

double Circle::r() const{
	return Circle::m_radius_;
}

Point2d Circle::mid() const{
	return Circle::m_mid_;
}

ColorRGB Circle::color() const{
	return m_color_;
}

double Circle::circumference() const{
	return 2*M_PI*m_radius_;
}

bool Circle::is_inside(Point2d const& p) const /*override*/{
	if(sqrt(pow(p.x()-m_mid_.x(),2)+pow(p.y()-m_mid_.y(),2))<=m_radius_){
		return true;
	}else{
		return false;
	}


}

bool Circle::operator<(Circle const& rhs)const{
	return (m_radius_ < rhs.m_radius_);

}

bool Circle::operator>(Circle const& rhs)const{
	return (m_radius_ > rhs.m_radius_);

}
