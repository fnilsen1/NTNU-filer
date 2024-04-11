#include "AnimationWindow.h"
#include "Emoji.h"
#include "animal.h"

constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;


int main()
{

	const Point tl{100, 100};
	const Point tl1{250, 100};
	const Point tl2{400, 100};
	const Point tl3{550, 100};
	const Point tl4{700, 100};
	const string win_label{"Emoji factory"};
	AnimationWindow win{tl.x, tl.y, xmax, ymax, win_label};
	
	EmptyFace d{tl, emojiRadius};
	d.draw(win);
	SmilyFace e{tl1, emojiRadius};
	e.draw(win);
	SadFace f{tl2, emojiRadius};
	f.draw(win);
	WinkyFace g{tl3, emojiRadius};
	g.draw(win);
	WeirdFace h{tl4, emojiRadius};
	h.draw(win);
	win.wait_for_close();

	//testAnimal();
    return 0;
}