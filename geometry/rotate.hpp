Point rotate(Point O, Point P, Real radian){;
    Point Q = P - O; 
    Real X = real(Q) * cos(radian) - imag(Q) * sin(radian);
    Real Y = real(Q) * sin(radian) + imag(Q) * cos(radian);
    return Point(X, Y) + O;
}