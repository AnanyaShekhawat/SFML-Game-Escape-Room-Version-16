#include <string>
#include <iostream> 
#include "SFML-2.5.1/include/SFML/Graphics.hpp"
#include "SFML-2.5.1/include/SFML/Window.hpp"
#include "SFML-2.5.1/include/SFML/Audio.hpp"
using namespace std;

sf::Texture parkinglot;
sf::Sprite backgroundImage;
  
sf::Texture home;
sf::Texture nwing;
sf::Texture gym;
sf::Texture office;
sf::Texture bookroom;
sf::Texture library;
sf::Texture btq;

sf::Texture locker;
sf::Texture insideLocker;
sf::Texture keypad;
sf::Texture idCard;
sf::Texture schedule;
sf::Texture libraryCheckout;
sf::Texture getBooks;
sf::Texture isbnclue;
sf::Texture btqfinalclue;

sf::Texture exitButton;
sf::Sprite exitButtonImage;

sf::Texture button; 

sf::Texture parkinglotButton;
sf::Sprite parkinglotButtonImage;
sf::Texture nwingButton;
sf::Sprite nwingButtonImage;
sf::Texture gymButton;
sf::Sprite gymButtonImage;
sf::Texture idButton;
sf::Sprite idButtonImage;
sf::Texture officeButton;
sf::Sprite officeButtonImage;
sf::Texture bookroomButton;
sf::Sprite bookroomButtonImage;
sf::Texture libraryButton;
sf::Sprite libraryButtonImage;
sf::Texture btqButton;
sf::Sprite btqButtonImage;

bool ifOnHome = false;

sf::RenderWindow window(sf::VideoMode(950.0f, 476.0f), "Escape the School", sf::Style::Default);

void gymPuzzle(sf::Event Event)
{
  int input;
  cout << "Please type the password to get inside the gym." << endl;
  int tries = 0;
  while (true){
    cin >> input;
    if (input == 423)
    {  
      cout << "Correct! Click on \"Checkout\" to get your ID card!" << endl;
      window.clear();
      backgroundImage.setTexture(gym);
      window.draw(idButtonImage); 
      window.draw(backgroundImage);
      window.display();
      break;
    }
    else if (tries == 5)
    {
      cout << "HINT: Look at the cars in the parking lot." << endl;
    }
    else if (tries == 10)
    {
      cout << "HINT: Look at the colors of the letters in GYM." << endl;
    }
    else
    {
      cout << "Please try again." << endl;
    }
    tries++;
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    if (exitButtonImage.getGlobalBounds().contains(mousePosF))
    {
      window.clear();
      backgroundImage.setTexture(home);
      ifOnHome = true; 
      window.draw(backgroundImage);
      window.display(); 
    }
  }
  switch (Event.type)
  {
    case sf::Event::Closed:
      window.close();
    break;
    case sf::Event::MouseMoved:
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
    }  
    break;
    case sf::Event::MouseButtonPressed:
    {
      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
      sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
      if (idButtonImage.getGlobalBounds().contains(mousePosF))
      {
        window.clear();
        backgroundImage.setTexture(idCard);
        window.draw(backgroundImage);
        window.display(); 
      }
      else if (exitButtonImage.getGlobalBounds().contains(mousePosF))
      {
        window.clear();
        backgroundImage.setTexture(home);
        ifOnHome = true; 
        window.draw(backgroundImage);
        window.display(); 
      }
    }
    break;
  }
}

