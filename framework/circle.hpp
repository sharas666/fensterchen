#ifndef CIRCLE_HPP
#define CIRCLE_HPP




#include "shape.hpp"


class Circle : public Shape{

	public:
		Circle();
		Circle(double const rad, Point2d const& m, std::string name);
		Circle(double const rad, std::string name);
		Circle(double const rad, Point2d const& m, ColorRGB const&, std::string name);
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
		std::ostream& print(std::ostream& os) const /*override*/;

	private:
		double m_radius_;
		Point2d m_mid_;
		

};
#endif
