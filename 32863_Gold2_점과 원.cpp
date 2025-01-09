#include <iostream>

using namespace std;

double point[4][2];
double c_x=0, c_y=0, c_r;

void Solve_CircleCenter() {
    //기울기, y절편
    double lines[2][2];

    //두 직선의 방정식 구하기
    for (int i = 0; i < 2; i++) {
        double p1_x = point[i][0], p1_y = point[i][1];
        double p2_x = point[i+1][0], p2_y = point[i+1][1];
        
        double mid_x = (p1_x+p2_x)/2;
        double mid_y= (p1_y+p2_y)/2;
        
        lines[i][0] = (p1_y-p2_y)/(p1_x-p2_x);
        lines[i][1] = mid_y - (lines[i][0]*mid_x);
    }

    cout << lines[0][0] << lines[0][1] << lines[1][0] << lines[1][1];
    //교점 구하기 y = ax + b, y = cx + d, ax-cx = d-b, x = (d-b)/(a-c)
    double a = lines[0][0], b = lines[0][1], c = lines[1][0], d = lines[1][1];
    if (a == c)
    c_x = (d-b)/(a-c);
    c_y = a*c_x + b;

}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> point[i][0] >> point[i][1];
    }
    Solve_CircleCenter();
    cout << c_x << " " << c_y;

}