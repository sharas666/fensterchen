#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "circle.cpp"
#include "rectangle.cpp"
#include "draw.cpp"
#include <string>

class Shape{
	public:
		virtual void draw(Window const&) const = 0;
		virtual bool is_inside() const = 0;
		virtual std::ostream& print(std::ostream& os) const;


	protected:
		std::string m_name_;
		ColorRGB m_color_;
};

std::ostream& operator<<(std::ostream& os,Shape const& s)
{
	s.print(os);
}

#endif