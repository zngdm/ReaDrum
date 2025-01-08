    #include <SFML/Graphics.hpp>
    #include <iostream>
    #include <SFML/Audio.hpp>
    #include <chrono>
    


    int main()
{


    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    /// For windows
    sf::RenderWindow window(sf::VideoMode(800, 600), "ReaDeum", sf::Style::None);
    sf::SoundBuffer buffer1;
    sf::SoundBuffer buffer2;
    sf::SoundBuffer buffer3;
    /// For Sound's
        /// K
    if (!buffer1.loadFromFile("k.ogg"))
    {
        return 1;
    }
    sf::Sound soundK;
    soundK.setBuffer(buffer1);
        /// S
    if (!buffer2.loadFromFile("s.ogg"))
    {
        return 1;
    }
    sf::Sound soundS;
    soundS.setBuffer(buffer2);
        /// H
    if (!buffer3.loadFromFile("h.ogg"))
    {
        return 1;
    }
    sf::Sound soundH;
    soundH.setBuffer(buffer3);
    
    /// For Mouse
    sf::Vector2i mouseStartPosition;

    /// For Opening Image
    sf::Image Opimage;
    if (!Opimage.loadFromFile("ReaDrum.png")) {
        return 1;
    }

    sf::Texture Optexture;
    if (!Optexture.loadFromImage(Opimage)) {
        return 1;
    }
    sf::Sprite Opsprite;
    Opsprite.setTexture(Optexture);
    Opsprite.setPosition(0, 0);

    ///
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right)
            {
                mouseStartPosition = sf::Mouse::getPosition(window);
            }
 ///        KEYBOARD EVENT's           
            else if (event.type == sf::Event::KeyPressed) 
            {
                if (event.key.code == sf::Keyboard::K) 
                {
                    ///std::cout << "K" << std::endl;
                    soundK.play();
                }
                else if (event.key.code == sf::Keyboard::S)
                {
                    ///std::cout << "S" << std::endl;
                    soundS  .play();
                }
                else if (event.key.code == sf::Keyboard::H)
                {
                    ///std::cout << "H" << std::endl;
                    soundH.play();
                }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
            // Calculate the window's new position based on mouse movement
            sf::Vector2i currentMousePosition = sf::Mouse::getPosition(window);
            window.setPosition(window.getPosition() + (currentMousePosition - mouseStartPosition));
        }


        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();
        
        window.clear(sf::Color::Black);
        
        if (duration <= 5) {
            window.draw(Opsprite);
        }
        window.display();
    }

    return 0;
}