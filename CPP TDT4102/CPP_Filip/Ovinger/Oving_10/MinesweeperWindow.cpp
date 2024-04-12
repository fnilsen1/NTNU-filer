#include "MinesweeperWindow.h"
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize+200, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
    cout << width * cellSize<< " " << (height + 1) * cellSize+200 << endl;
    //300 bredde 530 høyde

	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	// Legg til miner paa tilfeldige posisjoner

    for(int i = 0; i < mines; i++){
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(0, tiles.size()-1);
    int random_index = distribution(generator);
    cout << random_index << endl;
    if(tiles.at(random_index)->getIsMine() == false){
        tiles.at(random_index)->setIsMine(true);
    }

    else{
        i--;
    }

    }

    add(textField);
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
if(at(xy)->getState() != Cell::closed){
return;
};
cellsClicked++;
// if(at(xy)->getState() == Cell::closed){
// at(xy)->open();
// };

at(xy)->open();

if(at(xy)->getIsMine() == false){
int mineCount = countMines(adjacentPoints(xy));

if(mineCount > 0){
at(xy)->setAdjMines(mineCount);

}
else{
for(auto el : adjacentPoints(xy)){
openTile(el);
};


}

}
else{
textField.setText("Game over");
}



}

void MinesweeperWindow::flagTile(Point xy) {
if(at(xy)->getState() == Cell::closed || at(xy)->getState() == Cell::flagged){
at(xy)->flag();
};

}

int MinesweeperWindow::countMines(vector<Point> points){
int counter = 0;
for(auto el: points){
if(at(el)->getIsMine() == true){
counter++;
}

};

return counter;

};

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
        if(cellsClicked==width*height-mines){
            textField.setText("You won!");
        }

	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}
