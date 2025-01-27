    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <chrono>
    #include <vector>    
    #include <fstream>
    #include "FindWavFile.h"
    #include <filesystem>


    int main()
{
/// vector For SoundBuffer's


    std::filesystem::path  p("C:\\Program Files\\ReaDrum\\Sounds");

    std::vector<std::string> WVL = FindWavFile(p);
    
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    
    /// For windows
    sf::RenderWindow window(sf::VideoMode(800, 600), "ReaDeum", sf::Style::None);
    

  
/// sf::Music Sou2 ("C:\\Program Files\\ReaDrum\\Sounds\\h.ogg");

    
    /// For Mouse
    sf::Vector2i mouseStartPosition;

    /// For Opening Image
    sf::Image Opimage;
    if (!Opimage.loadFromFile("C:\\Program Files\\ReaDrum\\ReaDrum.png")) 
    {
        return 1;
    }

    sf::Texture Optexture;
    if (!Optexture.loadFromImage(Opimage)) 
    {
        return 1;
    }
    sf::Sprite Opsprite;
    Opsprite.setTexture(Optexture);
    Opsprite.setPosition(0, 0);

    /// LOADING soundFile'S From C | ProgramFile | ReaDrum | Sounds ;
    
    
    
    
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
                if (event.key.code == sf::Keyboard::Num0 || event.key.code == sf::Keyboard::Numpad0)
                {
                    ///std::cout << "K" << std::endl;
                    
///                 sou0.play();
                }
                else if (event.key.code == sf::Keyboard::Num1 || event.key.code == sf::Keyboard::Numpad1)
                {
                    ///std::cout << "S" << std::endl;
///                 Sou1.play();
                }
                else if (event.key.code == sf::Keyboard::Num2 || event.key.code == sf::Keyboard::Numpad2)
                {
                    ///std::cout << "H" << std::endl;
///                 Sou2.play();
               }
            }
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
        {
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