#include "Emoji.h"
#include "AnimationWindow.h"

Face::Face(Point c, int r) : centre{c}, radius{r} {};

void Face::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius, Color::yellow);
    win.draw_arc(centre, (radius), (radius),0, 360, Color::black);
}


EmptyFace::EmptyFace(Point c, int r) : Face{c, r} {};

void EmptyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(Point{centre.x - radius/4, centre.y - radius/10}, radius/10, Color::red);
    win.draw_circle(Point{centre.x + radius/4, centre.y - radius/10}, radius/10, Color::green);
}

SmilyFace::SmilyFace(Point c, int r) : EmptyFace{c,r} {};

void SmilyFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{centre.x, centre.y-30}, 70 , 60 , 240, 300, Color::black);
}

SadFace::SadFace(Point c, int r) : EmptyFace{c,r} {};

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(Point{centre.x, centre.y+70}, 70 , 60 , 60, 120, Color::black);
}

WinkyFace::WinkyFace(Point c, int r) : Face{c,r} {};

void WinkyFace::draw(AnimationWindow& win) {
    Face::draw(win);
    win.draw_circle(Point{centre.x - radius/4, centre.y - radius/10}, radius/10, Color::red);
    win.draw_arc(Point{centre.x + radius/4, centre.y + radius/10+5}, 20, 20, 50, 130, Color::black);
    win.draw_arc(Point{centre.x, centre.y-30}, 70 , 60 , 240, 300, Color::black);
}

WeirdFace::WeirdFace(Point c, int r) : EmptyFace{c,r} {};

void WeirdFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    // win.draw_arc(Point{centre.x - radius/4, centre.y - radius/9}, 25, 25, 45, 100, Color::black);
    // win.draw_line(Point{centre.x + radius/4, centre.y - radius/3}, Point{centre.x, centre.y - radius/7}, Color::black);
    win.draw_circle(Point{centre.x, centre.y + radius/2}, radius/3, Color::black);

}