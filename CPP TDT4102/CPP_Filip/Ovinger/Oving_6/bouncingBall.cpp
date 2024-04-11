#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"
#include "config.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};


map<int, TDT4102::Color> colorMap = {
{1, Color::orange},
{2, Color::purple},
{3, Color::green},
{4, Color::teal}};

void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{1};
    int velocity{2};
    Color current_color;
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    int x{100};
    int y{400};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};



    // read from configuration file
    // initialise the run
    Point circlePosition {x, y};
    filesystem::path config_file{"konfigurasjon.txt"};
    ifstream is{config_file};

    Config slow;
    Config fast;
    is >> slow; // slow.color_up = 3, slow.color_down = 2, slow.velocity = 1
    is >> fast;

    velocity = slow.velocity;
    colour_up = colorMap.at(slow.colorUp);
    colour_down = colorMap.at(slow.colorDown);

    current_color = colour_up;
    bool state = true;

    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);
        

        // movement in x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;

            // increment counter which counts number of full left-to-right passes
            count_num_passes++;

            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {

                // change configuration
                // update both velocity and colors
                if(state==true){
                    velocity = fast.velocity;
                    state = !state;
                    colour_down = colorMap.at(fast.colorDown);
                    colour_up = colorMap.at(fast.colorUp);

                }

                else{
                    velocity = slow.velocity;
                    state = !state;
                    colour_down = colorMap.at(slow.colorDown);
                    colour_up = colorMap.at(slow.colorUp);

                }


    
            }


            
        } else {
            // moving rightwards
            x += increment_x;
        }

        
        if ((increment_y + y) > window.height()-30) {
        count_bounce_bottom++;
        current_color = colour_up;
        }

        if ((increment_y + y) < 30) {
        count_bounce_top++;
        current_color = colour_down;
        }



        // movement in y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards
            y -= increment_y;

            
        } else {
            // move downward
            y += increment_y;



        }


        circlePosition.x = x;
        circlePosition.y = y;
        window.draw_circle(circlePosition, radius, current_color);
        window.next_frame();
    }
}

