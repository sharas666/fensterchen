#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "point2d.cpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include "window.hpp"


class Circle : public Shape{

	public:
		Circle();
		Circle(double const& rad, Point2d const& m);
		Circle(double const& rad);
		Circle(double const& rad, Point2d const& m, ColorRGB const&);
		~Circle();
		double r() const;
		Point2d mid() const;
		ColorRGB color() const;
		double circumference() const;
		void draw(Window const& k) const /*override*/;
		void draw(Window const& k, ColorRGB color) const /*override*/;
		bool is_inside(Point2d const& p) const /*override*/;
		bool operator<(Circle const&)const;
		bool operator>(Circle const&)const;

	private:
		double m_radius_;
		Point2d m_mid_;
		

};
#endif
