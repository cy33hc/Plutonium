
/*

    Plutonium library

    @file ui_Layout.hpp
    @brief Contains pu::Layout class, the object used to render within applications
    @author XorTroll

    @copyright Plutonium project - an easy-to-use UI framework for Nintendo Switch homebrew

*/

#pragma once
#include <pu/ui/ui_Container.hpp>
#include <functional>

namespace pu::ui
{
    class Layout : public Container
    {
        public:
            Layout();
            PU_SMART_CTOR(Layout)
            ~Layout();

            bool HasChilds();
            void SetOnInput(std::function<void(SDL_Event&)> Callback);
            std::function<void(SDL_Event&)> GetOnInput();
            void AddThread(std::function<void()> Callback);
            std::vector<std::function<void()>> GetAllThreads();
            void SetBackgroundImage(std::string Path);
            void SetBackgroundColor(Color Color);
            void SimulateTouch(Touch Custom);
            Touch GetSimulatedTouch();
            sdl2::Texture GetBackgroundImageTexture();
            Color GetBackgroundColor();
            bool HasBackgroundImage();
        private:
            bool hasimage;
            Color overbgcolor;
            Touch simtouch;
            sdl2::Texture overbgtex;
            std::function<void(SDL_Event&)> onipt;
            std::vector<std::function<void()>> thds;
    };
}
