#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include "point2d.hpp"
#include "window.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>


class Shape{
	public:
		Shape();
		Shape(std::string const& name, ColorRGB c);
		virtual ~Shape();
		virtual void draw(Window const& w) const = 0;
		virtual void draw(Window const& w, ColorRGB color) const = 0;
		virtual bool is_inside(Point2d const& p) const = 0;
		virtual std::ostream& print(std::ostream& os) const;


	protected:
		std::string m_name_;
		ColorRGB m_color_;
};

std::ostream& operator<<(std::ostream& os,Shape const& s);


#endif