#include <iostream>

using std::cout; 
using std::endl;


namespace Geometry {

    /*
    Example of a geometry primative you might encounter,
    in robotics or a video game engine
    */
    class Point3d {
        public:
        constexpr Point3d(double x, double y, double z)
         : m_x(x), m_y(y), m_z(z) {}

        constexpr bool operator==(const Point3d& other) const {
            return 
            m_x == other.m_x && 
            m_y == other.m_y &&
            m_z == other.m_z;
        }

        constexpr Point3d operator+(const Point3d& other) {
            return Point3d(
                m_x + other.m_x,
                m_y + other.m_y,
                m_z + other.m_z
            );
        }

        constexpr Point3d& operator+=(const Point3d& other) {
            m_x += other.m_x;
            m_y += other.m_y;
            m_z += other.m_z;
            return *this;            
        }

        // We declare the stream insertion operator a "friend" function.
        // It's external to the class, but allowed to access its private members
        friend std::ostream& operator<<(std::ostream& out, const Point3d& pt);

        private:
        double m_x;
        double m_y;
        double m_z;

    }; // class Point3d

    // Outside of the class, we define the stream insertion operator for Point3d,
    // allowing us to use cout on it
    std::ostream& operator<<(std::ostream& out, const Point3d& pt) {
        out <<"Point3d (x=" << pt.m_x << ", y=" << pt.m_y << ", z=" << pt.m_z << ")";
        return out;
    }
}

int main(int argc, char** argv) 
{
    using Geometry::Point3d;

    // To tie together some of the previous lessons
    // and demonstrate operator overloading,
    // here's some usage of our custom class
    // that will evaluate at compile time

    constexpr Point3d a (3.5, 4.6, 9.17);
    constexpr Point3d b  = Point3d{12.4, 5.7, 7.5} + a;
    constexpr Point3d c (3.5, 4.6, 9.17);
    constexpr bool these_points_are_the_same{a == c};
    constexpr Point3d d = Point3d(1.8, 91.5, 9814.07) += c;

    cout << a << endl;
    cout << b << endl;
    cout << "These points are the same: "<<these_points_are_the_same<<endl;
    cout << d << endl;
    return 0;
}