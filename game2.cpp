// This is the 3rd game in the series [Brick Breaker].
// There will be a series of bricks , a ball, and an paddel which is used to bounce off the ball to break the bricks.
// In this game I have used physics and mechnacis for the movement of the paddel and the ball.
// If all the bricks are destroyed, the game is over and you win.
// If the ball hits the bottom of the screen, the game is over.

#include <SFML/Graphics.hpp>  //SFML library for graphics
#include <SFML/Window.hpp>   //SFML library for window
#include <optional>   // For SFML 3.0 event handling 
#include <vector>    // For vectors(arrays) used for bricks in game
using namespace sf;  // For sf namespace
using namespace std; // For std namespace
int main() {
    RenderWindow window(sf::VideoMode({800, 600}), "Brick Breaker"); // Create a window with size 800x600
    
    // Create Ball
    CircleShape ball(7.f);  // Radius 7
    ball.setFillColor(Color::White);  // Give the ball a visible color
    ball.setPosition({400.f, 300.f});  // Braced initializer

    // Create Paddle
    RectangleShape paddle({100.f, 20.f});  // Width 100, Height 20
    paddle.setFillColor(Color::Red);    // Give the paddle a visible color
    paddle.setPosition({350.f, 550.f});  // Braced initializer
    float paddelSpeed = 0.2f;    // Paddle movement speed
    float ballDX = 0.05f, ballDY = 0.05f;   // Ball movement speed
      std::vector<RectangleShape> bricks;  // Vector of bricks(definition)
      RectangleShape brick({60.f, 20.f}); // Width 60, Height 20
       brick.setFillColor(Color::Green); // Give the bricks a visible color
      for (int row = 0; row < 5; row++) { // 5 rows of bricks
          for (int col = 0; col < 10; col++) { // 10 columns of bricks
                  brick.setPosition({col * 70.f + 35.f, row * 30.f + 50.f}); // Spaced apart
                  bricks.push_back(brick);
            }
         }
    while (window.isOpen()) {    // main game loop starts here

        while (auto event = window.pollEvent()) {
            if (event->is<Event::Closed>()) {
                window.close();
            }
        }
             if (Keyboard::isKeyPressed(Keyboard::Key::Left) && paddle.getPosition().x > 0)
                {
                // left key is pressed: move our character
               paddle.move({-paddelSpeed, 0.f});
               }
             if (Keyboard::isKeyPressed(Keyboard::Key::Right) && paddle.getPosition().x + paddle.getSize().x <  window.getSize().x)
                {
                // left key is pressed: move our character
               paddle.move({paddelSpeed, 0.f});
               }
            if (ball.getPosition().x <= 0 || ball.getPosition().x + ball.getRadius() * 2 >= window.getSize().x) {
                  ballDX = -ballDX;  // Reverse X direction
                }
            if (ball.getPosition().y <= 0) {
                   ballDY = -ballDY;  // Reverse Y direction
                }
            if (ball.getPosition().y + ball.getRadius() * 2 >= paddle.getPosition().y &&
                   ball.getPosition().x >= paddle.getPosition().x &&
                   ball.getPosition().x <= paddle.getPosition().x + paddle.getSize().x) {
                   ballDY = -ballDY;  // Bounce off paddle
                }
            if (ball.getPosition().y >= window.getSize().y) {
                   window.close();  // Game over
            }
             // Brick collision
            for (size_t i = 0; i < bricks.size(); ++i) {
               if (bricks[i].getGlobalBounds().contains({ball.getPosition().x + ball.getRadius(), ball.getPosition().y + ball.getRadius()}))
                  {
                bricks.erase(bricks.begin() + i);
                ballDY = -ballDY;
                break;
               }
            }


        ball.move({ballDX, ballDY});
        window.clear(Color::Black);  // Set background color
       for (auto& brick : bricks) {
    window.draw(brick);
}

        window.draw(ball);
        window.draw(paddle);
        window.display();
    }

    return 0;
}
