#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#define _USE_MATH_DEFINES
#include <cmath>
#include "window.hpp"
#include "point2d.hpp"

class Rectangle{

	public:
		Rectangle();
		Rectangle(Point2d const& left_bottom_corner, double const& angle, double const& side_a, double const& side_b, ColorRGB const& c);
		Rectangle(Point2d const& left_bottom_corner, double const& side_a, double const& side_b, ColorRGB const& c);
		~Rectangle();
		double a() const;
		double b() const;
		ColorRGB c() const;
		Point2d corner() const;
		double angle() const;
		ColorRGB color() const;
		double circumference() const;
		void draw(Window const&) const;
		void draw(Window const&, ColorRGB) const;
		bool is_inside(Point2d const& p) const;

	private:
		Point2d left_bottom_corner_;
		double angle_;
		double sidelength_a;
		double sidelength_b;
		ColorRGB color_;

};
#endif
