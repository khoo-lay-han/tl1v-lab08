#include <iostream>

class Geometry
{
public:
    // Question 1
    Geometry(float hg, float rd, float lg)
        : pi(3.142), height(hg), radius(rd), length(lg)
    {}

    // Question 2
    ~Geometry() { std::cout << "\n= END OF PROGRAM =\n"; }

    // Question 3
    friend class Cylinder;

    // Question 4
    friend class Cone;

    friend class Cube; // Part B
    
private:
    float pi;
    float height;
    float radius;
    float length; // Part B
};

class Cylinder
{
public:
    // Question 5
    void calc_vol(const Geometry* g) 
    { 
        vol = g->pi * g->radius*g->radius * g->height; 
        std::cout << "\nVolume of cylinder with radius " 
            << g->radius << " and height " << g->height
            << " is: " << vol << "\n";
    }

private: 
    float vol;
};

class Cone
{
public:
    // Question 6
    void calc_vol(const Geometry& g) 
    { 
        vol = (g.pi * g.radius*g.radius * g.height) / 3;
        std::cout << "\nVolume of cone with radius " 
            << g.radius << " and height " << g.height
            << " is: " << vol << "\n"; 
    }

private:
    float vol;
};

// Part B Question 2
class Cube
{
public:
    
    void calc_vol(const Geometry& g) 
    { 
        vol = g.length * g.length * g.length; 
        std::cout << "\nVolume of cube with length " 
            << g.length << " is: " << vol << "\n";
    }

private:
    float vol;
};

int main()
{
    float hg, rd, lg;

    std::cout << "Enter height : ";
    std::cin >> hg;
    std::cout << "Enter radius : ";
    std::cin >> rd;
    std::cout << "Enter length : ";
    std::cin >> lg;
    
    // Question 7
    Geometry gmt(hg, rd, lg);

    // Question 8 
    Cylinder cyc;

    // Question 9
    cyc.calc_vol(&gmt);

    // Question 10
    Cone cn;

    // Question 11
    cn.calc_vol(gmt);

    // Part B
    Cube cb;
    cb.calc_vol(gmt);
}
