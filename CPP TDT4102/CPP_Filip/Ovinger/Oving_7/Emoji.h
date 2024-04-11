#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
public:
    virtual void draw(AnimationWindow&) = 0;
    virtual ~Emoji(){}; //destruktør
};

class Face : public Emoji
{
protected:
Point centre;
int radius;
public:
    Face(Point c, int r);
    void virtual draw(AnimationWindow& win) override = 0;
    virtual ~Face(){};
};

class EmptyFace : public Face
{
protected:
public:
    EmptyFace(Point c, int r);

    void draw(AnimationWindow& win);
};

class SmilyFace : public EmptyFace
{
public:
    SmilyFace();
    SmilyFace(Point c, int r);

    void draw(AnimationWindow& win) override;
};

class SadFace : public EmptyFace
{
public:
    SadFace();
    SadFace(Point c, int r);

    void draw(AnimationWindow& win) override;
};

class WinkyFace : public Face
{
public:
    WinkyFace();
    WinkyFace(Point c, int r);

    void draw(AnimationWindow& win) override;
};

class WeirdFace : public EmptyFace
{
public:
    WeirdFace();
    WeirdFace(Point c, int r);

    void draw(AnimationWindow& win) override;
};