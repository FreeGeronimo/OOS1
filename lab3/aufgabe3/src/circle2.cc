#include "circle2.hh"

#include <iostream>
#include <sstream>

using namespace std;

Circle::Circle(const Point &c, double r) : centre(c), radius(r)
{
}

Circle::Circle(const char* c)
{
    stringstream buf(c);
    buf >> *this;
}

Circle::Circle(const string &str)
{
    stringstream buf(str);
    buf >> *this;
}

double Circle::GetRadius() const
{
    return radius;
}

const Point &Circle::GetCentre() const
{
    return centre;
}

void Circle::SetRadius(double radius)
{
    this->radius = radius;
}

void Circle::SetCentre(const Point &centre)
{
    this->centre = centre;
}

void Circle::Move(double dx, double dy)
{
    centre.Move(dx, dy);
}

void Circle::Print(bool lf) const
{
    cout << ToString();
    if (lf)
        cout << endl;
}

string Circle::ToString() const
{
    stringstream buf;
    buf << "<";
    buf << centre.ToString();
    buf << ", " << radius << ">";
    return buf.str();
}

istream &operator>>(istream &is, Circle &c)
{
    /* <(9.1, 12.1), 1.2> */
    bool started = false;
    bool done = false;
    while (!is.eof() && !done)
    {
        switch (is.get())
        {
            case '<':
                if (!started)
                {
                    is >> c.centre;
                }
                started = true;
                break;
            case ',':
                if (started)
                {
                    is >> c.radius;
                }
                break;
            case '>':
                done = true;
                break;
            default:
                /* ignore */
                break;
        }
    }
    return is;
}
