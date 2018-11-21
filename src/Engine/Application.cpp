#include <Engine/Application.hpp>

// #define GAME_FULLSCREEN

namespace Engine
{
    Application::Application(const sf::String& title, const unsigned int width, const unsigned int height)
        : m_Components(std::make_shared<Components>()), m_Clock(std::make_unique<sf::Clock>())
    {
#ifdef GAME_FULLSCREEN
        auto desktop                 = sf::VideoMode::getDesktopMode();
        auto windowMode              = sf::VideoMode(desktop.width, desktop.height, desktop.bitsPerPixel);
        m_Components->m_RenderWindow = std::make_unique<sf::RenderWindow>(windowMode, title, sf::Style::Fullscreen);
#else
        sf::VideoMode vm(width, height);
        m_Components->m_RenderWindow = std::make_unique<sf::RenderWindow>(vm, title);
#endif
    }

    void Application::processEvents()
    {
        while (m_Components->m_RenderWindow->pollEvent(*m_Components->m_InputManager->m_Event)) {
            ImGui::SFML::ProcessEvent(*m_Components->m_InputManager->m_Event);

            if (m_Components->m_InputManager->m_Event->type == sf::Event::Closed ||
                m_Components->m_InputManager->isKeyPressed(sf::Keyboard::Escape)) {
                m_Components->m_RenderWindow->close();
                break;
            }

            m_Components->m_SceneManager->getActiveScene()->processInput();
        }
    }

    void Application::update()
    {
        *m_Components->m_DeltaTime = m_Clock->restart();

        ImGui::SFML::Update(*m_Components->m_RenderWindow, *m_Components->m_DeltaTime);

        m_Components->m_SceneManager->getActiveScene()->update();
    }

    void Application::render()
    {
        ImGui::Begin("Hello, GAME!");
        ImGui::Button("github.com/nuriu/sfml-cmake-vscode");
        ImGui::End();

        m_Components->m_RenderWindow->clear();
        m_Components->m_SceneManager->getActiveScene()->render();

        ImGui::SFML::Render(*m_Components->m_RenderWindow);

        m_Components->m_RenderWindow->display();
    }
} // namespace Engine
