#include <pu/ui/ui_Layout.hpp>

namespace pu::ui
{
    Layout::Layout() : Container(0, 0, 960, 544)
    {
        this->onipt = [&](SDL_Event&){};
        this->hasimage = false;
        this->overbgtex = nullptr;
        this->overbgcolor = Color(225, 225, 225, 255);
    }

    Layout::~Layout()
    {
        if(this->overbgtex != nullptr) render::DeleteTexture(this->overbgtex);
    }

    bool Layout::HasChilds()
    {
        return !this->elms.empty();
    }

    void Layout::SetOnInput(std::function<void(SDL_Event&)> Callback)
    {
        this->onipt = Callback;
    }

    std::function<void(SDL_Event&)> Layout::GetOnInput()
    {
        return this->onipt;
    }

    void Layout::AddThread(std::function<void()> Callback)
    {
        this->thds.push_back(Callback);
    }

    std::vector<std::function<void()>> Layout::GetAllThreads()
    {
        return this->thds;
    }

    void Layout::SetBackgroundImage(std::string Path)
    {
        if(this->overbgtex != nullptr) render::DeleteTexture(this->overbgtex);
        this->hasimage = true;
        this->overbgtex = render::LoadImage(Path);
    }

    void Layout::SetBackgroundColor(Color Color)
    {
        if(this->overbgtex != nullptr) render::DeleteTexture(this->overbgtex);
        this->hasimage = false;
        this->overbgcolor = Color;
    }

    void Layout::SimulateTouch(Touch Custom)
    {
        this->simtouch = Custom;
    }

    Touch Layout::GetSimulatedTouch()
    {
        Touch simcpy = this->simtouch;
        this->simtouch = Touch::Empty;
        return simcpy; // Getting simulated touch resets it
    }

    sdl2::Texture Layout::GetBackgroundImageTexture()
    {
        return this->overbgtex;
    }

    Color Layout::GetBackgroundColor()
    {
        return this->overbgcolor;
    }

    bool Layout::HasBackgroundImage()
    {
        return this->hasimage;
    }
}
