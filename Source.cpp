//"bloons" style game, part 1
//coded by Dr. Mo, Feb 2022
//dynamicsofanasteroid.com
#include <SFML/Graphics.hpp>
#include <vector>
#include<iostream>
using namespace std;

//discussion questions for students:
//1) How would you *avoid* diagonals in the path? How do you purposely create them?
//2) Why the "-1" in this line: if(currPath < pathPoints.size()-1)? Why is it needed?
//3) What's the difference between a struct and a class? Could we have used a class instead of a struct?


//create a struct: structs are like classes, but no functions (just variables)
struct point {
    int x;
    int y;
};


int main()
{
    //set up path points using the struct we made
    struct point p1;
    p1.x = 250;
    p1.y = 900;
    struct point p2;
    p2.x = 250;
    p2.y = 850;
    struct point p3;
    p3.x = 200;
    p3.y = 850;
    struct point p4;
    p4.x = 150;
    p4.y = 800;
    struct point p5;
    p5.x = 150;
    p5.y = 550;
    struct point p6;
    p6.x = 150;
    p6.y = 700;
    struct point p7;
    p7.x = 100;
    p7.y = 700;
    struct point p8;
    p8.x = 50;
    p8.y = 650;
    struct point p9;
    p9.x = 50;
    p9.y = 350;
    struct point p10;
    p10.x = 100;
    p10.y = 300;
    struct point p11;
    p11.x = 150;
    p11.y = 300;
    struct point p12;
    p12.x = 150;
    p12.y = 450;
    struct point p13;
    p13.x = 150;
    p13.y = 200;
    struct point p14;
    p14.x = 300;
    p14.y = 50;
    struct point p15;
    p15.x = 500;
    p15.y = 50;
    struct point p16;
    p16.x = 600;
    p16.y = 150;
    struct point p17;
    p17.x = 600;
    p17.y = 200;
    struct point p18;
    p18.x = 700;
    p18.y = 300;
    struct point p19;
    p19.x = 700;
    p19.y = 350;
    struct point p20;
    p20.x = 600;
    p20.y = 450;
    struct point p21;
    p21.x = 400;
    p21.y = 450;
    struct point p22;
    p22.x = 300;
    p22.y = 350;
    struct point p23;
    p23.x = 300;
    p23.y = 300;
    struct point p24;
    p24.x = 400;
    p24.y = 200;
    struct point p25;
    p25.x = 600;
    p25.y = 200;
    struct point p26;
    p26.x = 700;
    p26.y = 300;
    struct point p27;
    p27.x = 700;
    p27.y = 350;
    struct point p28;
    p28.x = 600;
    p28.y = 450;
    struct point p29;
    p29.x = 600;
    p29.y = 800;
    struct point p30;
    p30.x = 550;
    p30.y = 850;
    struct point p31;
    p31.x = 450;
    p31.y = 850;
    struct point p32;
    p32.x = 400;
    p32.y = 800;
    struct point p33;
    p33.x = 400;
    p33.y = 750;
    struct point p34;
    p34.x = 350;
    p34.y = 750;
    struct point p35;
    p35.x = 350;
    p35.y = 800;
    struct point p36;
    p36.x = 300;
    p36.y = 850;
    struct point p37;
    p37.x = 250;
    p37.y = 850;
    struct point p38;
    p38.x = 250;
    p38.y = 900;


    //set up vector to hold path points, push path points into it
    vector <point> pathPoints;
    pathPoints.push_back(p1);
    pathPoints.push_back(p2);
    pathPoints.push_back(p3);
    pathPoints.push_back(p4);
    pathPoints.push_back(p5);
    pathPoints.push_back(p6);
    pathPoints.push_back(p7);
    pathPoints.push_back(p8);
    pathPoints.push_back(p9);
    pathPoints.push_back(p10);
    pathPoints.push_back(p11);
    pathPoints.push_back(p12);
    pathPoints.push_back(p13);
    pathPoints.push_back(p14);
    pathPoints.push_back(p15);
    pathPoints.push_back(p16);
    pathPoints.push_back(p17);
    pathPoints.push_back(p18);
    pathPoints.push_back(p19);
    pathPoints.push_back(p20);
    pathPoints.push_back(p21);
    pathPoints.push_back(p22);
    pathPoints.push_back(p23);
    pathPoints.push_back(p24);
    pathPoints.push_back(p25);
    pathPoints.push_back(p26);
    pathPoints.push_back(p27);
    pathPoints.push_back(p28);
    pathPoints.push_back(p29);
    pathPoints.push_back(p30);
    pathPoints.push_back(p31);
    pathPoints.push_back(p32);
    pathPoints.push_back(p33);
    pathPoints.push_back(p34);
    pathPoints.push_back(p35);
    pathPoints.push_back(p36);
    pathPoints.push_back(p37);
    pathPoints.push_back(p38);

    // create game window
    sf::RenderWindow window(sf::VideoMode(780, 900), "Bloons");

    //balloon variables
    float xpos = 250; 
    float ypos = 950; //start off screen
    sf::CircleShape bloon(25);
    bloon.setFillColor(sf::Color(250, 0, 0));
    bloon.setPosition(xpos, ypos);
    int currPath = 0; //begin heading towards the first point in the pathing vector
    int ticker = 0;



    // GAME LOOP----------------------------------------------------------------------------------------
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        //pathing algorithm*******************************************************************
        //this works by moving the x and y coord of our baloon towards the (x,y) of the next point in the path
        //the path is stored as a series of points in a vector called "pathPoints"

        ticker++; //slow dem bloons down
        if (ticker % 30 == 0) { //make 30 bigger to slow down baloon more

            //first check if you're at the turning point, move to next point if you are
            if ((xpos == pathPoints[currPath].x) && (ypos == pathPoints[currPath].y))
                if (currPath < pathPoints.size() - 1) //don't walk off end of vector!
                    currPath++; //iterate to next point

            //if not there yet, move our x towards x position of next junction
            if (xpos < pathPoints[currPath].x)
                xpos += 1;
            if (xpos > pathPoints[currPath].x)
                xpos -= 1;
            //and move our y towards y position of next junction
            if (ypos < pathPoints[currPath].y)
                ypos += 1;
            if (ypos > pathPoints[currPath].y)
                ypos -= 1;
        }//end pathing algorithm**************************************************************


        //move da bloon
        bloon.setPosition(xpos, ypos);

        // Render section----------------------------------------------------------------
        window.clear(sf::Color::Black);
        window.draw(bloon);

        

        window.display();
    }

    return 0;//buh bye
}