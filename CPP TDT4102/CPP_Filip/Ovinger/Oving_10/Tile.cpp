#include "Tile.h"
#include "std_lib_facilities.h"

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{

if(state == Cell::closed){
setButtonColor(TDT4102::Color::white);
state = Cell::open;

if(isMine == true){
set_label("X");
set_label_color(TDT4102::Color::red);

};

}

}

void Tile::flag()
{
if(state == Cell::flagged){
state = Cell::closed;
set_label("");
}

else if(state == Cell::closed){
state = Cell::flagged;
set_label(cellToSymbol.at(state));
set_label_color(TDT4102::Color::black);

}
}


bool Tile::getIsMine(){
return isMine;
};

void Tile::setIsMine(bool state){
isMine = state;
};

void Tile::setAdjMines(int n){
set_label(to_string(n));
set_label_color(minesToColor.at(n));

};