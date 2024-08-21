typedef complex<double> point; 
#define x real() 
#define y imag() 
#define PI 3.1415926535897932384626 

// counter clockwise rotationpoint rotate(point P, point Q, double theta) 
{ 
    return (P-Q) * polar(1.0, theta) + Q; 
} 
 


/*-----------------------------------------------------------------------------*/
int main()
{
    // files();
    needForSpeed
    ld X,Y,D;
    cin >> X >> Y >> D;
    // first point
    point P(X,Y);
    // second point
    point Q(0.0,0.0);
    double theta=D*(PI/180.0);

    point rotated_P=rotate(P,Q,theta);
    cout.precision(15);
    cout << fixed << rotated_P.x << " " << rotated_P.y << endl;
    return 0;
}