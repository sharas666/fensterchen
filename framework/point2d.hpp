#ifndef POINT2D_HPP
#define POINT2D_HPP


class Point2d{
	public:
		Point2d();
		Point2d(double const& x_value, double const& y_value);
		~Point2d();
		double x() const;
		double y() const;
		void translate(double const& x_new, double const& y_new);
		void rotate(Point2d const&, double const&);
		void rotate(double const&);
	private:
		double xcoord_;
		double ycoord_;

};

struct ColorRGB{
	ColorRGB(int r, int g, int b) : r{r}, g{g}, b{b}{}
	ColorRGB(int c) : r{c}, g{c}, b{c}{}
	int r,g,b;
};
#endif