int main()
{
  parkinglot.loadFromFile("parkinglotnew.jpg");
  nwing.loadFromFile( "nwing.jpg" );
  home.loadFromFile("home.jpg"); 
  gym.loadFromFile( "gym.jpg" );
  office.loadFromFile( "office.jpg" );
  bookroom.loadFromFile( "bookroom.jpg" );
  library.loadFromFile( "library.jpg" );
  btq.loadFromFile( "btq.jpg" );
  
  locker.loadFromFile( "locker.jpg" );
  insideLocker.loadFromFile( "insidelocker.jpg" );
  keypad.loadFromFile( "gymkeypad.jpg" );
  idCard.loadFromFile("idcard.jpg"); 
  schedule.loadFromFile( "scheduletemp.jpg" );
  libraryCheckout.loadFromFile( "librarycheckout.jpg");
  getBooks.loadFromFile( "getbooks.jpg" );
  isbnclue.loadFromFile( "isbnclue.jpg" );
  btqfinalclue.loadFromFile( "btqfinalclue.jpg" );
  
  backgroundImage.setTexture(home);

  sf::Font font;
  font.loadFromFile("OpenSans-Light.ttf");

  exitButton.loadFromFile("homesmall.PNG");
  exitButtonImage.setPosition(775.0f, 40.0f);
  exitButtonImage.setTexture(exitButton);

  parkinglotButton.loadFromFile("homesmall.PNG");
  parkinglotButtonImage.setPosition(130.0f, 10.0f);
  parkinglotButtonImage.setTexture(parkinglotButton);

  nwingButton.loadFromFile("homesmall.PNG");
  nwingButtonImage.setPosition(175.0f, 300.0f);
  nwingButtonImage.setTexture(nwingButton);

  gymButton.loadFromFile("homesmall.PNG");
  gymButtonImage.setPosition(330.0f, 150.0f);
  gymButtonImage.setTexture(gymButton);

  officeButton.loadFromFile("homesmall.PNG");
  officeButtonImage.setPosition(330.0f, 340.0f);
  officeButtonImage.setTexture(officeButton);

  bookroomButton.loadFromFile("homesmall.PNG");
  bookroomButtonImage.setPosition(435.0f, 55.0f);
  bookroomButtonImage.setTexture(bookroomButton);

  libraryButton.loadFromFile("homesmall.PNG");
  libraryButtonImage.setPosition(330.0f, 225.0f);
  libraryButtonImage.setTexture(libraryButton);

  btqButton.loadFromFile("homesmall.PNG");
  btqButtonImage.setPosition(410.0f, 215.0f);
  btqButtonImage.setTexture(btqButton);

  idButton.loadFromFile("red.png");
  idButtonImage.setPosition(200.0f, 200.0f);
  idButtonImage.setTexture(idButton);

  ifOnHome = true; 
  while (window.isOpen())
  {
    sf::Event Event;
    //homeScreen(Event);
      while (window.pollEvent(Event))
    {
      switch (Event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;
      case sf::Event::MouseMoved:
        {
          sf::Vector2i mousePos = sf::Mouse::getPosition(window);
          sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
          if ( exitButtonImage.getGlobalBounds().contains(mousePosF))
          {
            exitButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            exitButtonImage.setColor(sf::Color(255, 255, 255));
          }
          if( parkinglotButtonImage.getGlobalBounds().contains(mousePosF))
          {
            parkinglotButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            parkinglotButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( nwingButtonImage.getGlobalBounds().contains(mousePosF))
          {
            nwingButtonImage.setColor(sf::Color(250, 20, 20));
            }
          else
          {
            nwingButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( gymButtonImage.getGlobalBounds().contains(mousePosF))
          {
            gymButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            gymButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( officeButtonImage.getGlobalBounds().contains(mousePosF))
          {
            officeButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            officeButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( bookroomButtonImage.getGlobalBounds().contains(mousePosF))
          {
            bookroomButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            bookroomButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( libraryButtonImage.getGlobalBounds().contains(mousePosF))
          {
            libraryButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            libraryButtonImage.setColor(sf::Color(255, 255, 255));
          }
          
          if( btqButtonImage.getGlobalBounds().contains(mousePosF))
          {
            btqButtonImage.setColor(sf::Color(250, 20, 20));
          }
          else
          {
            btqButtonImage.setColor(sf::Color(255, 255, 255));
          }
        }
        break;
      case sf::Event::MouseButtonPressed:
        {
          sf::Vector2i mousePos = sf::Mouse::getPosition(window);
          sf::Vector2f mousePosF( static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
          if (exitButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(home);
            ifOnHome = true; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (parkinglotButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(parkinglot);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (nwingButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(nwing);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (gymButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear(); 
            backgroundImage.setTexture(keypad);
            window.draw(backgroundImage);
            ifOnHome = false; 
            window.display(); 
            gymPuzzle(Event);
          }
          else if (officeButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(office);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (bookroomButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(bookroom);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (libraryButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(library);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
          else if (btqButtonImage.getGlobalBounds().contains(mousePosF))
          {
            window.clear();
            backgroundImage.setTexture(btq);
            ifOnHome = false; 
            window.draw(backgroundImage);
            window.display(); 
          }
        }
        break;
      }
    }
    window.clear();
    window.draw(backgroundImage);
    window.draw(exitButtonImage);
    if(ifOnHome)
    {
      window.draw(parkinglotButtonImage);
      window.draw(nwingButtonImage);
      window.draw(gymButtonImage);
      window.draw(officeButtonImage);
      window.draw(bookroomButtonImage);
      window.draw(libraryButtonImage);
      window.draw(btqButtonImage);
    }
    window.display();
  }
  return 0;
}