#include "circle.hpp"


Circle::Circle():
	Shape{"standard_constructed_circle",{0,0,0}},
	m_radius_{1},
	m_mid_{0.0,0.0}
	
{
	std::cout << "Kreis " << m_name_ << " konstruiert." << std::endl;
}

Circle::Circle(double const rad, Point2d const& m, std::string const& name):
	Shape{name,{0,0,0}},
	m_radius_{rad},
	m_mid_{m}
	
{
	std::cout << "Kreis " << m_name_ << " konstruiert." << std::endl;
}

Circle::Circle(double const rad, std::string const& name):
	Shape{name,{0,0,0}},
	m_radius_{rad},
	m_mid_{0.0,0.0}
	
{
	std::cout << "Kreis " << m_name_ << " konstruiert." << std::endl;
}

Circle::Circle(double const rad, Point2d const& m, ColorRGB const& c, std::string const& name):
	Shape{name,c},
	m_radius_{rad},
	m_mid_{m}
	
{
	std::cout << "Kreis " << m_name_ << " konstruiert." << std::endl;
}
Circle::~Circle(){
	std::cout << "Kreis " << m_name_ << " zerstört." << std::endl;
};

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

void Circle::draw(Window const& window) const{
    Point2d start_point{m_mid_.x() + m_radius_, m_mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(m_mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),m_color_.r,m_color_.g,m_color_.b);
        start_point.rotate(m_mid_, bow*M_PI);
    }

 
}
void Circle::draw(Window const& window, ColorRGB color) const{
    Point2d start_point{m_mid_.x() + m_radius_, m_mid_.y()};
    Point2d end_point{start_point};
  
       

    for (int j = 1; j<201; ++j){
        double bow = 0.01;
        end_point.rotate(m_mid_, bow*M_PI);
        window.drawLine(start_point.x(), start_point.y(), end_point.x(), end_point.y(),color.r,color.g,color.b);
        start_point.rotate(m_mid_, bow*M_PI);
    }
}

std::ostream& Circle::print(std::ostream& os) const{
	Shape::print(os);
	std::cout << "Radius: " << m_radius_ << std::endl;
	std::cout << "Mittelpunkt: x = " << m_mid_.x() << "y = " << m_mid_.y() << std::endl;
	return os;
}


bool Circle::operator<(Circle const& rhs)const{
	return (m_radius_ < rhs.m_radius_);

}

bool Circle::operator>(Circle const& rhs)const{
	return (m_radius_ > rhs.m_radius_);

}

bool Circle::is_leave() const{
	return true;
}