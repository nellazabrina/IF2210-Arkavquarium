#include "LinkedList.h"
#include "Siput.h"
#include "Lib/oop.hpp"
#include <iostream>
using namespace std;

Siput::Siput() {
    distance_to_coin = 0;
    set_speed(SIPUT_MOVEMENT_SPD);
    set_dir("Right");
}

int Siput::get_speed() {
    return speed;
}

void Siput::set_speed(int x) {
    speed = x;
}

void Siput::draw() {

    Moveable::set_x(0);
    Moveable::set_y(0);

    // draw siput on screen
    if (Moveable::get_dir() == "Left"){
        draw_image(FILE_siput_left, get_x(), get_y());
    } else {
        draw_image(FILE_siput_right, get_x(), get_y());
    }
}

void Siput::move(double sec_since_last, LinkedList<Coin>& C) {

    if (get_y() == SCREEN_BOTTOM && inRadius(C) != -999) {

        // get the x value of nearest coin
        int idx = inRadius(C);

        // set siput x , to
        double a = atan2(C.get(idx).get_x() - get_x(), C.get(idx).get_y() - get_y());
        set_x(get_x()+ get_speed() * cos(a) * sec_since_last);

    }
}

double Siput::euclidean(Coin c) {
    // get euclidean distance to coin

    double x_siput = get_x();
    double y_siput = get_y();
    double x_coin = c.get_x();
    double y_coin = c.get_y();

    return (sqrt(pow(x_siput-x_coin, 2)) + (pow(y_siput-y_coin, 2)));
}

int Siput::inRadius(LinkedList<Coin>& C) {

    int idx = 1;
    double radius = 1;
    bool find = false;
    while (!find && idx < C.getNBelmt()) {

        if (radius > euclidean(C.get(idx))) {
            find = true;
        } else {
            idx++;
        }
    }

    if (find) {
        return idx;
    } else {
        return -999;
    }
}

int Siput::find_coin(LinkedList<Coin>& C) {
  
    int x = Moveable::get_x();
    int y = Moveable::get_y();
    
    int idx = 1;
    int i = 2;
    
    while (i < C.getNBelmt()) {
        if (euclidean(C.get(idx)) > euclidean(C.get(i))) {
            idx = i;
        } else {
            i++;
        }
    }
    return idx;
}

bool Siput::take_coin(LinkedList<Coin>& C) {

    int idx = inRadius(C);

    if (idx != -999) {
        C.remove(C.get(idx));
        return true;
    } else {
        return false;
    }
}