#include "MinesweeperWindow.h"
#include "std_lib_facilities.h"

int main()
{
	// constexpr int width = 10;
	// constexpr int height = 10;
	// constexpr int mines = 3;

	// Point startPoint{ 200, 300 };
	// MinesweeperWindow mw{startPoint.x, startPoint.y, width, height, mines, "Minesweeper" };
	// mw.wait_for_close();
    cout << "Skriv inn et tall: " << endl;
    int a = 0;

    try{
        // cin >> a;
        // cout << 0/0 << endl;
 
        throw 13;
        

    }

    catch(...){
        cout << "Dayum";
    }

	return 0;
}
 